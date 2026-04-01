#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

int main()
{
    int num, i, dif = 0, count, uygun = 1, sayilar[] = {1, 6, 5, 2, 1, 4, 2};
    int size = sizeof(sayilar) / sizeof(sayilar[0]);

    while (uygun == 1)
    {
        printf("sayi gir ");
        scanf("%d", &num);

        count = 0;

        for (i = 0; i < size; i++)
        {
            if (num == *(sayilar + i))
            {
                *(sayilar + i) = -1;
                count++;
            }
        }

        if (count >= 1)
        {
            dif++;
        }

        uygun = 0;

        for (i = 0; i < size; i++)
        {
            if (*(sayilar + i) != -1)
            {
                uygun = 1;
            }
        }
    }

    printf("%d\n", dif);

    return 0;
}
