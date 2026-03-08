#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int a, b, c, i;
    FILE *fptr;

    fptr = fopen("ikiliDosya.dat", "w");
    if (fptr == NULL)
    {
        printf("unsc\n");
    }

    else
    {
        for (i = 1; i < 9; i++)
        {
            fprintf(fptr, "%d\t%d\t%d\n", i, i + 1, i + 2);
        }

        printf("scs\n");

        fclose(fptr);
    }

    fptr = fopen("ikiliDosya.dat", "r");
    if (fptr == NULL)
    {
        printf("unsc\n");
    }
    else
    {
        while (fscanf(fptr, "%d %d %d", &a, &b, &c) != EOF)
        {
            printf("%d\t%d\t%d\n", a, b, c);
        }

        fclose(fptr);

        printf("scs\n");
    }

    return 0;
}
