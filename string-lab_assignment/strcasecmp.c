#include <stdio.h>
#include <string.h>
#include <ctype.h>

int strcasecmp_tp(char *a, char *b){
    *a = tolower(*a);
    *b = tolower(*b);
    int len_a = strlen(a);
    int len_b = strlen(b);
    if(len_a == len_b){
        for(int i = 0; i < len_a; i++){
            if(a[i] < b[i])
                return -1;
            else if(a[i] > b[i])
                return 1;
        }
        return 0;
    }
    else if(len_a < len_b)
        return -1;
    else
        return 1;
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
    char a[128], b[128];
    get_string(a);
    get_string(b);
    int result1 = strcasecmp_tp(a, b);
    if (result1 == 0) {
        printf("\"%s\" and \"%s\" are equal (case-insensitive).\n", a, b);
    } else if (result1 < 0) {
        printf("\"%s\" is less than \"%s\" (case-insensitive).\n", a, b);
    } else {
        printf("\"%s\" is greater than \"%s\" (case-insensitive).\n", a, b);
    }
    return 0;
}