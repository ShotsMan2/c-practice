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

        count++;
        return n;
    }

    if (num > root->data)
    {
        root->right = ekle(root->right, num);
    }
    else
    {
        root->left = ekle(root->left, num);
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

int agactopla(node *agac)
{
    if (agac == NULL)
    {
        return 0;
    }

    return agac->data + agactopla(agac->left) + agactopla(agac->right);
}

void ortbuyukyazdir(node *agac, int ort)
{
    if (agac == NULL)
    {
        return;
    }

    ortbuyukyazdir(agac->left, ort);

    if (ort < agac->data)
    {
        printf("%d ", agac->data);
    }

    ortbuyukyazdir(agac->right, ort);
}

int main()
{
    node *root = NULL;
    root = ekle(root, 20);
    root = ekle(root, 40);
    root = ekle(root, 70);
    root = ekle(root, 10);

    yazdir(root);

    float ort = (float)agactopla(root) / count;

    printf("ort: %.2f\n", ort);

    ortbuyukyazdir(root, ort);

    return 0;
}
