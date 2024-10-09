#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

int main(){
    tree t = NULL;
    insertNode(&t, 10);
    insertNode(&t, 15);
    insertNode(&t, 5);
    insertNode(&t, 25);
    insertNode(&t, 20);
    insertNode(&t, 25);
    insertNode(&t, 15);
    inorderTraversal(t);
    printf("\n");
    preorderTraversal(t);
    printf("\n");
    postorderTraversal(t);
    printf("\n");
    destroyTree(&t);
    printf("test0\n");
    return 0;
}