// circular queue using array

typedef struct queue{
    int size;
    int front;
    int rear;
    int len;
    int *arr;
}queue;

void init(queue *q, int size);
int isEmpty(queue q);
int isFull(queue q);
int len(queue q);
void enqueue(queue *q, int x);
int dequeue(queue *q);
int peekFront(queue q);
int peekRear(queue q);
void displayQueue(queue q);
void clearQueue(queue *q);