#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main(){
    stack s;
    init(&s);
    printf("is empty: %d\n", isEmpty(s));
    push(&s, 10);
    push(&s, 11);
    push(&s, 12);
    push(&s, 13);
    printf("len: %d\n", len(s));
    displayStack(s);
    printf("%d\n", pop(&s));
    printf("%d\n", pop(&s));
    printf("%d\n", pop(&s));
    printf("%d\n", pop(&s));
    printf("%d\n", peek(s));
    displayStack(s);
    printf("test0\n");
    clearStack(&s);
    return 0;
}