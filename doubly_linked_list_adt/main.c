#include <stdio.h>
#include "dll.h"

int main(){
    DLL l;
    init(&l); //done
    // insert_at_beg(&l, 15); //done
    append(&l, 12); //done
    append(&l, 12); //done
    append(&l, 12); //done
    append(&l, 12); //done
    append(&l, 12);
    insert_at_pos(&l, 20, 0); //done
    // display_list_node(l); //done
    display_lr(l); //done
    // printf("%d\n", remove_at_beg(&l)); //done
    // display_list_node(l);
    // printf("%d\n", remove_at_end(&l)); //done
    // printf("%d\n", remove_at_pos(&l, 1)); //done
    printf("%d\n", lin_search(l, 5)); //done
    // sort_list(&l); //done
    printf("palin: %d\n", isPalindrome(l)); //done
    remove_dupl_func(&l);
    display_lr(l); //done
    // display_rl(l); //done
    free_list(&l); //done
    printf("test0\n");
    return 0;
}