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

void display(list l){
    if(isEmpty(l))
        return;
    node *p = l;
    do{
        printf("%d ", p->data);
        p = p->next;
    }while(p != l);
    printf("\n");
    return;
}

void display_list_node(list l){
    if(isEmpty(l))
        return;
    node *p = l;
    int i = 0;
    do{
        printf("Node %d:\n\tData: %d\n\tCurrent Node address: %p\n\tNext Node Address: %p\n", i, p->data, p, p->next);
        p = p->next;
        i++;
    }while(p != l);
}

void append(list *l, int x){
    node *nn = (node *)malloc(sizeof(node));
    nn->data = x;
    if(isEmpty(*l)){
        *l = nn;
        nn->next = *l;
        return;
    }
    node *p = *l;
    do{
        p = p->next;
    }while(p->next != *l);
    p->next = nn;
    nn->next = *l;
    return;
}

void insert_at_beg(list *l, int x){
    if(isEmpty(*l)){
        append(l, x);
        return;
    }
    node *p = *l, *q = *l;
    while(q->next != *l)
        q = q->next;
    node *nn = (node *)malloc(sizeof(node));
    nn->data = x;
    nn->next = p->next;
    *l = nn;
    q->next->next = *l;
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
    if(index == 0){
        insert_at_beg(l, x);
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

int remove_at_beg(list *l){
    if(isEmpty(*l))
        return INT_MIN;
    node *p = *l, *q = *l;
    do{
        q = q->next;
    }while(q->next != *l);
    int temp = p->data;
    if(len(*l) == 1)
        *l = NULL;
    else
        *l = p->next;
    q->next = *l;
    free(p);
    return temp;
}

int remove_at_end(list *l){
    if(isEmpty(*l))
        return INT_MIN;
    if(len(*l) == 1)
        return remove_at_beg(l);
    node *p = *l;
    node *q;
    do{
        q = p;
        p = p->next;
    }while(p->next != *l);
    int temp = p->data;
    q->next = *l;
    free(p);
    return temp;
}

int remove_at_pos(list *l, int index){
    if(isEmpty(*l) || index < 0 || index >= len(*l))
        return INT_MIN;

    if(index == len(*l) - 1)
        return remove_at_end(l);
    else if(index == 0)
        return remove_at_beg(l);
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

// void sort(list *l);

// void remove_dupl(list *l);

void merge_list(list l1, list l2, list *l3){
    node *p = l1;
    do{
        append(l3, p->data);
        p = p->next;
    }while(p != l1);
    p = l2;
    do{
        append(l3, p->data);
        p = p->next;
    }while(p != l2);
    return;
}

void shift_left(list *l){
    node *p = *l;
    int temp = p->data;
    while(p->next != *l){
        p->data = p->next->data;
        p = p->next;
    }
    p->data = temp;
    return;
}

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
