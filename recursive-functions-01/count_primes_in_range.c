#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int asalmi(int num1, int bolen)
{

    if (num1 < 2)
    {
        return 0;
    }

    if (bolen == 1)
    {
        return 1;
    }

    if (num1 % bolen == 0)
    {
        return 0;
    }

    return asalmi(num1, bolen - 1);
}
int asalsay(int num1, int num2)
{
    if (num1 == num2)
    {
        return 0;
    }

    int asal = asalmi(num1, num1 / 2);

    if (asal == 1)
    {
        return 1 + asalsay(num1 + 1, num2);
    }
    else
    {
        return asalsay(num1 + 1, num2);
    }
}

int main()
{
    int num1, num2, temp;

    printf("Enter a num1 ");
    scanf("%d", &num1);

    printf("Enter a num2 ");
    scanf("%d", &num2);

    if (num1 > num2)
    {
        temp = num1;
        num1 = num2;
        num2 = temp;
    }

    int result = asalsay(num1 + 1, num2);

    printf("\n%d", result);

    return 0;
}
