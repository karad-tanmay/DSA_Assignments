// here element itself is a priority (lower value -> higher priority)
// here enqueue : O(1) and dequeue : O(n)
// ie. insertion in same order as input(irrespective of priority)
// and deletion will be as per priority (find min val, remove it) (also FIFO is followed incase of elements with equal priority)

// there is also other methods (opposite of this) (not used here tho)
// insertion : O(n) (in sorted order)
// deletion : O(1) (direct removal of 1st/ nth element as per sorting order)

typedef struct node{
    int data;
    struct node* next;
}node;

typedef struct pqueue{
    node* front;
    node* rear;
}pqueue;

void init(pqueue *pq);
int isEmpty(pqueue pq);
int len(pqueue pq);
void enqueue(pqueue *pq, int x);
int dequeue(pqueue *pq);
void clearQueue(pqueue *pq);
void displayQueue(pqueue pq);
// void displayQueue(pqueue pq); display as per priority or as per insertion order
// int peekFront(pqueue pq); return highest priority element
// int peekRear(pqueue pq); return lowest priority element