// Implementing stack using Singly Linked List.

typedef struct node{
    int data;
    struct node* next;
}node;

typedef struct stack{
    struct node* top;
}stack;

void initStack(stack *s);
int isEmptyStack(stack s);
int lenStack(stack s);
void push(stack *s, int x);
int pop(stack *s);
int peek(stack s);
void displayStack(stack s);
void clearStack(stack *s);