#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int sayi, bit;
    long ikilikarsilik = 0;
    long carpan = 1;

    printf("sayiyi gir ");
    scanf("%d", &sayi);

    if (sayi == 0)
    {
        printf("0\n");
    }
    else
    {
        while (sayi > 0)
        {
            bit = sayi & 1;

            ikilikarsilik = ikilikarsilik + (carpan * bit);

            carpan = carpan * 10;

            sayi = sayi >> 1;
        }

        printf("%ld\n", ikilikarsilik);
    }
}
