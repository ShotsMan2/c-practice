#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void cevir(int num)
{
    int sagtaraf = (num & 15) << 4;

    int soltaraf = (num >> 4) & 15;

    int result = sagtaraf | soltaraf;

    printf("%d %d", num, result);
}

int main()
{
    int num;

    printf("Enter a number ");
    scanf("%d", &num);

    cevir(num);

    return 0;
}
