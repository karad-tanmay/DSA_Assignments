#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "queue.h"

void initQueue(queue *q){
    initStack(&(q->s1));
    initStack(&(q->s2));
    return;
}

int isEmptyQueue(queue q){
    return (isEmptyStack(q.s1) && isEmptyStack(q.s2));
}

int lenQueue(queue q){
    return (lenStack(q.s1) + lenStack(q.s2));
}

void enqueue(queue *q, int x){
    push(&(q->s1), x);
    return;
}

int dequeue(queue *q){
    if(isEmptyQueue(*q))
        return INT_MIN;
    if(isEmptyStack(q->s2)){
        while(!isEmptyStack(q->s1))
            push(&(q->s2), pop(&(q->s1)));
    }
    return pop(&(q->s2));
}

int peekFront(queue q){
    if(isEmptyQueue(q))
        return INT_MIN;
    if(!isEmptyStack(q.s2))
        return peek(q.s2);
    node *p = q.s1.top;
    while(p->next != NULL)
        p = p->next;
    return p->data;
}

int peekRear(queue q){
    if(isEmptyQueue(q))
        return INT_MIN;
    if(!isEmptyStack(q.s1))
        return peek(q.s1);
    node *p = q.s2.top;
    while(p->next != NULL)
        p = p->next;
    return p->data;
}

// void displayQueue(queue q);

void clearQueue(queue *q){
    clearStack(&(q->s1));
    clearStack(&(q->s2));
    return;
}