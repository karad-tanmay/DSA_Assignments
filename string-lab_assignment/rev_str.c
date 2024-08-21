#include <stdio.h>

int get_string(char *str){
    char ch;
    int i = 0;
    while((ch = getchar()) != '\n' && ch != EOF) {
        str[i++] = ch;
    }
    str[i] = '\0';
    return i;
}

void put_string(char *str){
    for(int i = 0; str[i] != '\0'; i++)
        printf("%c", str[i]);
    return;
}

void rev_str(char *str, int len){
    int i, j;
    char temp;
    for(i = 0, j = len - 1; i < j; i++, j--){
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
    return;
}

int main(){
    char str[256];
    int len_str = get_string(str);
    rev_str(str, len_str);
    put_string(str);
    return 0;
}