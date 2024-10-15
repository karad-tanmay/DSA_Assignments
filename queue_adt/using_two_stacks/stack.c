#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void initStack(stack *s){
    s->top = NULL;
    return;
}

int isEmptyStack(stack s){
    return (s.top == NULL);
}

int lenStack(stack s){
    node *p = s.top;
    int i = 0;
    while(p != NULL){
        p = p->next;
        i++;
    }
    return i;
}

void push(stack *s, int x){
    node *nn = (node *)malloc(sizeof(node));
    nn->data = x;
    nn->next = NULL;
    if(isEmptyStack(*s)){
        s->top = nn;
        return;
    }
    node *p = s->top;
    nn->next = p;
    s->top = nn;
    return;
}

int pop(stack *s){
    if(isEmptyStack(*s))
        return INT_MIN;
    int temp;
    node *p = s->top;
    s->top = p->next;
    temp = p->data;
    free(p);
    return temp;
}

int peek(stack s){
    if(isEmptyStack(s))
        return INT_MIN;
    return s.top->data;
}

void displayStack(stack s){
    if(isEmptyStack(s))
        return;
    node *p = s.top;
    while(p != NULL){
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
    return;
}

void clearStack(stack *s){
    if(isEmptyStack(*s))
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