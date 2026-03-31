#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

int main()
{
    int i, bulundu = 0, num, sayilar[14] = {10, 15, 20, 33, 22, 11, 9, 8, 48, 47, 12, 25, 12, 21};

    printf("sayi gir ");
    scanf("%d", &num);

    for (i = 0; i < 14; i++)
    {
        if (*(sayilar + i) == num)
        {
            printf("%d.\n", i + 1);
            bulundu = 1;
        }
    }

    if (bulundu == 0)
    {
        printf("bu sayi dizide yok\n");
    }

    return 0;
}
