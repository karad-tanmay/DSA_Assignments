#include <stdio.h>
#include "sll.h"

void init(SLL *l){
    *l = NULL;
}

int isEmpty(SLL l){
    return (l == NULL);
}

int len(SLL l){
    nodeSLL *p = l;
    int count = 0;
    while(p){
        p = p->next;
        count++;
    }
    return count;
}

void insert(SLL *l, void *dataPtr, int index){
    // validity of index, dataPtr -
    if(dataPtr == NULL || index < 0 || index > len(*l))
        return;

    // new node creation - 
    nodeSLL *nn = (nodeSLL*)malloc(sizeof(nodeSLL));
    if(nn == NULL)
        return;
    nn->data = dataPtr;
    nn->next = NULL;

    // case if insert at beg -
    if(index == 0){
        nn->next = *l;
        *l = nn;
        return;
    }

    // general insert -
    int i = 0;
    nodeSLL *p = *l;
    while(i < index - 1 && p != NULL){
        p = p->next;
        i++;
    }
    nn->next = p->next;
    p->next = nn;
    return;
}

void* remove(SLL *l, int index){
    // if list is empty case -
    if(isEmpty(*l))
        return NULL;

    // validity of index -
    if(index < 0 || index >= len(*l))
        return NULL;
    void *tp;

    // remove at beg case -
    if(index == 0){
        tp = (*l)->data;
        (*l) = (*l)->next;
        return;
    }

    // general remove -
    int i = 0;
    nodeSLL *p = *l, *q;
    while(i < index - 1){
        p = p->next;
        i++;
    }
    q = p->next;
    p->next = q->next;
    tp = q->data;
    free(q);
    return tp;
}

void deleteList(SLL *l){
    // list empty case -
    if(isEmpty(*l))
        return;
    
    // general delete list -
    nodeSLL *p = *l;
    while(p != NULL){
        *l = p->next;
        free(p->data);
        free(p);
        p = *l;
    }
    return;
}

// for debugging -
void displayPtrs(SLL l);