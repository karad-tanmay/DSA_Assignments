#include <stdio.h>
#include <string.h>

char* strtok_temp(char *str, char *delim){
    static char *p;
    char *q;
    if(str != NULL)
        p = str;
    q = p;
    int i, j, tp = -1;
    for(i = 0; tp < 0 && p[i] != '\0'; i++){
        for(j = 0; p[i] != delim[j] && delim[j] != '\0'; j++);
        if(delim[j] != '\0')
            tp = i;
    }
    if(p[i] == '\0')
        return NULL;
    p[tp++] = '\0';
    p = &p[tp];
    if(strlen(q) == 0)
        q = strtok_temp(NULL, delim);
    return q;
}

void get_string(char *str){
    char ch;
    int i = 0;
    while((ch = getchar()) != '\n' && ch != EOF){
        str[i++] = ch;
    }
    str[i] = '\0';
    return;
}

int main(){
    char str[128];
    get_string(str);
    char *word;
    word = strtok_temp(str, " ,;:!-?.");
    while(word != NULL){
        printf("%s\n", word);
        word = strtok_temp(NULL, " ,;:!-?.");
    }
    return 0;
}