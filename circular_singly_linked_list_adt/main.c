#include "csll.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    list l1, l2, l3;
    init(&l1);
    init(&l2);
    init(&l3);
    // printf("%d\n", isEmpty(l1));
    append(&l1, 10);
    append(&l1, 10);
    append(&l1, 10);
    // printf("%d\n", len(l1));
    insert_at_beg(&l1, 15);
    // printf("test2\n");
    insert_at_pos(&l1, 20, 2);
    display(l1);

    // display_list_node(l1);
    // remove_at_beg(&l1);
    // display_list_node(l1);
    // remove_at_end(&l1);
    // remove_at_pos(&l1, 1);
    // printf("%d\n", lin_search(l1, 20));
    // printf("test3\n");
    shift_left(&l1);
    display(l1);
    append(&l2, 14);
    append(&l2, 13);
    append(&l2, 12);
    append(&l2, 11);
    merge_list(l1, l2, &l3);
    display(l3);
    free_list(&l1);
    return 0;
}