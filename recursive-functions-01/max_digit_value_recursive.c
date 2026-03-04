#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int power(int base, int exponent)
{
    if (exponent == 0)
    {
        return 1;
    }

    return base * power(10, exponent - 1);
}

int countDigits(int num)
{
    if (num > -10 && num < 10)
    {
        return 1;
    }

    return 1 + countDigits(num / 10);
}

int cevir(int num)
{
    if (num > -10 && num < 10)
    {
        return 9;
    }

    int digit = countDigits(num);

    return power(10, digit - 1) * 9 + cevir(num / 10);
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
