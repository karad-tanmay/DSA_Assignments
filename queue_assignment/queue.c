#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

void qinit(queue *q){
    // if(q->front != NULL)
    //     qdelete(q);
    q->front = NULL;
    q->rear = NULL;
    return;
}

int qfull(queue *q){
    node *p = (node *)malloc(sizeof(node));
    if(p == NULL)
        return 1;
    free(p);
    return 0;
}

int qempty(queue *q){
    return (q->front == NULL);
}

void enq(queue *q, data d){
    node *nn = (node*)malloc(sizeof(node));
    nn->d = d;
    nn->next = NULL;
    if(qempty(q)){
        q->front = nn;
        q->rear = nn;
        nn->next = q->front;
    }
    else{
        node *p = q->rear;
        p->next = nn;
        nn->next = q->front;
        q->rear = nn;
    }
    return;
}

data deq(queue *q){
    data temp;
    if(q->front == q->rear){
        temp = q->front->d;
        free(q->front);
        q->rear = NULL;
        return temp;
    }
    node *p = q->front;
    q->front = p->next;
    q->rear->next = q->front;
    temp = p->d;
    free(p);
    return temp;
}
// void qdelete(queue *q);