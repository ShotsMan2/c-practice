#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void adet01(int sayi, int birler, int sifirlar)
{
    if (sayi == 0)
    {
        printf("1= %d   0= %d", birler, sifirlar);
        return;
    }

    int bit = sayi & 1;

    if (bit == 1)
    {
        adet01(sayi >> 1, birler + 1, sifirlar);
    }
    else
    {
        adet01(sayi >> 1, birler, sifirlar + 1);
    }
}

int main()
{
    int sayi;

    printf("sayi gir ");
    scanf("%d", &sayi);

    if (sayi == 0)
    {
        printf("1= 0   0= 1\n");
    }
    else
    {
        adet01(sayi, 0, 0);
    }
}
