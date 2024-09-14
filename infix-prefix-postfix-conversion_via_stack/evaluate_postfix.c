#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

#define MAX_SIZE 512

int main(){
    stack s;
    init(&s);
    char infix[MAX_SIZE], postfix[MAX_SIZE];
    get_infix(infix);
    infix_to_postfix(infix, postfix, s);
    printf("Postfix Expression: %s\n", postfix);
    printf("Result of given Expression: %.2f", eval_postfix(postfix, s));
    return 0;
}