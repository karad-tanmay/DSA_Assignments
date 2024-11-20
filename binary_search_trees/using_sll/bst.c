#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

// node* createNode(int data);

void init(BST *t){
    *t = NULL;
}

int isEmpty(BST t){
    return (t == NULL);
}

int BSTHeight(BST t){
    int x, y;
    if(t == NULL)
        return 0;
    x = BSTHeight(t->left);
    y = BSTHeight(t->right);
    return x > y ? x + 1 : y + 1;
}

node* getInPre(BST t){
    node *p = t;
    while(p && p->right != NULL)
        p = p->right;
    return p;
}

node* getInSucc(BST t){
    node *p = t;
    while(p && p->left != NULL)
        p = p->left;
    return p;
}

void insertNode(BST *t, int data){
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

node* searchNode(BST t, int key){
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

// working
void deleteNode(BST *t, int key){
    if(*t == NULL)
        return;
    if((*t)->left == NULL && (*t)->right == NULL && (*t)->data == key){
        free(*t);
        *t = NULL;
        return;
    }
    node *p = *t, *q;
    if(p->data > key)
        deleteNode(&p->left, key);
    else if(p->data < key)
        deleteNode(&p->right, key);
    else{
        if(BSTHeight(p->left) > BSTHeight(p->right)){
            q = getInPre(p->left);
            p->data = q->data;
            deleteNode(&p->left, q->data);
        }
        else{
            q = getInSucc(p->right);
            p->data = q->data;
            deleteNode(&p->right, q->data);
        }
    }
    return;
}

node* findMinNode(BST t){
    if(isEmpty(t))
        return NULL;
    if(t->left == NULL)
        return t;
    node *p = t;
    return findMinNode(p->left);
}

node* findMaxNode(BST t){
    if(isEmpty(t))
        return NULL;
    if(t->right == NULL)
        return t;
    node *p = t;
    return findMaxNode(p->right);
}

void inorderTraversal(BST t){
    if(t == NULL)
        return;
    inorderTraversal(t->left);
    printf("%d ", t->data);
    inorderTraversal(t->right);
}

void preorderTraversal(BST t){
    if(t == NULL)
        return;
    printf("%d ", t->data);
    preorderTraversal(t->left);
    preorderTraversal(t->right);
}

void postorderTraversal(BST t){
    if(t == NULL)
        return;
    postorderTraversal(t->left);
    postorderTraversal(t->right);
    printf("%d ", t->data);
}

void destroyBST(BST *t){
    if(*t == NULL){
        return;
    }
    node *p = *t;
    destroyBST(&p->left);
    destroyBST(&p->right);
    free(p);
    *t = NULL;
    return;
}
