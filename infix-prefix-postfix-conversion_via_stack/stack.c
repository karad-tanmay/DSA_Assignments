#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

void init(stack *s){
    s->top = NULL;
    return;
}

int isEmpty(stack s){
    return (s.top == NULL);
}

int len(stack s){
    node *p = s.top;
    int i = 0;
    while(p != NULL){
        p = p->next;
        i++;
    }
    return i;
}

void push(stack *s, float x){
    node *nn = (node *)malloc(sizeof(node));
    nn->data = x;
    nn->next = NULL;
    if(isEmpty(*s)){
        s->top = nn;
        return;
    }
    node *p = s->top;
    nn->next = p;
    s->top = nn;
    return;
}

float pop(stack *s){
    if(isEmpty(*s))
        return (float)INT_MAX;
    float temp;
    node *p = s->top;
    s->top = p->next;
    temp = p->data;
    free(p);
    return temp;
}

float peek(stack s){
    if(isEmpty(s))
        return (float)INT_MAX;
    return s.top->data;
}

void displayStack(stack s){
    if(isEmpty(s))
        return;
    node *p = s.top;
    while(p != NULL){
        printf("%.2f ", p->data);
        p = p->next;
    }
    printf("\n");
    return;
}

void clearStack(stack *s){
    if(isEmpty(*s))
        return;
    node *p = s->top;
    while(p != NULL){
        s->top = p->next;
        free(p);
        p = s->top;
    }
    s->top = NULL;
    return;
}


// infix - prefix - postfix funcs
#define MAX_SIZE 512

void get_infix(char *infix){
    char ch;
    int i = 0;
    printf("Enter infix expression (use brackets for unary operators): ");
    while((ch = getchar()) != '\n' && ch != EOF && i < MAX_SIZE)
        infix[i++] = ch;
    infix[i] = '\0';
    return;
}

int is_operand(char ch){
    if(ch >= '0' && ch <= '9')
        return 1;
    else if(ch >= 'A' && ch <= 'Z')
        return 1;
    else if(ch >= 'a' && ch <= 'z')
        return 1;
    else if(ch == '.')
        return 1;
    else
        return 0;
}

float is_operator(char ch){
    if(ch == '^')
        return 3.1;
    else if(ch == '%')
        return 2.3;
    else if(ch == '/')
        return 2.2;
    else if(ch == '*')
        return 2.1;
    else if(ch == '+')
        return 1.2;
    else if(ch == '-')
        return 1.1;
    return 0;
}

char get_operator(float sign_num){
    if(sign_num == 3.1f)
        return '^';
    else if(sign_num == 2.3f)
        return '%';
    else if(sign_num == 2.2f)
        return '/';
    else if(sign_num == 2.1f)
        return '*';
    else if(sign_num == 1.1f)
        return '-';
    else if(sign_num == 1.2f)
        return '+';
    return '?';
}

float get_result(float num1, float num2, char operator){
    if(operator == '^')
        return pow(num2, num1);
    else if(operator == '%')
        return (int)num2 % (int)num1;
    else if(operator == '/')
        return num2 / num1;
    else if(operator == '*')
        return num2 * num1;
    else if(operator == '+')
        return num2 + num1;
    else if(operator == '-')
        return num2 - num1;
    return 0;
}

// return 1 if current sign has higher precedence than the top of stack.
// return 0 if current sign has lower precedence than the top of stack.
int get_sign_precedence(float sign, stack s){
    int sign_val = (int)sign;
    int stack_sign = (int)peek(s);
    return (sign_val > stack_sign);
}

void infix_to_postfix(char* infix, char* postfix, stack s){
    int i = 0, j = 0;
    while(infix[i] != '\0'){
        float sign = is_operator(infix[i]);
        if(is_operand(infix[i])){
            postfix[j++] = infix[i];
            if(!(is_operand(infix[i + 1])))
                postfix[j++] = ' ';
        }
        else if(infix[i] == '(')
            push(&s, 0);
        else if(infix[i] == ')'){
            while(peek(s) != 0){
                postfix[j++] = get_operator(pop(&s));
                postfix[j++] = ' ';
            }
            pop(&s);
        }
        else if(sign != 0){
            if(get_sign_precedence(sign, s))
                push(&s, sign);
            else{
                while(!get_sign_precedence(sign, s)){
                    postfix[j++] = get_operator(pop(&s));
                    postfix[j++] = ' ';
                }
                push(&s, sign);
            }
        }
        i++;
    }
    while(!isEmpty(s)){
        postfix[j++] = get_operator(pop(&s));
        postfix[j++] = ' ';
    }
    postfix[j] = '\0';
    return;
}

float eval_postfix(char *postfix, stack s){
    float result = 0;
    float num1, num2;
    int i = 0, j = 0;
    char *temp_num = NULL;
        temp_num = (char*)malloc(15 * sizeof(char));
    while(postfix[i] != '\0'){
        if(is_operand(postfix[i])){
            temp_num[j++] = postfix[i];
            if(!is_operand(postfix[i + 1])){
                temp_num[j] = '\0';
                j = 0;
                push(&s, atof(temp_num));
            }
        }
        else if(is_operator(postfix[i])){
            num1 = pop(&s);
            if(!isEmpty(s))
                num2 = pop(&s);
            else
                num2 = 0;
            result = get_result(num1, num2, postfix[i]);
            push(&s, result);
        }
        i++;
    }
    free(temp_num);
    return pop(&s);
}

// (90*2)/45+2