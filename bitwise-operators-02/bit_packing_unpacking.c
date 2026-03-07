#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void cevir(int num1, int num2)
{
    int data;

    data = num2 | num1 << 8;

    printf("%d\n", data);

    int cozulennum2 = data & 0xFF;

    int cozulennum1 = (data >> 8) & 0xFF;

    printf("num1= %d\n", cozulennum1);
    printf("num2= %d\n", cozulennum2);
}

int main()
{
    int num1 = 5, num2 = 7;

    cevir(num1, num2);

    return 0;
}
