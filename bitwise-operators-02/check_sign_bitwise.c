#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void sign(int num)
{
    int i;

    for (i = 31; i >= 0; i--)
    {
        int bit = (num >> i) & 1;
        printf("%d", bit);
    }
    printf("\n");

    int signbiti = (num >> 31) & 1;

    if (signbiti == 1)
    {
        printf("negaitve");
    }
    else
    {
        printf("positive");
    }
}

int main()
{
    int num;

    printf("num girin ");
    scanf("%d", &num);

    sign(num);
}
