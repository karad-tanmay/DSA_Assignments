#include <stdio.h>
#include "stack.h"

#define MAX_SIZE 512

void get_string(char* user_ip){
    char ch;
    int i = 0;
    while((ch = getchar()) != '\n' && ch != EOF && i < MAX_SIZE)
        user_ip[i++] = ch;
    user_ip[i] = '\0';
    return;
}

int main(){
    stack s;
    init(&s);
    char user_str[MAX_SIZE], rev_str[MAX_SIZE];
    get_string(user_str);
    reverseString(user_str, rev_str, s);
    printf("Reversed String: %s\n", rev_str);
    return 0;
}
