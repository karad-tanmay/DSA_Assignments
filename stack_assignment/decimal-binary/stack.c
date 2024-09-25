#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_SIZE 32

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

void push(stack *s, int x){
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

int pop(stack *s){
    if(isEmpty(*s))
        return INT_MIN;
    int temp;
    node *p = s->top;
    s->top = p->next;
    temp = p->data;
    free(p);
    return temp;
}

int peek(stack s){
    if(isEmpty(s))
        return INT_MIN;
    return s.top->data;
}

void displayStack(stack s){
    if(isEmpty(s))
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

// void twos_comp(stack *s){
//     int lenS = len(*s);
//     int *tp = (int*)malloc((lenS + 1) * sizeof(int));
//     int i = 1;
//     while(!isEmpty(*s))
//         tp[i++] = pop(s) ^ 1;
    
// }

void deci_to_bin(int num, int *bin, stack s){
    int sf = 0, carry = 1, i = 0;
    if(num < 0){
        num *= -1;
        sf = 1;
    }
    while(num){
        push(&s, num % 2);
        num /= 2;
    }
    int temp = len(s);
    i = MAX_SIZE - temp;
    while(!isEmpty(s))
        bin[i++] = pop(&s);
    if(sf){
        for(i = 0; i < MAX_SIZE; i++)
            bin[i] = bin[i] ^ 1;
        i--;
        while(carry){
            if(bin[i] == 1)
                bin[i--] = 0;
            else{
                bin[i] = 1;
                carry = 0;
            }
        }
    }
    return;
}