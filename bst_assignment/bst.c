#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

void initBST(BST *t){
    *t = NULL;
    return;
}

int BSTHeight(BST t){
    int x, y;
    if(t == NULL)
        return 0;
    x = BSTHeight(t->left);
    y = BSTHeight(t->right);
    return x > y ? x + 1 : y + 1;
}

nodeBST* getInPre(BST t){
    nodeBST *p = t;
    while(p && p->right != NULL)
        p = p->right;
    return p;
}

nodeBST* getInSucc(BST t){
    nodeBST *p = t;
    while(p && p->left != NULL)
        p = p->left;
    return p;
}

void insertNode(BST *t, int data){
    nodeBST* nn = (nodeBST*)malloc(sizeof(nodeBST));
    if(!nn)
        return;
    nn->left = nn->right = nn->parent = NULL;
    nn->month = data;
    nodeBST *p = *t, *q;
    if(p == NULL){
        *t = nn;
        return;
    }
    while(p != NULL){
        q = p;
        if(data < p->month)
            p = p->left;
        else if(data > p->month)
            p = p->right;
        else
            return;
    }
    if(data > q->month)
        q->right = nn;
    else
        q->left = nn;
    nn->parent = q;
    return;
}

void preorderTraverse(BST t){
    stack s;
    init(&s);
    nodeBST *p = t;
    while(p != NULL || !isEmpty(s)){
        if(p != NULL){
            printf("%d ", p->month);
            push(&s, p);
            p = p->left;
        }
        else{
            p = pop(&s);
            p = p->right;
        }
    }
    return;
}

void inorderTraverse(BST t){
    stack s;
    init(&s);
    nodeBST *p = t;
    while(p != NULL || !isEmpty(s)){
        if(p != NULL){
            push(&s, p);
            p = p->left;
        }
        else{
            p = pop(&s);
            printf("%d ", p->month);
            p = p->right;
        }
    }
    return;
}

// void postorderTraverse(BST t){}

void removeNode(BST *t, int data){
    nodeBST *p = *t, *q;
    while(p != NULL){
        if(p == NULL)
            return;
        if(p->left == NULL && p->right == NULL && p->month == data){
            nodeBST *parent = p->parent;
            if(parent->left == p){
                parent->left = NULL;
            }else{
                parent->right = NULL;
            }
            free(p);
            return;
        }
        if(data < p->month)
            p = p->left;
        else if(data > p->month)
            p = p->right;
        else{
            if(BSTHeight(p->left) > BSTHeight(p->right)){
                q = getInPre(p->left);
                p->month = q->month;
                p = q;
                data = p->month;
            }
            else{
                q = getInSucc(p->right);
                p->month = q->month;
                p = q;
                data = p->month;
            }
        }
    }
    return;
}

void destroyTree(BST *t){
    if(*t == NULL)
        return;
    destroyTree(&(*t)->left);
    destroyTree(&(*t)->right);
    free(*t);
    return;
}


// stack funcs -
void init(stack *s){
    s->top = NULL;
    return;
}

int isEmpty(stack s){
    return (s.top == NULL);
}

int len(stack s){
    node *p = s.top;
    int i = 0;
    while(p != NULL){
        p = p->next;
        i++;
    }
    return i;
}

void push(stack *s, nodeBST *q){
    node *nn = (node *)malloc(sizeof(node));
    nn->nodeAdd = q;
    nn->next = NULL;
    if(isEmpty(*s)){
        s->top = nn;
        return;
    }
    node *p = s->top;
    nn->next = p;
    s->top = nn;
    return;
}

nodeBST* pop(stack *s){
    if(isEmpty(*s))
        return NULL;
    nodeBST *temp = NULL;
    node *p = s->top;
    s->top = p->next;
    temp = p->nodeAdd;
    free(p);
    return temp;
}

nodeBST* peek(stack s){
    if(isEmpty(s))
        return NULL;
    return s.top->nodeAdd;
}

void displayStack(stack s){
    if(isEmpty(s))
        return;
    node *p = s.top;
    while(p != NULL){
        printf("%p ", p->nodeAdd);
        p = p->next;
    }
    printf("\n");
    return;
}

void clearStack(stack *s){
    if(isEmpty(*s))
        return;
    node *p = s->top;
    while(p != NULL){
        s->top = p->next;
        free(p);
        p = s->top;
    }
    s->top = NULL;
    return;
}