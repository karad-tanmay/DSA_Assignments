#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

int main(){
    tree t = NULL;
    node *p, *q, *r = NULL;
    insertNode(&t, 10);
    insertNode(&t, 15);
    insertNode(&t, 5);
    insertNode(&t, 20);
    insertNode(&t, 25);
    insertNode(&t, 25);
    insertNode(&t, 15);
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
    if(r != NULL){
        r = searchNode(t, 15);
        printf("Search 15: %d\n", r->data);
    }

    destroyTree(&t);
    printf("test0\n");
    return 0;
}