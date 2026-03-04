#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int findSecondMax(int arr[], int size)
{
    if (size == 2)
    {
        if (arr[0] < arr[1])
        {
            int temp = arr[0];
            arr[0] = arr[1];
            arr[1] = temp;
        }
        return arr[1];
    }

    findSecondMax(arr + 1, size - 1);

    int current = arr[0];
    int maxrest = arr[1];
    int maxrest2 = arr[2];

    if (current > maxrest)
    {
        arr[0] = current;
        arr[1] = maxrest;
    }
    else if (current > maxrest2 && current != maxrest)
    {
        arr[0] = maxrest;
        arr[1] = current;
    }
    else
    {
        arr[0] = maxrest;
        arr[1] = maxrest2;
    }

    return arr[1];
}

int main()
{
    int numbers[10] = {12, 45, 7, 88, 23, 56, 91, 34, 67, 5};

    int size = 10;

    int result = findSecondMax(numbers, size);

    printf("%d", result);

    return 0;
}
