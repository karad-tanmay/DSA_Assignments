typedef struct node{
    int data;
    struct node* next;
}node;

typedef struct queue{
    node* front;
    node* rear;
}queue;

void init(queue *q); //done
int isEmpty(queue q); //done
int len(queue q); //done
void enqueue(queue *q, int x); //done
int dequeue(queue *q); //done
int peekFront(queue q); //done
int peekRear(queue q); //done
void displayQueue(queue q); //done
void clearQueue(queue *q); //done