#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

int main()
{
    int num, arr[100], i = 0, sum = 0, j;

    for (;;)
    {
        printf("enter a number ");
        scanf("%d", &num);

        if (num == -1)
        {
            break;
        }

        if (num > 0)
        {
            *(arr + i) = num;
            i++;
        }
    }

    for (j = 0; j < i; j++)
    {
        sum += *(arr + j);
    }

    printf("%d\n", sum / i);

    return 0;
}
