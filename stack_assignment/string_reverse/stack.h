// Implementing stack using Singly Linked List.

typedef struct node{
    char data;
    struct node* next;
}node;

typedef struct stack{
    struct node* top;
}stack;

void init(stack *s);
int isEmpty(stack s);
int len(stack s);
void push(stack *s, char x);
char pop(stack *s);
char peek(stack s);
void displayStack(stack s);
void clearStack(stack *s);

void reverseString(char *src, char *dest, stack s);