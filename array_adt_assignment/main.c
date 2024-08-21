#include "array.h"
#include "menu.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    array *a = NULL;
    array *b = NULL;
    array *c = NULL;

    char cmd[10], user_arr[5];
    int is_on = 1;

    while(is_on > 0){
        menu_display();
        read_cmd(cmd, user_arr);

        if(strcmp("exit", cmd) == 0){
            if(a != NULL){
                free(a->A);
                free(a);
            }
            if(b != NULL){
                free(b->A);
                free(b);
            }
            if(c != NULL){
                free(c->A);
                free(c);
            }
            is_on = -1;
        }

        else if(strcmp("init", cmd) == 0){
            int size;
            printf("Enter size of Array: ");
            scanf("%d", &size);
            getchar();
            if(strcmp("arr1", user_arr) == 0)
                a = init(a, size);
            else if(strcmp("arr2", user_arr) == 0)
                b = init(b, size);
            else{
                printf("Incorrect Array name.");
                continue;
            }
        }

        else if(strcmp("append", cmd) == 0){
            int ele;
            printf("Enter your no.: ");
            scanf("%d", &ele);
            getchar();
            if(strcmp("arr1", user_arr) == 0 && a != NULL)
                append(a, ele);
            else if(strcmp("arr2", user_arr) == 0 && b != NULL)
                append(b, ele);
            else if(strcmp("arr3", user_arr) == 0 && c != NULL)
                append(c, ele);
            else{
                printf("Incorrect Array name or Array uninitialized.\n");
                continue;
            }
        }

        else if(strcmp("insert", cmd) == 0){
            int index, ele;
            printf("Enter index and element: ");
            scanf("%d%d", &index, &ele);
            getchar();
            if(strcmp("arr1", user_arr) == 0 && a != NULL)
                insert_at_index(a, ele, index);
            else if(strcmp("arr2", user_arr) == 0 && b != NULL)
                insert_at_index(b, ele, index);
            else if(strcmp("arr3", user_arr) == 0 && c != NULL)
                insert_at_index(c, ele, index);
            else{
                printf("Incorrect Array name or Array uninitialized.\n");
                continue;
            }
        }

        else if(strcmp("remove", cmd) == 0){
            int index;
            printf("Enter index: ");
            scanf("%d", &index);
            getchar();
            if(strcmp("arr1", user_arr) == 0 && a != NULL)
                remove_at_index(a, index);
            else if(strcmp("arr2", user_arr) == 0 && b != NULL)
                remove_at_index(b, index);
            else if(strcmp("arr3", user_arr) == 0 && c != NULL)
                remove_at_index(c, index);
            else{
                printf("Incorrect Array name or Array uninitialized.\n");
                continue;
            }
        }

        else if(strcmp("display", cmd) == 0){
            if(strcmp("arr1", user_arr) == 0 && a != NULL)
                display(*a);
            else if(strcmp("arr2", user_arr) == 0 && b != NULL)
                display(*b);
            else if(strcmp("arr3", user_arr) == 0 && c != NULL)
                display(*c);
            else{
                printf("Incorrect Array name or Array uninitialized.\n");
                continue;
            }
        }

        else if(strcmp("max", cmd) == 0){
            if(strcmp("arr1", user_arr) == 0 && a != NULL)
                printf("%d\n", max(*a));
            else if(strcmp("arr2", user_arr) == 0 && b != NULL)
                printf("%d\n", max(*b));
            else if(strcmp("arr3", user_arr) == 0 && c != NULL)
                printf("%d\n", max(*c));
            else{
                printf("Incorrect Array name or Array uninitialized.\n");
                continue;
            }
        }

        else if(strcmp("min", cmd) == 0){
            if(strcmp("arr1", user_arr) == 0 && a != NULL)
                printf("%d\n", min(*a));
            else if(strcmp("arr2", user_arr) == 0 && b != NULL)
                printf("%d\n", min(*b));
            else if(strcmp("arr3", user_arr) == 0 && c != NULL)
                printf("%d\n", min(*c));
            else{
                printf("Incorrect Array name or Array uninitialized.\n");
                continue;
            }
        }

        else if(strcmp("reverse", cmd) == 0){
            if(strcmp("arr1", user_arr) == 0 && a != NULL)
                reverse(a);
            else if(strcmp("arr2", user_arr) == 0 && b != NULL)
                reverse(b);
            else if(strcmp("arr3", user_arr) == 0 && c != NULL)
                reverse(c);
            else{
                printf("Incorrect Array name or Array uninitialized.\n");
                continue;
            }
        }

        else if(strcmp("merge", cmd) == 0 && a != NULL && b != NULL){
            if(c != NULL){
                free(c->A);
                free(c);
            }
            c = merge(*a, *b);
        }

        else{
            printf("Invalid Command.\n");
            continue;
        }
    }

    return 0;
}