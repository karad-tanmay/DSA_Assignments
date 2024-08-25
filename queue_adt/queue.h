typedef struct node{
    int data;
    struct node* next;
}node;

typedef struct queue{
    node* front;
    node* rear;
}queue;

void init(queue *q);
int isEmpty(queue q);
int len(queue q);
void enqueue(queue *q, int x);
int dequeue(queue *q);
int peekFront(queue q);
int peekRear(queue q);
void displayQueue(queue q);
void clearQueue(queue *q);