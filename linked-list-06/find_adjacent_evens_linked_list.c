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
    int num;

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

    node *temp = head;
    while (temp != NULL && temp->next != NULL)
    {
        if (temp->data % 2 == 0 && temp->next->data % 2 == 0)
        {
            printf("%d-%d ", temp->data, temp->next->data);
            temp = temp->next;
        }

        temp = temp->next;
    }

    return 0;
}
