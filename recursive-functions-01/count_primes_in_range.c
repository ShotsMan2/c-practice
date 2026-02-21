#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int asalmi(int s1, int bolen)
{

    if (s1 < 2)
    {
        return 0;
    }

    if (bolen == 1)
    {
        return 1;
    }

    if (s1 % bolen == 0)
    {
        return 0;
    }

    return asalmi(s1, bolen - 1);
}
int asalsay(int s1, int s2)
{
    if (s1 == s2)
    {
        return 0;
    }

    int asal = asalmi(s1, s1 / 2);

    if (asal == 1)
    {
        return 1 + asalsay(s1 + 1, s2);
    }
    else
    {
        return asalsay(s1 + 1, s2);
    }
}

int main()
{
    int s1, s2, temp;

    printf("say1 gir ");
    scanf("%d", &s1);

    printf("say2 gir ");
    scanf("%d", &s2);

    if (s1 > s2)
    {
        temp = s1;
        s1 = s2;
        s2 = temp;
    }

    int result = asalsay(s1 + 1, s2);

    printf("\n%d", result);

    return 0;
}
