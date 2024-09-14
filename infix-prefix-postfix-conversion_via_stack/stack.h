// Implementing stack using Singly Linked List.

typedef struct node{
    float data;
    struct node* next;
}node;

typedef struct stack{
    struct node* top;
}stack;

void init(stack *s);
int isEmpty(stack s);
int len(stack s);
void push(stack *s, float x);
float pop(stack *s);
float peek(stack s);
void displayStack(stack s);
void clearStack(stack *s);

// infix-prefix-postfix funcs-

void get_infix(char *infix);
int is_operand(char ch);
float is_operator(char ch);
char get_operator(float sign_num);
float get_result(float num1, float num2, char operator);


// return 1 if current sign has higher precedence than the top of stack.
// return 0 if current sign has lower precedence than the top of stack.
int get_sign_precedence(float sign, stack s);

void infix_to_postfix(char* infix, char* postfix, stack s);

float eval_postfix(char *exp, stack s);