#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

// node* createNode(int data);

void init(tree *t){
    *t = NULL;
}

int isEmpty(tree t){
    return (t == NULL);
}

void insertNode(tree *t, int data){
    if(*t == NULL){
        (*t) = (node*)malloc(sizeof(node));
        (*t)->data = data;
        (*t)->left = (*t)->right = NULL;
        return;
    }
    else{
        node *p = *t;
        if(data < p->data)
            insertNode(&p->left, data);
        else if(data > p->data)
            insertNode(&p->right, data);
    }
    return;
}

node* searchNode(tree t, int key){
    if(t == NULL)
        return NULL;
    else{
        node *p = t;
        if(p->data == key)
            return p;
        else if(key < p->data)
            return searchNode(p->left, key);
        else
            return searchNode(p->right, key);
    }
}

node* findMinNode(tree t){
    if(isEmpty(t))
        return NULL;
    if(t->left == NULL)
        return t;
    node *p = t;
    return findMinNode(p->left);
}

node* findMaxNode(tree t){
    if(isEmpty(t))
        return NULL;
    if(t->right == NULL)
        return t;
    node *p = t;
    return findMaxNode(p->right);
}

void inorderTraversal(tree t){
    if(t == NULL)
        return;
    inorderTraversal(t->left);
    printf("%d ", t->data);
    inorderTraversal(t->right);
}

void preorderTraversal(tree t){
    if(t == NULL)
        return;
    printf("%d ", t->data);
    preorderTraversal(t->left);
    preorderTraversal(t->right);
}

void postorderTraversal(tree t){
    if(t == NULL)
        return;
    postorderTraversal(t->left);
    postorderTraversal(t->right);
    printf("%d ", t->data);
}

void destroyTree(tree *t){
    if(*t == NULL){
        return;
    }
    node *p = *t;
    destroyTree(&p->left);
    destroyTree(&p->right);
    free(p);
    *t = NULL;
    return;
}
