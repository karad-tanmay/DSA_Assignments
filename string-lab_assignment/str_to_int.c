#include <stdio.h>
#include <stdlib.h>

void get_string(char *str){
    char ch;
    int i = 0;
    while((ch = getchar()) != '\n' && ch != EOF) {
        str[i++] = ch;
    }
    str[i] = '\0';
    return;
}

int is_num(char *str){
    int i = 0;
    if(str[i] == '-')
        i++;
    for(; str[i] != '\0'; i++){
        if(str[i] < '0' || str[i] > '9')
            return 0;
    }
    return 1;
}

int main(){
    char str[128];
    int num;
    get_string(str);
    int temp = is_num(str);
    if(temp){
        num = atoi(str);
        printf("%d", num);
    }
    return 0;
}