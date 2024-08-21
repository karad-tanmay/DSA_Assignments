#include <stdio.h>

void get_string(char *str){
    char ch;
    int i = 0;
    while((ch = getchar()) != '\n' && ch != EOF) {
        str[i++] = ch;
    }
    str[i] = '\0';
    return;
}

int char_occ_count(char *str, char ch){
    int count = 0;
    for(int i = 0; str[i] != '\0'; i++){
        if(str[i] == ch)
            count++;
    }
    return count;
}

int main(){
    char str[128];
    char ch;
    get_string(str);
    scanf(" %c", &ch);
    printf("The char %c occured %d times in given string.", ch, char_occ_count(str, ch));
    return 0;
}