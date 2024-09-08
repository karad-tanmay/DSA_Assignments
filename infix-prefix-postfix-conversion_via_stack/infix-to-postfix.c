#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

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

int is_operator(char ch){
    if(ch == '^')
        return 6;
    else if(ch == '%')
        return 5;
    else if(ch == '/')
        return 4;
    else if(ch == '*')
        return 3;
    else if(ch == '+')
        return 2;
    else if(ch == '-')
        return 1;
    return 0;
}

// return 1 if current sign has higher precedence than the top of stack.
// return 0 if current sign has lower precedence than the top of stack.
int get_sign_precedence(int sign, stack s){
    int stack_sign = is_operator(peek(s));
    return (sign > stack_sign);
}

void infix_to_postfix(char* infix, char* postfix, stack s){
    int i = 0, j = 0;
    while(infix[i] != '\0'){
        int sign = is_operator(infix[i]);
        if(is_operand(infix[i])){
            postfix[j++] = infix[i];
            if(!(is_operand(infix[i + 1])))
                postfix[j++] = ' ';
        }
        else if(infix[i] == '(')
            push(&s, infix[i]);
        else if(infix[i] == ')'){
            while(peek(s) != '('){
                postfix[j++] = pop(&s);
                postfix[j++] = ' ';
            }
            pop(&s);
        }
        else if(sign != 0){
            if(get_sign_precedence(sign, s))
                push(&s, infix[i]);
            else{
                while(!isEmpty(s)){
                    postfix[j++] = pop(&s);
                    postfix[j++] = ' ';
                }
                push(&s, infix[i]);
            }
        }
        i++;
    }
    while(!isEmpty(s)){
        postfix[j++] = pop(&s);
        postfix[j++] = ' ';
    }
    postfix[j] = '\0';
    return;
}

int main(){
    stack s;
    init(&s);
    char infix[MAX_SIZE], postfix[MAX_SIZE];
    get_infix(infix);
    infix_to_postfix(infix, postfix, s);
    printf("Postfix Expression: %s\n", postfix);
    return 0;
}