#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void ikili(int sayi)
{
    int dizi[32];
    int i = 0, j;

    if (sayi == 0)
    {
        printf("0");
        return;
    }

    while (sayi > 0)
    {
        dizi[i] = sayi & 1;

        sayi = sayi >> 1;

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
    int sayi;

    printf("sayiyi gir ");
    scanf("%d", &sayi);

    ikili(sayi);
}
