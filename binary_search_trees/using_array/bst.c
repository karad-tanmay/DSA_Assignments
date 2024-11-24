#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "bst.h"

void init(bst *t, int size)
{
    if (size <= 0)
        return;
    t->size = size;
    t->a = (int *)malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++)
        t->a[i] = INT_MIN;
    return;
}

void insert(bst *t, int data, int i)
{
    if (t->a[i] == INT_MIN)
    {
        t->a[i] = data;
        return;
    }
    if (i < t->size)
    {
        if (data < t->a[i])
            insert(t, data, (2 * i) + 1);
        else if (data > t->a[i])
            insert(t, data, (2 * i) + 2);
    }
    return;
}

void inorder_traversal(bst t, int i)
{
    if (t.a[i] == INT_MIN || i >= t.size)
        return;
    inorder_traversal(t, (2 * i) + 1);
    printf("%d ", t.a[i]);
    inorder_traversal(t, (2 * i) + 2);
    return;
}

void preorder_traversal(bst t, int i)
{
    if (t.a[i] == INT_MIN || i >= t.size)
        return;
    printf("%d ", t.a[i]);
    inorder_traversal(t, (2 * i) + 1);
    inorder_traversal(t, (2 * i) + 2);
    return;
}

void postorder_traversal(bst t, int i)
{
    if (t.a[i] == INT_MIN || i >= t.size)
        return;
    inorder_traversal(t, (2 * i) + 1);
    inorder_traversal(t, (2 * i) + 2);
    printf("%d ", t.a[i]);
    return;
}

int countLeaf(bst t, int count, int i)
{
    if (t.a[i] == INT_MIN)
        return count;
    if (t.a[(2 * i) + 1] == INT_MIN && t.a[(2 * i) + 2] == INT_MIN)
    {
        count++;
        return count;
    }
    if (i < t.size)
    {
        count = countLeaf(t, count, (2 * i) + 1);
        count = countLeaf(t, count, (2 * i) + 2);
    }
    return count;
}

int countNonLeaf(bst t, int count, int i)
{
    if (i >= t.size || t.a[i] == INT_MIN)
        return count;
    if (((2 * i) + 1 < t.size && t.a[2 * i + 1] != INT_MIN) || ((2 * i) + 2 < t.size && t.a[2 * i + 2] != INT_MIN))
        count++;
    count = countNonLeaf(t, count, 2 * i + 1);
    count = countNonLeaf(t, count, 2 * i + 2);
    return count;
}

int heightBST(bst t, int i)
{
    if (i >= t.size || t.a[i] == INT_MIN)
        return -1;
    int leftHeight = heightBST(t, (2 * i) + 1);
    int rightHeight = heightBST(t, (2 * i) + 2);
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

void destroyBST(bst *t)
{
    t->size = 0;
    free(t->a);
    t->a = NULL;
    return;
}