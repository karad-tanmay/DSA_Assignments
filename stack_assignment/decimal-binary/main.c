#include <stdio.h>
#include <limits.h>
#include "stack.h"

#define MAX_SIZE 32

void display_bin(int *bin){
    for(int i = 0; i < MAX_SIZE; i++)
        printf("%d", bin[i]);
    printf("\n");
    return;
}

int main(){
    stack s;
    init(&s);
    int deci_num, bin_num[MAX_SIZE] = {0};
    scanf("%d", &deci_num);
    deci_to_bin(deci_num, bin_num, s);
    display_bin(bin_num);
    return 0;
}