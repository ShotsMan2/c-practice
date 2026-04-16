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
    int num, eleman, count = 1;

    node *head = NULL;
    node *tail = NULL;

    for (;;)
    {
        printf("veri gir ");
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

    printf("eleman gir ");
    scanf("%d", &eleman);

    node *temp = head;

    while (temp != NULL)
    {
        if (count == eleman)
        {
            printf("%d\n", temp->data);
            break;
        }

        temp = temp->next;

        count++;
    }

    return 0;
}
