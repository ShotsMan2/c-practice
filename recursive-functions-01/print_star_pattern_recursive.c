#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int sekil(int satir, int kalanyildiz)
{
    if (satir > 5)
    {
        return 0;
    }

    if (kalanyildiz > 0)
    {
        printf("*");

        sekil(satir, kalanyildiz - 1);
    }

    else
    {
        printf("\n");

        sekil(satir + 1, (2 * (satir + 1)) - 1);
    }
}

int main()
{

    sekil(1, 1);
}
