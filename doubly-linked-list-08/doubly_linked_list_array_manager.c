#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
} node;

node *lists[100] = {NULL};
int n;

void listele()
{
    int i;

    for (i = 0; i < n; i++)
    {
        node *temp = lists[i];
        printf("Liste%d: ", i + 1);
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

void Kaydir(int index1, int index2)
{
    int gercekidx1 = index1 - 1;
    int gercekidx2 = index2 - 1;

    if (gercekidx1 < 0 || gercekidx1 >= n || gercekidx2 < 0 || gercekidx2 >= n)
    {
        printf("gecersiz indexler girdiniz\n");
        return;
    }
    if (gercekidx1 == gercekidx2)
    {
        printf("ayni listeyi kendine ekleyemezsin\n");
        return;
    }

    if (lists[gercekidx2] == NULL)
    {
        listele();
        return;
    }
    if (lists[gercekidx1] == NULL)
    {
        lists[gercekidx1] = lists[gercekidx2];
    }
    else
    {
        node *temp = lists[gercekidx1];
        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = lists[gercekidx2];
        lists[gercekidx2]->prev = temp;
    }

    lists[gercekidx2] = NULL;

    listele();
}

void Birlestir()
{
    node *yenihead = NULL;
    node *yenitail = NULL;

    int i;

    for (i = 0; i < n; i++)
    {
        node *temp = lists[i];
        while (temp != NULL)
        {
            node *yenidugum = (node *)malloc(sizeof(node));
            yenidugum->data = temp->data;
            yenidugum->next = NULL;
            yenidugum->prev = NULL;

            if (yenihead == NULL)
            {
                yenihead = yenidugum;
                yenitail = yenidugum;
            }
            else
            {
                yenitail->next = yenidugum;
                yenidugum->prev = yenitail;
                yenitail = yenidugum;
            }

            temp = temp->next;
        }
    }
    printf("\n");

    printf("ListeN: ");

    if (yenihead == NULL)
    {
        printf("{}\n");
    }
    else
    {
        printf("{");
        node *yazdir = yenihead;
        while (yazdir != NULL)
        {
            printf("%d", yazdir->data);
            if (yazdir->next != NULL)
            {
                printf(", ");
            }
            yazdir = yazdir->next;
        }
        printf("}\n");
    }

    printf("\n");
}

void Sil()
{
    int i;

    for (i = 0; i < n; i++)
    {
        if (lists[i] == NULL)
        {
            continue;
        }
        int max = -1;
        node *maxnode = NULL;
        node *temp = lists[i];

        while (temp != NULL)
        {
            if (temp->data > max)
            {
                max = temp->data;
                maxnode = temp;
            }
            temp = temp->next;
        }

        if (maxnode != NULL)
        {
            if (maxnode->prev == NULL)
            {
                lists[i] = maxnode->next;
                if (lists[i] != NULL)
                {
                    lists[i]->prev = NULL;
                }
            }

            else
            {
                maxnode->prev->next = maxnode->next;
                if (maxnode->next != NULL)
                {
                    maxnode->next->prev = maxnode->prev;
                }
            }

            free(maxnode);
        }
    }

    listele();
}

int main()
{
    int k, x, i, j, num, idx1, idx2;

    srand(time(NULL));

    for (;;)
    {

        printf("N i 2 den buyuk olacak sekilde gir ");
        scanf("%d", &n);

        if (n > 2)
        {
            break;
        }
    }
    for (;;)
    {

        printf("K yi 3 den buyuk olacak sekilde gir ");
        scanf("%d", &k);

        if (k > 3)
        {
            break;
        }
    }
    for (;;)
    {

        printf("x i 9 dan buyuk olacak sekilde gir ");
        scanf("%d", &x);

        if (x > 9)
        {
            break;
        }
    }

    node *tail[100] = {NULL};

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < k; j++)
        {
            node *yeninode = (node *)malloc(sizeof(node));

            num = (rand() % x) + (i * x) + 1;
            yeninode->data = num;
            yeninode->next = NULL;
            yeninode->prev = NULL;

            if (lists[i] == NULL)
            {
                lists[i] = yeninode;
                tail[i] = yeninode;
            }
            else
            {
                tail[i]->next = yeninode;
                yeninode->prev = tail[i];
                tail[i] = yeninode;
            }
        }
    }

    listele();

    printf("index1 i gir ");
    scanf("%d", &idx1);
    printf("index2 yi gir ");
    scanf("%d", &idx2);

    Kaydir(idx1, idx2);

    Birlestir();

    Sil();

    return 0;
}
