#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "twoStack.h"

void init(stack *s, int size){
    if(size <= 1)
        return;
    s->size = size;
    s->top1 = -1;
    s->top2 = s->size;
    s->arr = (int *)malloc(sizeof(int) * size);
    return;
}

int isEmpty1(stack s){
    return(s.top1 == -1);
}

int isEmpty2(stack s){
    return(s.top2 == s.size);
}

int len1(stack s){
    return s.top1 + 1;
}

int len2(stack s){
    return s.size - s.top2;
}

void push1(stack *s, int data){
    if(s->top1 >= s->top2 - 1 || s->top1 == s->size - 1)
        return;

    s->top1++;
    s->arr[s->top1] = data;
    return;
}

void push2(stack *s, int data){
    if(s->top2 <= s->top1 + 1 || s->top2 == 0)
        return;

    s->top2--;
    s->arr[s->top2] = data;
    return;
}

int pop1(stack *s){
    if(isEmpty1(*s))
        return INT_MIN;
    return s->arr[s->top1--];
}

int pop2(stack *s){
    if(isEmpty2(*s))
        return INT_MIN;
    return s->arr[s->top2++];
}

int peek1(stack s){
    if(isEmpty1(s))
        return INT_MIN;
    return s.arr[s.top1];
}

int peek2(stack s){
    if(isEmpty2(s))
        return INT_MIN;
    return s.arr[s.top2];
}

void display1(stack s){
    printf("stack1: ");
    for(int i = s.top1; i >= 0; i--)
        printf("%d ", s.arr[i]);
    printf("\n");
    return;
}

void display2(stack s){
    printf("stack2: ");
    for(int i = s.top2; i < s.size; i++)
        printf("%d ", s.arr[i]);
    printf("\n");
    return;
}

void displayStack(stack s){
    printf("whole stack :");
    for(int i = 0; i < s.size; i++){
        printf("%d ", s.arr[i]);
    }
    printf("\n");
}

void displayTops(stack s){
    printf("top1: %d\ntop2: %d\n", s.top1, s.top2);
    return;
}

void freestack(stack *s){
    s->top1 = -1;
    s->top2 = s->size;
    s->size = 0;
    free(s->arr);
    return;
}
