#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "dll.h"

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void init(DLL *l){
    l->front = NULL;
    l->rear = NULL;
    return;
}

int isEmpty(DLL l){
    return (l.front == NULL);
}

int len(DLL l){
    node *p = l.front;
    int i = 0;
    while(p != NULL){
        i++;
        p = p->next;
    }
    return i;
}

// display funcs-
void display_lr(DLL l){
    if(isEmpty(l))
        return;
    node *p = l.front;
    while(p != NULL){
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
    return;
}

void display_rl(DLL l){
    if(isEmpty(l))
        return;
    node *p = l.rear;
    while(p != NULL){
        printf("%d ", p->data);
        p = p->prev;
    }
    printf("\n");
    return;
}

void display_list_node(DLL l){
    if(isEmpty(l))
        return;
    node *p = l.front;
    int i = 0;
    while(p != NULL){
        printf("Node %d:\n\tData: %d\n\tPrevious Node Address: %p\n\tCurrent Node Address: %p\n\tNext Node Address: %p\n", i, p->data, p->prev, p, p->next);
        i++;
        p = p->next;
    }
    return;
}

void display_node(node n, char *var_name){
    // if(&n == NULL)
    //     return;
    printf("Node %s:\n\tData: %d\n\tPrevious Node Address: %p\n\tCurrent Node Address: %p\n\tNext Node Address: %p\n", var_name, n.data, n.prev, &n, n.next);
    return;
}

// insert funcs-
void append(DLL *l, int x){
    node *nn = (node *)malloc(sizeof(node));
    nn->data = x;
    nn->prev = NULL;
    nn->next = NULL;
    if(isEmpty(*l)){
        l->front = nn;
        l->rear = nn;
        return;
    }
    node *p = l->rear;
    p->next = nn;
    nn->prev = p;
    l->rear = nn;
    return;
}

void insert_at_beg(DLL *l, int x){
    node *nn = (node *)malloc(sizeof(node));
    nn->data = x;
    nn->prev = NULL;
    nn->next = NULL;
    if(isEmpty(*l)){
        l->front = nn;
        l->rear = nn;
        return;
    }
    node *p = l->front;
    p->prev = nn;
    l->front = nn;
    nn->next = p;
    return;
}

void insert_at_pos(DLL *l, int x, int index){
    if(index == 0 && isEmpty(*l))
        append(l, x);
    if(index < 0 || index >= len(*l))
        return;
    if(index == 0){
        insert_at_beg(l, x);
        return;
    }
    node *nn = (node *)malloc(sizeof(node));
    nn->data = x;
    nn->next = NULL;
    nn->prev = NULL;
    node *p = l->front;
    int i = 0;
    while(i < index - 1){
        p = p->next;
        i++;
    }
    nn->next = p->next;
    nn->prev = p;
    p->next->prev = nn;
    p->next = nn;
    return;
}

// remove funcs-
int remove_at_beg(DLL *l){
    if(isEmpty(*l))
        return INT_MIN;
    node *p = l->front;
    p->next->prev = NULL;
    l->front = p->next;
    int temp = p->data;
    free(p);
    return temp;
}

int remove_at_pos(DLL *l, int index){
    if(isEmpty(*l))
        return INT_MIN;
    if(index == 0)
        return remove_at_beg(l);
    else if(index == len(*l) - 1)
        return remove_at_end(l);
    node *p = l->front;
    int i = 0;
    while(i < index){
        p = p->next;
        i++;
    }
    p->next->prev = p->prev;
    p->prev->next = p->next;
    int temp = p->data;
    free(p);
    return temp;
}

int remove_at_end(DLL *l){
    if(isEmpty(*l))
        return INT_MIN;
    node *p = l->rear;
    p->prev->next = NULL;
    l->rear = p->prev;
    int temp = p->data;
    free(p);
    return temp;
}

//other funcs-
int lin_search(DLL l, int x){
    if(isEmpty(l))
        return -1;
    node *p = l.front;
    int i = 0;
    while(p != NULL){
        if(p->data == x)
            return i;
        p = p->next;
        i++;
    }
    return -1;
}

void sort_list(DLL *l){
    if(len(*l) <= 1)
        return;
    node *p = l->front;
    node *q = l->front;
    while(p != NULL){
        q = p->next;
        while(q != NULL){
            if(p->data > q->data)
                swap(&p->data, &q->data);
            q = q->next;
        }
        p = p->next;
    }
    return;
}

int isPalindrome(DLL l){
    if(isEmpty(l))
        return 0;
    int lenL = len(l);
    if(lenL == 1)
        return 1;
    node *p = l.front, *q = l.rear;
    int i = 0, j = lenL;
    while(i <= j){
        if(p->data != q->data)
            return 0;
        p = p->next;
        q = q->prev;
        i++;
        j--;
    }
    return 1;
}

void remove_dupl(DLL *l){
    if(len(*l) <= 1)
        return;
    node *p = l->front;
    node *q = p->next;
    node *r = l->rear;
    while(p != NULL){
        while(q != NULL){
            if(p->data == q->data){
                swap(&q->data, &r->data);
                remove_at_end(l);
                r = l->rear;
            }
            q = q->next;
        }
        p = p->next;
        if(p != NULL)
            q = p->next;
    }
    return;
}

void remove_dupl_func(DLL *l){
    remove_dupl(l);
    remove_dupl(l);
    return;
}

void free_list(DLL *l){
    if(isEmpty(*l))
        return;
    node *p = l->front;
    while(p != NULL){
        l->front = p->next;
        free(p);
        p = l->front;
    }
    l->front = NULL;
    l->rear = NULL;
}
