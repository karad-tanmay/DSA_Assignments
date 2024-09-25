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
    char user_str[MAX_SIZE];
    get_string(user_str);
    int temp = isValidParenthesis(user_str, s);
    printf("result: %d\n", temp);
    if(temp)
        printf("Valid Parenthesis.\n");
    else
        printf("Invalid Parenthesis.\n");
    return 0;
}