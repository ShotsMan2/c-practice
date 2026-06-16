#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *head = NULL;

void siraliekle(int num)
{
    node *n = (node *)malloc(sizeof(node));
    n->data = num;
    n->next = NULL;

    if (head == NULL)
    {
        head = n;
        return;
    }

    if (head->data <= num)
    {
        n->next = head;
        head = n;
        return;
    };

    node *temp = head;
    while (temp->next != NULL && temp->next->data > num)
    {
        temp = temp->next;
    }

    n->next = temp->next;
    temp->next = n;
}

void listele()
{
    node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void elemantasi(int yeni, int mevcut)
{
    if (head == NULL || yeni == mevcut || yeni < 1 || mevcut < 1)
    {
        return;
    }

    int i;

    node *currmevcut = head;
    node *prevmevcut = NULL;
    for (i = 1; i < mevcut && currmevcut != NULL; i++)
    {
        prevmevcut = currmevcut;
        currmevcut = currmevcut->next;
    }

    if (currmevcut == NULL)
    {
        printf("indexi fazla girme.\n");
        return;
    }

    if (prevmevcut == NULL)
    {
        head = currmevcut->next;
    }
    else
    {
        prevmevcut->next = currmevcut->next;
    }

    if (yeni == 1)
    {
        currmevcut->next = head;
        head = currmevcut;
    }
    else
    {
        node *temp = head;
        for (i = 1; i < yeni - 1 && temp != NULL; i++)
        {
            if (temp->next == NULL)
            {
                break;
            }
            temp = temp->next;
        }
        currmevcut->next = temp->next;
        temp->next = currmevcut;
    }
}

int main()
{
    int num, mevcut, yeni;

    for (;;)
    {
        printf("sayi gir ");
        scanf("%d", &num);

        if (num == -1)
        {
            break;
        }

        siraliekle(num);

        listele();
    }

    printf("mevcut index gir ");
    scanf("%d", &mevcut);

    printf("yeni index gir ");
    scanf("%d", &yeni);

    elemantasi(yeni, mevcut);

    listele();

    return 0;
}
