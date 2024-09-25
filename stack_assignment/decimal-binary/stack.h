// Implementing stack using Singly Linked List.

typedef struct node{
    int data;
    struct node* next;
}node;

typedef struct stack{
    struct node* top;
}stack;

void init(stack *s);
int isEmpty(stack s);
int len(stack s);
void push(stack *s, int x);
int pop(stack *s);
int peek(stack s);
void displayStack(stack s);
void clearStack(stack *s);

void deci_to_bin(int num, int *bin, stack s);