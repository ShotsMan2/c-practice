#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void isaret(int sayi)
{
    int dizi[32] = {0};
    int i = 0, j;

    if (sayi == 0)
    {
        printf("00000000000000000000000000000000");
        return;
    }

    while (sayi > 0)
    {
        dizi[i] = sayi & 1;

        sayi = sayi >> 1;

        i++;
    }

    for (j = 31; j >= 0; j--)
    {
        printf("%d", dizi[j]);
    }
    printf("\n");
}

int main()
{
    int sayi;

    printf("sayi girin ");
    scanf("%d", &sayi);

    isaret(sayi);
}
