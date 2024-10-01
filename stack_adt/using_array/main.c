#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void display(){
    printf("1. PUSH\n2. POP\n3. PEEK\n4. Exit\nEnter your command no.: ");
}

int main(){
    stack s;
    int tp;
    printf("Enter stack size: ");
    scanf("%d", &tp);
    init(&s, tp);

    int choice, is_on = 1, temp;
    while(is_on){
        display();
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("Enter no. to be pushed: ");
            scanf("%d", &temp);
            push(&s, temp);
            break;

        case 2:
            printf("%d\n", pop(&s));
            break;

        case 3:
            printf("%d\n", peeek(s));
            break;

        case 4:
            freestack(&s);
            is_on = 0;
            break;

        default:
            printf("Invalid Command no.\n");
            break;
        }
    }

    return 0;
}