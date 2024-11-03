#include <stdio.h>
#include "bst.h"

int main(){
    bst t;
    init(&t, 15);
    insert(&t, 10, 0);
    insert(&t, 12, 0);
    insert(&t, 8, 0);
    insert(&t, 9, 0);
    insert(&t, 6, 0);
    insert(&t, 11, 0);
    insert(&t, 15, 0);
    insert(&t, 15, 0);
    for(int i = 0; i < t.size; i++)
        printf("%d ", t.a[i]);
    printf("\n");
    inorder_traversal(t, 0);
    printf("\n");
    preorder_traversal(t, 0);
    printf("\n");
    postorder_traversal(t, 0);
    printf("\n");
    printf("leaf nodes: %d", countLeaf(t, 0, 0));
    printf("\n");
    printf("non leaf nodes: %d", countNonLeaf(t, 0, 0));
    printf("\n");
    printf("Height: %d\n", heightBST(t, 0));
    destroyBST(&t);
    printf("test0");
    return 0;
}
