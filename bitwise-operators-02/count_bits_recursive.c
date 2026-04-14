#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void count01(int num, int birler, int sifirlar)
{
    if (num == 0)
    {
        printf("1= %d   0= %d", birler, sifirlar);
        return;
    }

    int bit = num & 1;

    if (bit == 1)
    {
        count01(num >> 1, birler + 1, sifirlar);
    }
    else
    {
        count01(num >> 1, birler, sifirlar + 1);
    }
}

int main()
{
    int num;

    printf("Enter a number ");
    scanf("%d", &num);

    if (num == 0)
    {
        printf("1= 0   0= 1\n");
    }
    else
    {
        count01(num, 0, 0);
    }
}
