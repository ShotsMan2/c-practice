#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void cevir(int sayi)
{
    int sum = 0;

    while (sayi > 0)
    {
        int bit1 = sayi & 1;
        int bit2 = (sayi >> 1) & 1;

        if (bit1 != bit2)
        {
            sum++;
        }

        sayi = sayi >> 2;
    }

    printf("%d", sum);
}

int main()
{
    int sayi;

    printf("sayi gir ");
    scanf("%d", &sayi);

    cevir(sayi);

    return 0;
}
