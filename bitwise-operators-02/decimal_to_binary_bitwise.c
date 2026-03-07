#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void ikili(int num)
{
    int dizi[32];
    int i = 0, j;

    if (num == 0)
    {
        printf("0");
        return;
    }

    while (num > 0)
    {
        dizi[i] = num & 1;

        num = num >> 1;

        i++;
    }

    for (j = i - 1; j >= 0; j--)
    {
        printf("%d", dizi[j]);
    }
    printf("\n");
}

int main()
{
    int num;

    printf("numyi gir ");
    scanf("%d", &num);

    ikili(num);
}
