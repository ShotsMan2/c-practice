#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void cevir(int num)
{
    int sum = 0;

    while (num > 0)
    {
        int bit1 = num & 1;
        int bit2 = (num >> 1) & 1;

        if (bit1 != bit2)
        {
            sum++;
        }

        num = num >> 2;
    }

    printf("%d", sum);
}

int main()
{
    int num;

    printf("num gir ");
    scanf("%d", &num);

    cevir(num);

    return 0;
}
