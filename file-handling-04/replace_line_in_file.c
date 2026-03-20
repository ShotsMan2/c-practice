#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main()
{
    int sira, i = 0, j;
    char arr[10][50], name[50];

    FILE *fptr;
    fptr = fopen("string.dat", "r");
    if (fptr == NULL)
    {
        printf("unsc\n");
    }
    else
    {
        while (fgets(arr[i], sizeof(arr[i]), fptr) != NULL)
        {
            i++;
        }

        printf("sira girin ");
        scanf("%d", &sira);

        getchar();

        printf("kayıt gir ");
        gets(name);

        printf("scs\n");
        fclose(fptr);
    }
    fptr = fopen("string.dat", "w");
    if (fptr == NULL)
    {
        printf("unsc\n");
    }
    else
    {
        for (j = 0; j <= i; j++)
        {
            if (sira - 1 == j)
            {
                fprintf(fptr, "%s\n", name);
                continue;
            }
            fprintf(fptr, "%s", arr[j]);
        }

        printf("scs\n");
        fclose(fptr);
    }

    return 0;
}
