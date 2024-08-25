#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "queue.h"

void init(queue *q){
    q->front = NULL;
    q->rear = NULL;
    return;
}

int isEmpty(queue q){
    return (q.front == NULL);
}

int len(queue q){
    node *p = q.front;
    int i = 0;
    while(p != NULL){
        p = p->next;
        i++;
    }
    return i;
}

void enqueue(queue *q, int x){
    node *nn = (node *)malloc(sizeof(node));
    nn->data = x;
    nn->next = NULL;
    node *p = q->rear;
    p->next = nn;
    q->rear = nn;
    if(isEmpty(*q))
        q->front = nn;
    return;
}

int dequeue(queue *q){
    if(isEmpty(*q))
        return INT_MIN;
    int temp;
    node *p = q->front;
    temp = p->data;
    q->front = p->next;
    if(len(*q) == 1)
        q->rear = NULL;
    free(p);
    return temp;
}

int peekFront(queue q){
    if(isEmpty(q))
        return INT_MIN;
    return q.front->data;
}

int peekRear(queue q){
    if(isEmpty(q))
        return INT_MIN;
    return q.rear->data;
}

void displayQueue(queue q){
    if(isEmpty(q))
        return;
    node *p = q.front;
    while(p != NULL){
        printf("%d ", p->data);
        p = p->next;
    }
    return;
}

void clearQueue(queue *q){
    if(isEmpty(*q))
        return;
    node *p = q->front;
    while(p != NULL){
        q->front = p->next;
        free(p);
        p = q->front;
    }
    q->rear = NULL;
    return;
}