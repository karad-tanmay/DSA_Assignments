#include "csll.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
    return;
}

void init(list *l){
    *l = NULL;
    return; 
}

int isEmpty(list l){
    return (l == NULL);
}

int len(list l){
    if(isEmpty(l))
        return 0;
    int i = 0;
    node *p = l;
    do{
        p = p->next;
        i++;
    }while(p != l);
    return i;
}

void append(list *l, int x){
    node *nn = (node *)malloc(sizeof(node));
    nn->data = x;
    nn->next = *l;
    if(isEmpty(*l)){
        *l = nn;
        return;
    }
    node *p = *l;
    do{
        p = p->next;
    }while(p->next != *l);
    p->next = nn;
    return;
}

void insert_at_pos(list *l, int x, int index){
    if(isEmpty(*l) && index == 0){
        append(l, x);
        return;
    }

    if((isEmpty(*l) && index > 0) || index < 0 || index >= len(*l))
        return;

    if(index == len(*l) - 1){
        append(l, x);
        return;
    }

    node *nn = (node *)malloc(sizeof(node));
    nn->data = x;
    nn->next = NULL;
    int i = 0;
    node *p = *l;
    while(i < index - 1){
        p = p->next;
        i++;
    }
    nn->next = p->next;
    p->next = nn;
    return;
}

void insert_at_beg(list *l, int x){
    if(isEmpty(*l)){
        append(l, x);
        return;
    }
    node *p = *l;
    node *nn = (node *)malloc(sizeof(node));
    nn->data = x;
    nn->next = p->next;
    *l = nn;
    return;
}

int remove_at_beg(list *l){
    if(isEmpty(*l))
        return INT_MIN;
    node *p = *l;
    int temp = p->data;
    *l = p->next;
    if(len(*l) == 1)
        *l = NULL;
    free(p);
    return temp;
}

int remove_at_end(list *l){
    if(isEmpty(*l))
        return INT_MIN;
    node *p = *l;
    do{
        p = p->next;
    }while(p->next != NULL);
    node *q = p->next;
    int temp = q->data;
    p->next = *l;
    free(q);
    return temp;
}

int remove_at_pos(list *l, int index){
    if(isEmpty(*l) || index < 0 || index >= len(*l))
        return INT_MIN;

    if(index == len(*l) - 1)
        return remove_at_end(l);

    node *p = *l;
    int i = 0;
    while(i < index - 1){
        p = p->next;
        i++;
    }
    node *q = p->next;
    int temp = q->data;
    p->next = q->next;
    free(q);
    return temp;
}

int lin_search(list l, int x){
    if(isEmpty(l))
        return -1;
    node *p = l;
    int i = 0;
    do{
        if(p->data == x)
            return i;
        p = p->next;
        i++;
    }while(p != l);
    return -1;
}

void sort(list *l);
void remove_dupl(list *l);

void merge_list(list l1, list l2, list *l3);

void free_list(list *l){
    if(isEmpty(*l))
        return;
    node *p = *l, *q = NULL;
    do{
        q = p->next;
        free(p);
        p = q;
    }while(p != *l);
    *l = NULL;
    return;
}
