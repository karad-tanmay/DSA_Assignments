typedef struct data{
    char name[16];
    unsigned int age;
}data;

typedef struct node{
    data d;
    struct node* next;
}node;

typedef struct queue{
    node* front;
    node* rear;
}queue;

void qinit(queue *q);
int qfull(queue *q);
int qempty(queue *q);
void enq(queue *q, data d);
data deq(queue *q);
// void qdelete(queue *q);