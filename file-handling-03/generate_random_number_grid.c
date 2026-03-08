#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int i, j, num;

    srand(time(NULL));

    FILE *fptr;
    fptr = fopen("randomnumber.txt", "w");
    if (fptr == NULL)
    {
        printf("unsc");
    }
    else
    {
        for (j = 0; j < 10; j++)
        {
            for (i = 0; i < 5; i++)
            {
                num = (rand() % 10) + 1;
                fprintf(fptr, "%d ", num);
            }
            fprintf(fptr, "\n");
        }

        printf("scs");
        fclose(fptr);
    }

    return 0;
}
