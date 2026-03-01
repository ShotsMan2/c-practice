#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void cevir(int sayi, int i, int dizi[])
{
    int j;

    if (sayi == 0)
    {
        for (j = i - 1; j >= 0; j--)
        {
            printf("%d", dizi[j]);
        }
        printf("\n");
        return;
    }

    dizi[i] = sayi & 1;

    if (dizi[i] == 0)
    {
        dizi[i] = 1;
    }
    else
    {
        dizi[i] = 0;
    }

    cevir(sayi >> 1, i + 1, dizi);
}

int main()
{
    int sayi, arr[32];

    printf("sayi gir ");
    scanf("%d", &sayi);

    if (sayi == 0)
    {
        printf("1\n");
    }
    else
    {
        cevir(sayi, 0, arr);
    }

    return 0;
}
