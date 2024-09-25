typedef struct stack{
    int top1;
    int top2;
    int size;
    int *arr;
}stack;

void init(stack *s, int size);

int isEmpty1(stack s);
int isEmpty2(stack s);

int len1(stack s);
int len2(stack s);

void push1(stack *s, int data);
void push2(stack *s, int data);

int pop1(stack *s);
int pop2(stack *s);

int peek1(stack s);
int peek2(stack s);

void display1(stack s);
void display2(stack s);

void displayStack(stack s);

void displayTops(stack s);

void freestack(stack *s);