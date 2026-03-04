#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int countdigits(int num)
{
    if (num > -10 && num < 10)
    {
        return 1;
    }

    return 1 + countdigits(num / 10);
}

int main()
{
    int num;

    printf("Enter a number ");
    scanf("%d", &num);

    int result = countdigits(num);

    printf("%d", result);

    return 0;
}
