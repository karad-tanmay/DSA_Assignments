#include <stdio.h>
#include <string.h>
#define max(a, b) ((a > b) ? a : b)

void longest_subseq_cont(char *str_main, char *str_sub, int *len){
    int i, j, temp = 0;
    for(i = 0, j = 0; str_main[i] != '\0' && str_sub[j] != '\0';){
        if(str_main[i] == str_sub[j]){
            i++;
            j++;
            temp++;
            *len = max(*len, temp);
        }
        else
            return;
    }
    return;
}

int longest_subseq(char *str_main, char *str_sub, char **p){
    int len = 0, i, j, temp = 0;
    for(i = 0; str_main[i] != '\0'; i++){
        for(j = 0; str_sub[j] != '\0'; j++){
            if(str_main[i] == str_sub[j]){
                temp = len;
                longest_subseq_cont(str_main + i, str_sub + j, &len);
                if(len > temp)
                    *p = (str_main + i);
            }
        }
    }
    return len;
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
    char str_main[128], str_sub[128], *p = NULL;
    get_string(str_main);
    get_string(str_sub);
    int len = longest_subseq(str_main, str_sub, &p);
    if(len > 0){
        for(int i = 0; i < len; i++)
            printf("%c", p[i]);
    }
    else
        printf("no subsequence found\n");
    return 0;
}