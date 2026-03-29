#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int *squareroot(int *ptr)
{
    *ptr = sqrt(*ptr);
    return ptr;
}

int main()
{
    int num;
    int *ptr;

    printf("enter a number ");
    scanf("%d", &num);

    ptr = squareroot(&num);

    printf("%d", *ptr);

    return 0;
}
