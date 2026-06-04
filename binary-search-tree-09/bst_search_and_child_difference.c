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

node *cocukfark(node *agac, int num)
{
    if (agac == NULL)
    {
        return NULL;
    }

    if (agac->data == num)
    {
        return agac;
    }
    else if (agac->data > num)
    {
        return cocukfark(agac->left, num);
    }
    else
    {
        return cocukfark(agac->right, num);
    }
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

    printf("sayi gir ");
    scanf("%d", &num);

    node *hedef = cocukfark(root, num);

    if (hedef == NULL)
    {
        printf("girdiginiz deger yok.\n");
    }
    else
    {
        int soldeger = 0;
        int sagdeger = 0;

        if (hedef->left != NULL)
        {
            soldeger = hedef->left->data;
            printf("sol: %d\n", soldeger);
        }
        else
        {
            printf("sol yok\n");
        }
        if (hedef->right != NULL)
        {
            sagdeger = hedef->right->data;
            printf("sag: %d\n", sagdeger);
        }
        else
        {
            printf("sag yok\n");
        }

        printf("fark: %d", abs(sagdeger - soldeger));
    }

    return 0;
}
