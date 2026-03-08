#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr[20] = {2, 53, 34, 23, 76, 34, 76, 34, 65, 72, 97, 33, 73, 76, 45, 87, 44, 34, 64, 23};
    FILE *ikili;
    ikili = fopen("ikiliDosya.dat", "wb");

    fwrite(arr, sizeof(int), 20, ikili);

    fclose(ikili);

    return 0;
}
