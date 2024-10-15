#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "bst.h"

void init(bst *t, int size){
    if(size <= 0)
        return;
    t->size = size;
    t->a = (int*)malloc(sizeof(int) * size);
    for(int i = 0; i < size; i++)
        t->a[i] = INT_MIN;
    return;
}

void insert(bst *t, int data, int i){
    if(t->a[i] == INT_MIN){
        t->a[i] = data;
        return;
    }
    if(i < t->size){
        if(data < t->a[i])
            insert(t, data, (2 * i) + 1);
        else if(data > t->a[i])
            insert(t, data, (2 * i) + 2);
    }
    return;
}

void inorder_traversal(bst t, int i){
    if(t.a[i] == INT_MIN || i >= t.size)
        return;
    inorder_traversal(t, (2 * i) + 1);
    printf("%d ", t.a[i]);
    inorder_traversal(t, (2 * i) + 2);
    return;
}

void preorder_traversal(bst t, int i){
    if(t.a[i] == INT_MIN || i >= t.size)
        return;
    printf("%d ", t.a[i]);
    inorder_traversal(t, (2 * i) + 1);
    inorder_traversal(t, (2 * i) + 2);
    return;
}

void postorder_traversal(bst t, int i){
    if(t.a[i] == INT_MIN || i >= t.size)
        return;
    inorder_traversal(t, (2 * i) + 1);
    inorder_traversal(t, (2 * i) + 2);
    printf("%d ", t.a[i]);
    return;
}

void destroyBST(bst *t){
    t->size = 0;
    free(t->a);
    t->a = NULL;
    return;
}