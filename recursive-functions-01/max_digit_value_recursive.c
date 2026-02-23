#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int usal(int taban, int us)
{
    if (us == 0)
    {
        return 1;
    }

    return taban * usal(10, us - 1);
}

int basamakbul(int sayi)
{
    if (sayi > -10 && sayi < 10)
    {
        return 1;
    }

    return 1 + basamakbul(sayi / 10);
}

int cevir(int sayi)
{
    if (sayi > -10 && sayi < 10)
    {
        return 9;
    }

    int basamak = basamakbul(sayi);

    return usal(10, basamak - 1) * 9 + cevir(sayi / 10);
}

int main()
{
    int sayi;

    printf("sayi gir ");
    scanf("%d", &sayi);

    int result = cevir(sayi);

    printf("%d", result);

    return 0;
}
