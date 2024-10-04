#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "pqueue.h"

void init(pqueue *pq){
    pq->front = NULL;
    pq->rear = NULL;
    return;
}

int isEmpty(pqueue pq){
    return (pq.front == NULL);
}

int len(pqueue pq){
    if(isEmpty(pq))
        return 0;
    node *p = pq.front;
    int len = 0;
    while(p != NULL){
        len++;
        p = p->next;
    }
    return len;
}

void enqueue(pqueue *pq, int x){
    node *nn = (node*)malloc(sizeof(node));
    nn->data = x;
    nn->next = NULL;
    if(isEmpty(*pq)){
        pq->front = nn;
        pq->rear = nn;
    }
    else{
        pq->rear->next = nn;
        pq->rear = nn;
    }
    return;
}

int dequeue(pqueue *pq){
    if(isEmpty(*pq))
        return INT_MIN;
    int min_index = -1, min = INT_MAX, i = 0;
    node *p = pq->front, *q;
    // find min, it's index
    while(p->next != NULL){
        if(p->data < min){
            min = p->data;
            min_index = i;
        }
        i++;
        p = p->next;
    }
    // traverse to node before it
    i = 0;
    p = pq->front;
    while(i < min_index - 1){
        p = p->next;
        i++;
    }
    // node deletion
    if(p == pq->front){
        pq->front = p->next;
        i = p->data;
        free(p);
        return i;
    }
    q = p->next;
    p->next = q->next;
    i = q->data;
    if(pq->rear == q)
        pq->rear = p;
    free(q);
    return i;
}

void clearQueue(pqueue *pq){
    if(isEmpty(*pq))
        return;
    node *p = pq->front;
    while(p != NULL){
        pq->front = p->next;
        free(p);
        p = pq->front;
    }
    pq->front = NULL;
    pq->rear = NULL;
    return;
}

void displayQueue(pqueue pq){
    if(isEmpty(pq))
        return;
    node *p = pq.front;
    while(p != NULL){
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
    return;
}