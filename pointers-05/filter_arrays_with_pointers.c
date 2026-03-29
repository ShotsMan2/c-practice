#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

int main()
{
    int n, i, pozsayac = 0, negsayac = 0;

    printf("n i girin ");
    scanf("%d", &n);

    int arr[n], poz[n], neg[n];

    for (i = 0; i < n; i++)
    {
        printf("sayi gir");
        scanf("%d", (arr + i));
    }

    for (i = 0; i < n; i++)
    {
        if (*(arr + i) > 0)
        {
            *(poz + pozsayac) = *(arr + i);
            pozsayac++;
        }
        else if (*(arr + i) < 0)
        {
            *(neg + negsayac) = *(arr + i);
            negsayac++;
        }
    }

    for (i = 0; i < pozsayac; i++)
    {
        printf("%d\t", *(poz + i));
    }
    printf("\n");
    for (i = 0; i < negsayac; i++)
    {
        printf("%d\t", *(neg + i));
    }

    return 0;
}
