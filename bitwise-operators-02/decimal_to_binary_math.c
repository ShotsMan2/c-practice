#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int num, bit;
    long ikilikarsilik = 0;
    long carpan = 1;

    printf("Enter a number ");
    scanf("%d", &num);

    if (num == 0)
    {
        printf("0\n");
    }
    else
    {
        while (num > 0)
        {
            bit = num & 1;

            ikilikarsilik = ikilikarsilik + (carpan * bit);

            carpan = carpan * 10;

            num = num >> 1;
        }

        printf("%ld\n", ikilikarsilik);
    }
}
