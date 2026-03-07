#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void isaret(int num)
{
    int arr[32] = {0};
    int i = 0, j;

    if (num == 0)
    {
        printf("00000000000000000000000000000000");
        return;
    }

    while (num > 0)
    {
        arr[i] = num & 1;

        num = num >> 1;

        i++;
    }

    for (j = 31; j >= 0; j--)
    {
        printf("%d", arr[j]);
    }
    printf("\n");
}

int main()
{
    int num;

    printf("num girin ");
    scanf("%d", &num);

    isaret(num);
}
