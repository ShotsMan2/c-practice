#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int bolentoplami(int num, int bolen)
{
    if (bolen == 0)
    {
        return 0;
    }

    if (num % bolen == 0)
    {
        return bolen + bolentoplami(num, bolen - 1);
    }
    else
    {
        return bolentoplami(num, bolen - 1);
    }
}
int mukemmelbul(int num)
{
    if (num < 6)
    {
        return -1;
    }
    
    int toplam = bolentoplami(num, num - 1);

    if (toplam == num)
    {
        return toplam;
    }

    return mukemmelbul(num - 1);
}

int main()
{
    int num;

    printf("Enter a number ");
    scanf("%d", &num);

    int result = mukemmelbul(num - 1);

    if (result == -1)
    {
        printf("muk num yok");
    }
    else
    {
        printf("muk num: %d", result);
    }

    return 0;
}
