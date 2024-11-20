#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "queue.h"

void init(queue *q, int size){
    q->size = size;
    q->len = 0;
    q->front = 0;
    q->rear = 0;
    q->arr = (int*)malloc(size * sizeof(int));
}

int isEmpty(queue q){
    return (q.len == 0);
}

int isFull(queue q){
    return (q.len == q.size);
}

void enqueue(queue *q, int x){
    if(isFull(*q))
        return;
    q->arr[q->rear] = x;
    q->len++;
    if(q->rear == q->size - 1)
        q->rear = 0;
    else
        q->rear++;
    return;
}

int dequeue(queue *q){
    if(isEmpty(*q))
        return INT_MIN;
    int temp = q->arr[q->front];
    q->len--;
    if(q->front == q->size - 1)
        q->front = 0;
    else
        q->front++;
    return temp;
}

int peekFront(queue q){
    if(isEmpty(q))
        return INT_MIN;
    return q.arr[q.front];
}

int peekRear(queue q){
    if(isEmpty(q))
        return INT_MIN;
    if(q.rear == 0)
        return q.arr[q.size - 1];
    return q.arr[q.rear - 1];
}

// got issues to solve with this:
void displayQueue(queue q){
    if(isEmpty(q))
        return;
    int i, j = q.front;
    for(i = 0; i < q.len; i++){
        if(j == q.size)
            j = 0;
        printf("%d ", q.arr[j]);
        j++; 
    }
    printf("\n");
    return;
}

void clearQueue(queue *q){
    free(q->arr);
    q->size = 0;
    q->len = 0;
    q->front = 0;
    q->rear = 0;
    return;
}