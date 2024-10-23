#include <stdio.h>
#include "bst.h"

int main(){
    BST t;
    initBST(&t);
    insertNode(&t, 5);
    insertNode(&t, 3);
    insertNode(&t, 8);
    insertNode(&t, 1);
    insertNode(&t, 4);
    insertNode(&t, 7);
    insertNode(&t, 9);
    preorderTraverse(t);
    printf("\n");
    removeNode(&t, 8);
    inorderTraverse(t);
    destroyTree(&t);
    printf("test0");
    return 0;
}