#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int usal(int taban, int us)
{
    if (us == 0)
    {
        return 1;
    }

    return taban * usal(taban, us - 1);
}

int basamakbul(int sayi)
{
    if (sayi > -10 && sayi < 10)
    {
        return 1;
    }

    return 1 + basamakbul(sayi / 10);
}

int terscevir(int sayi)
{
    if (sayi > -10 && sayi < 10)
    {
        return sayi;
    }

    int basamak = basamakbul(sayi);

    int sonrakam = sayi % 10;

    int kalansayi = sayi / 10;

    return (sonrakam * usal(10, basamak - 1)) + terscevir(kalansayi);
}

int main()
{
    int sayi;

    printf("sayi gir ");
    scanf("%d", &sayi);

    int result = terscevir(sayi);

    printf("%d", result);

    return 0;
}
