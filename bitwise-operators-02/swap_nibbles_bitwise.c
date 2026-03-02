#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void cevir(int sayi)
{
    int sagtaraf = (sayi & 15) << 4;

    int soltaraf = (sayi >> 4) & 15;

    int sonuc = sagtaraf | soltaraf;

    printf("%d %d", sayi, sonuc);
}

int main()
{
    int sayi;

    printf("sayi gir ");
    scanf("%d", &sayi);

    cevir(sayi);

    return 0;
}
