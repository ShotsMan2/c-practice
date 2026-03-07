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

int basamakbul(int num)
{
    if (num > -10 && num < 10)
    {
        return 1;
    }

    return 1 + basamakbul(num / 10);
}

int terscevir(int num)
{
    if (num > -10 && num < 10)
    {
        return num;
    }

    int basamak = basamakbul(num);

    int sonrakam = num % 10;

    int kalannum = num / 10;

    return (sonrakam * usal(10, basamak - 1)) + terscevir(kalannum);
}

int main()
{
    int num;

    printf("Enter a number ");
    scanf("%d", &num);

    int result = terscevir(num);

    printf("%d", result);

    return 0;
}
