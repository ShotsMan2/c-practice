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

void guncelle(node *agac, int num)
{
    if (agac == NULL)
    {
        return;
    }

    guncelle(agac->left, num);

    agac->data = agac->data + num;

    guncelle(agac->right, num);
}

int main()
{
    int num;

    node *root = NULL;

    root = ekle(root, 20);
    root = ekle(root, 40);
    root = ekle(root, 70);
    root = ekle(root, 10);

    yazdir(root);

    printf("sayi gir ");
    scanf("%d", &num);

    guncelle(root, num);

    yazdir(root);

    return 0;
}
