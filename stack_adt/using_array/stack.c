#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "stack.h"

void init(stack *s, int size){
    if(size <= 0)
        return;
    s->top = -1;
    s->size = size;
    s->arr = (int *)malloc(sizeof(int) * size);
    return;
}

int isEmpty(stack s){
    return(s.top == -1);
}

int len(stack s){
    return s.top + 1;
}

void push(stack *s, int data){
    if(isEmpty(*s)){
        s->top = 0;
        s->arr[s->top] = data;
        return;
    }

    if(s->top == s->size - 1)
        return;

    s->top++;
    s->arr[s->top] = data;
    return;
}

int pop(stack *s){
    if(isEmpty(*s))
        return INT_MIN;
    return s->arr[s->top--];
}

int peeek(stack s){
    if(isEmpty(s))
        return INT_MIN;
    return s.arr[s.top];
}

void freestack(stack *s){
    s->top = -1;
    s->size = 0;
    free(s->arr);
    return;
}