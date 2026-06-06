#include <stdio.h>
#include <stdlib.h>

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
        printf("sayi gir ");
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

    if (head == NULL)
    {
        printf("liste bos.\n");
        return 0;
    }

    tail->next = head;

    node *temp = head;

    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("\n");

    temp = head;
    while (head != tail)
    {

        temp->next->data = temp->data + temp->next->data;

        node *silinecek = temp;
        tail->next = temp->next;
        head = temp->next;

        node *yazdir = head;
        do
        {
            printf("%d ", yazdir->data);
            yazdir = yazdir->next;
        } while (yazdir != head);
        printf("\n");

        temp = temp->next;
        free(silinecek);
    }

    return 0;
}
