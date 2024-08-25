#include "sll.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void swap(int *a, int *b){
    int temp = *a;
    temp = *a;
    *a = *b;
    *b = temp;
    return;
}

void init(list *l) {
    *l = NULL;
}

int isEmpty(list l){
    return (l == NULL);
}

int len(list l){
    int i = 0;
    node *p = l;
    while(p != NULL){
        p = p->next;
        i++;
    }
    return i;
}

void display(list l){
    node *p = l;
    while(p != NULL){
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
    return;
}

// void traverse(list l); (same as display)

void display_list_node(list l){
    node *p = l;
    int i = 0;
    while(p != NULL){
        printf("Node %d:\n\tData: %d\n\tCurrent Node address: %p\n\tNext Node Address: %p\n", i, p->data, p, p->next);
        p = p->next;
        i++;
    }
    return;
}

void display_node(node n, char *var){
    if(&n == NULL)
        return;
    printf("Node %s:\n\tData: %d\n\tCurrent Node address: %p\n\tNext Node Address: %p\n", var, n.data, &n, n.next);
    return;
}

void append(list *l, int x){ //insert at end
    node *nn = (node *)malloc(sizeof(node));
    nn->data = x;
    nn->next = NULL;
    if(*l == NULL)
        *l = nn;
    else{
        node *p = *l;
        while(p->next != NULL)
            p = p->next;
        p->next = nn;
    }
}

void insert_at_beg(list *l, int x){
    node *nn = (node *)malloc(sizeof(node));
    nn->data = x;
    nn->next = *l;
    *l = nn;
    return;
}

void insert_at_pos(list *l, int x, int index){
    if(index == 0){
        insert_at_beg(l, x);
        return;
    }
    if(index < 0 || index >= len(*l))
        return;
    node *nn = (node *)malloc(sizeof(node));
    nn->data = x;
    nn->next = NULL;
    node *p = *l;
    int i = 0;
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
    int temp;
    node *p = *l;
    p = p->next;
    temp = p->data;
    free(l);
    *l = p;
    return temp;
}

int remove_at_pos(list *l, int pos){
    if(isEmpty(*l) || pos < 0 || pos >= len(*l))
        return INT_MIN;
    if(pos == 0)
        return remove_at_beg(l);
    node *p = *l, *q;
    int i = 0;
    while(i < pos - 1){
        p = p->next;
        i++;
    }
    q = p;
    p = p->next;
    q->next = p->next;
    int temp = p->data;
    free(p);
    return temp;
}

int remove_at_end(list *l){
    if(isEmpty(*l))
        return INT_MIN;
    node *p = *l;
    int temp;
    if(len(*l) == 1){
        p = p->next;
        temp = p->data;
        free(p);
        *l = NULL;
        return temp;
    }
    while(p->next->next != NULL)
        p = p->next;
    temp = p->next->data;
    free(p->next);
    p->next = NULL;
    return temp;
}

void sort(list *l){
    if(len(*l) <= 1)
        return;
    node *p = *l, *q = *l;
    // p = p->next;
    // q = q->next;
    while(q != NULL){
        while(p != NULL){
            if(q->data < p->data)
                swap(&q->data, &p->data);
            p = p->next;
        }
        q = q->next;
        p = *l;
    }
    return;
}

int lin_search(list l, int x){
    if(isEmpty(l))
        return -1;
    int i = 0;
    node *p = l;
    while(p != NULL){
        if(p->data == x)
            return i;
        i++;
        p = p->next;
    }
    return -1;
}

void remove_dupl(list *l){
    if(isEmpty(*l))
        return;
    int i = 0, j = 0;
    node *p = *l, *q = *l, *r = *l;
    while(p != NULL){
        q = q->next;
        while(q != NULL){
            if(p->data == q->data){
                swap(&r->data, &q->data);
                remove_at_beg(l);
                r = *l;
            }
            j++;
            q = q->next;
        }
        j = 0;
        i++;
        p = p->next;
        q = p;
    }
    return;
}

void free_list(list *l){
    if(isEmpty(*l))
        return;
    node *p = *l;
    while(p != NULL){
        *l = p->next;
        free(p);
        p = *l;
    }
    *l = NULL;
    return;
}