#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

int main()
{
    int num, sayi, fark, minfark, count = 1;

    node *head = NULL;
    node *tail = NULL;

    for (;;)
    {
        printf("Enter a data ");
        scanf("%d", &num);

        if (num == -1)
        {
            break;
        }

        node *n = (node *)malloc(sizeof(node));
        n->data = num;
        n->next = NULL;

        if (head == NULL)
        {
            head = n;
            tail = n;
        }
        else
        {
            tail->next = n;
            tail = n;
        }
    }

    printf("Enter a num ");
    scanf("%d", &sayi);

    node *temp = head;

    minfark = sayi - head->data;
    if (minfark < 0)
    {
        minfark = -minfark;
    }

    int close = head->data;
    int sira = count;

    while (temp != NULL)
    {
        fark = sayi - temp->data;
        if (fark < 0)
        {
            fark = -fark;
        }

        if (fark < minfark)
        {
            close = temp->data;
            sira = count;
            minfark = fark;
        }

        count++;
        temp = temp->next;
    }

    printf("%d sayisi %d sayisina yakindir ve %d. siradadir.", sayi, close, sira);

    return 0;
}
