#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int basamakbul(int num)
{
    if (num > -10 && num < 10)
    {
        return 1;
    }

    return 1 + basamakbul(num / 10);
}

int main()
{
    int num;

    printf("Enter a number ");
    scanf("%d", &num);

    int result = basamakbul(num);

    printf("%d", result);

    return 0;
}
