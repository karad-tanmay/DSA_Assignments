typedef struct stack{
    int top;
    int size;
    int *arr;
}stack;

void init(stack *s, int size);
int isEmpty(stack s);
int len(stack s);
void push(stack *s, int data);
int pop(stack *s);
int peeek(stack s);
void freestack(stack *s);