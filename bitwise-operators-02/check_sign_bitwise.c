#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void isaret(int sayi)
{
    int i;

    for (i = 31; i >= 0; i--)
    {
        int bit = (sayi >> i) & 1;
        printf("%d", bit);
    }
    printf("\n");

    int isaretbiti = (sayi >> 31) & 1;

    if (isaretbiti == 1)
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
    int sayi;

    printf("sayi girin ");
    scanf("%d", &sayi);

    isaret(sayi);
}
