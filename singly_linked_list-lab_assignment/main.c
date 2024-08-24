#include "sll.h"
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int main() {
    list l;

    init(&l);
    append(&l, 10);
    append(&l, 20);
    append(&l, 10);
    append(&l, 30);
    append(&l, 20);
    append(&l, 20);
    append(&l, 30);
    insert_at_beg(&l, 15);
    display(l);
    insert_at_pos(&l, 33, 7);
    // printf("%d\n", remove_at_end(&l));
    // sort(&l);
    remove_dupl(&l);
    display(l);
    // printf("%d\n", lin_search(l, 20));
    printf("%d\n", len(l));

    // to free allocated memory
    free_list(&l);

    return 0;
}