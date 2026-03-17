#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main()
{
    char arr[50];
    int i = 0, j;

    FILE *fptr;
    fptr = fopen("dosya.txt", "r");
    if (fptr == NULL)
    {
        printf("unsc\n");
    }
    else
    {
        while ((arr[i] = getc(fptr)) != EOF)
        {
            i++;
        }

        for (j = i - 2; j >= 0; j = j - 2)
        {
            printf("%c", arr[j]);
        }

        printf("\n  scs\n");
        fclose(fptr);
    }

    return 0;
}
