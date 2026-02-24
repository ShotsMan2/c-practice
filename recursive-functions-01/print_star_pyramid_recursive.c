#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int sekil(int satir, int kalanyildiz, int bosluk)
{
    if (satir > 5)
    {
        return 0;
    }

    if (kalanyildiz > 0)
    {
        if (bosluk < 5)
        {
            printf(" ");
            return sekil(satir, kalanyildiz, bosluk + 1);
        }
        else
        {
            printf("*");
            return sekil(satir, kalanyildiz - 1, bosluk);
        }
    }
    else
    {
        printf("\n");

        return sekil(satir + 1, (2 * (satir + 1)) - 1, satir + 1);
    }
}

int main()
{
    sekil(1, 1, 1);
}
