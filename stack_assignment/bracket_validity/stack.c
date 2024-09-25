#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

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

void push(stack *s, char x){
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

char pop(stack *s){
    if(isEmpty(*s))
        return '?';
    char temp;
    node *p = s->top;
    s->top = p->next;
    temp = p->data;
    free(p);
    return temp;
}

char peek(stack s){
    if(isEmpty(s))
        return '?';
    return s.top->data;
}

void displayStack(stack s){
    if(isEmpty(s))
        return;
    node *p = s.top;
    while(p != NULL){
        printf("%c ", p->data);
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

int isValidParenthesis(char *str, stack s){
    int i = 0;
    while(str[i] != '\0'){
        if(str[i] == '(' || str[i] == '[' || str[i] == '{')
            push(&s, str[i]);
        else if(str[i] == ')' || str[i] == ']' || str[i] == '}'){
            if(peek(s) == '(' && str[i] == ')')
                pop(&s);
            else if(peek(s) == '{' && str[i] == '}')
                pop(&s);
            else if(peek(s) == '[' && str[i] == ']')
                pop(&s);
            else
                return 0;
        }
        i++;
    }
    if(!isEmpty(s))
        return 0;
    return 1;
}