#include "stack.c"

typedef struct queue{
    stack s1;
    stack s2;
}queue;

void initQueue(queue *q);
int isEmptyQueue(queue q);
int lenQueue(queue q);
void enqueue(queue *q, int x);
int dequeue(queue *q);
int peekFront(queue q);
int peekRear(queue q);
// void displayQueue(queue q);
void clearQueue(queue *q);