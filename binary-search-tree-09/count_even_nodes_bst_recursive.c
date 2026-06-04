#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

typedef struct node
{
    int data;
    struct node *right;
    struct node *left;
} node;

int count = 0;

node *ekle(node *root, int num)
{
    if (root == NULL)
    {
        node *n = (node *)malloc(sizeof(node));
        n->data = num;
        n->left = NULL;
        n->right = NULL;

        return n;
    }

    if (num < root->data)
    {
        root->left = ekle(root->left, num);
    }
    else if (num > root->data)
    {
        root->right = ekle(root->right, num);
    }

    return root;
}

void yazdir(node *agac)
{
    if (agac == NULL)
    {
        return;
    }

    yazdir(agac->left);

    printf("%d ", agac->data);

    yazdir(agac->right);
}

void ciftbul(node *agac)
{
    if (agac == NULL)
    {
        return;
    }

    ciftbul(agac->left);

    if (agac->data % 2 == 0)
    {
        count++;
    }

    ciftbul(agac->right);
}

int main()
{
    int num;

    node *root = NULL;

    root = ekle(root, 21);
    root = ekle(root, 40);
    root = ekle(root, 70);
    root = ekle(root, 10);

    yazdir(root);

    ciftbul(root);

    printf("cift adet: %d", count);

    return 0;
}
