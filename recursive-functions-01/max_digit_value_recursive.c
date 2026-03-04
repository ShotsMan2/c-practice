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

int basamakbul(int num)
{
    if (num > -10 && num < 10)
    {
        return 1;
    }

    return 1 + basamakbul(num / 10);
}

int cevir(int num)
{
    if (num > -10 && num < 10)
    {
        return 9;
    }

    int basamak = basamakbul(num);

    return usal(10, basamak - 1) * 9 + cevir(num / 10);
}

int main()
{
    int num;

    printf("Enter a number ");
    scanf("%d", &num);

    int result = cevir(num);

    printf("%d", result);

    return 0;
}
