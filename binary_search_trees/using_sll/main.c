#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

int main()
{
    BST t = NULL;
    node *p, *q, *r = NULL;
    insertNode(&t, 10);
    insertNode(&t, 15);
    insertNode(&t, 5);
    insertNode(&t, 12);
    insertNode(&t, 25);
    insertNode(&t, 3);
    insertNode(&t, 8);
    inorderTraversal(t);
    printf("\n");
    preorderTraversal(t);
    printf("\n");
    postorderTraversal(t);
    printf("\n");

    p = findMaxNode(t);
    printf("max: %d\n", p->data);
    q = findMinNode(t);
    printf("min: %d\n", q->data);
    if (r != NULL)
    {
        r = searchNode(t, 15);
        printf("Search 15: %d\n", r->data);
    }
    deleteNode(&t, 5);
    inorderTraversal(t);
    printf("\n");
    destroyBST(&t);
    printf("test0\n");
    return 0;
}