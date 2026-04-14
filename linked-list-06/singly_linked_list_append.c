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
    node *head = NULL;
    node *tail = NULL;
    int num;

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

    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}
