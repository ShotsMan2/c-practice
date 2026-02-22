#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int basamakbul(int sayi)
{
    if (sayi > -10 && sayi < 10)
    {
        return 1;
    }

    return 1 + basamakbul(sayi / 10);
}

int main()
{
    int sayi;

    printf("sayi gir ");
    scanf("%d", &sayi);

    int result = basamakbul(sayi);

    printf("%d", result);

    return 0;
}
