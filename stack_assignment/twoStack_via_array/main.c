#include <stdio.h>
#include "twoStack.h"

void display_menu(){
    printf("\nMenu for twoStack:\n");
    printf("\t1. push1\t9. exit\n");
    printf("\t2. push2\t10. len1\n");
    printf("\t3. pop1\t\t11. len2\n");
    printf("\t4. pop2\t\t12. isEmpty1\n");
    printf("\t5. peek1\t13. isEmpty2\n");
    printf("\t6. peek2\t14. displayStack\n");
    printf("\t7. display1\t15. displayTops\n");
    printf("\t8. display2\n");
    return;
}

int main(){
    stack s;
    int size, tp;
    printf("Enter combined stack size(>1): ");
    scanf("%d", &size);
    init(&s, size);
    int is_on = 1, cmd;
    while(is_on){
        display_menu();
        scanf("%d", &cmd);
        switch(cmd){
            case 1:
                printf("Enter element(push1): ");
                scanf("%d", &tp);
                push1(&s, tp);
                break;

            case 2:
                printf("Enter element(push2): ");
                scanf("%d", &tp);
                push2(&s, tp);
                break;

            case 3:
                printf("pop1: %d\n", pop1(&s));
                break;

            case 4:
                printf("pop2: %d\n", pop2(&s));
                break;

            case 5:
                printf("peek1: %d\n", peek1(s));
                break;

            case 6:
                printf("peek2: %d\n", peek2(s));
                break;

            case 7:
                display1(s);
                break;

            case 8:
                display2(s);
                break;

            case 9:
                freestack(&s);
                is_on = 0;
                break;

            case 10:
                printf("len1: %d\n", len1(s));
                break;

            case 11:
                printf("len2: %d\n", len2(s));
                break;

            case 12:
                printf("isEmpty1: %d\n", isEmpty1(s));
                break;

            case 13:
                printf("isEmpty2: %d\n", isEmpty2(s));
                break;

            case 14:
                displayStack(s);
                break;

            case 15:
                displayTops(s);
                break;

            default:
                printf("Invalid cmd number.\n");
                break;
        }
    }
    return 0;
}