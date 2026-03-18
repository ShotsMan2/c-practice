#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main()
{
    char str[50];
    int i;

    FILE *fptr;
    fptr = fopen("string.dat", "w");
    if (fptr == NULL)
    {
        printf("unsc\n");
    }
    else
    {
        for (i = 0; i < 5; i++)
        {
            printf("str gir ");
            fgets(str, sizeof(str), stdin);
            fprintf(fptr, "%s", str);
        }

        printf("scs\n");
        fclose(fptr);
    }

    return 0;
}
