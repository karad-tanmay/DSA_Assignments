#include <stdio.h>
#include <stdlib.h>
#include "time.h"

int main(){
    time a;
    time b;
    time *c = NULL;

    init(&a, 10, 20, 50);
    init(&b, 5, 30, 40);

    display(a);
    display(b);

    c = add_time(a, b);
    display(*c);
    free(c);

    c = sub_time(a, b);
    display(*c);
    free(c);

    return 0;
}