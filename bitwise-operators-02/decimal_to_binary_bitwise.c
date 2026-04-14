#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void ikili(int num)
{
    int arr[32];
    int i = 0, j;

    if (num == 0)
    {
        printf("0");
        return;
    }

    while (num > 0)
    {
        arr[i] = num & 1;

        num = num >> 1;

        i++;
    }

    for (j = i - 1; j >= 0; j--)
    {
        printf("%d", arr[j]);
    }
    printf("\n");
}

int main()
{
    int num;

    printf("Enter a number ");
    scanf("%d", &num);

    ikili(num);
}
