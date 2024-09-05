#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main(){
    stack s;
    init(&s, 10);
    push(&s, 10);
    printf("%d\n", pop(&s));
    printf("%d\n", peeek(s));
    freestack(&s);
    printf("test0\n");
    return 0;
}