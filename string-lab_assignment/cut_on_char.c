#include <stdio.h>

char *cutonchar(char *str, char ch){
    int i;
    for(i = 0; str[i] != ch; i++);
    str[i] = '\0';
    return str;
}

void get_string(char *str){
    char ch;
    int i = 0;
    while((ch = getchar()) != '\n' && ch != EOF) {
        str[i++] = ch;
    }
    str[i] = '\0';
    return;
}

int main(){
    char str[128], *first_word;
    get_string(str);
    char ch;
    scanf(" %c", &ch);
    first_word = cutonchar(str, ch);
    printf("%s", first_word);
    return 0;
}