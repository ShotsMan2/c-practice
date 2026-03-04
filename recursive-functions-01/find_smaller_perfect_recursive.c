#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int sumOfDivisors(int num, int divisor)
{
    if (divisor == 0)
    {
        return 0;
    }

    if (num % divisor == 0)
    {
        return divisor + sumOfDivisors(num, divisor - 1);
    }
    else
    {
        return sumOfDivisors(num, divisor - 1);
    }
}
int findPerfect(int num)
{
    if (num < 6)
    {
        return -1;
    }
    
    int sum = sumOfDivisors(num, num - 1);

    if (sum == num)
    {
        return sum;
    }

    return findPerfect(num - 1);
}

int main()
{
    int num;

    printf("Enter a number ");
    scanf("%d", &num);

    int result = findPerfect(num - 1);

    if (result == -1)
    {
        printf("muk num yok");
    }
    else
    {
        printf("muk num: %d", result);
    }

    return 0;
}
