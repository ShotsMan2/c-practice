#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void cevir(int num, int i, int arr[])
{
    int j;

    if (num == 0)
    {
        for (j = i - 1; j >= 0; j--)
        {
            printf("%d", arr[j]);
        }
        printf("\n");
        return;
    }

    arr[i] = num & 1;

    if (arr[i] == 0)
    {
        arr[i] = 1;
    }
    else
    {
        arr[i] = 0;
    }

    cevir(num >> 1, i + 1, arr);
}

int main()
{
    int num, arr[32];

    printf("enter a number ");
    scanf("%d", &num);

    if (num == 0)
    {
        printf("1\n");
    }
    else
    {
        cevir(num, 0, arr);
    }

    return 0;
}
