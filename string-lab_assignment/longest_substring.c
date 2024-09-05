#include <string.h>
#include <stdio.h>
#define max(a, b) ((a > b) ? a : b)

int lengthOfLongestSubstring(char* s) {
    int i = 0, j = 1, k, flag, max_len = 0;
    while(s[i] != '\0'){
        flag = 0;
        for(k = i; k < j; k++){
            if(s[k] == s[j]){
                flag = 1;
                k = j;
            }
        }
        if(flag){
            max_len = max(max_len, j - i);
            i++;
        }
        else{
            max_len = max(max_len, j - i);
            if(s[j] != '\0')
                j++;
            else
                i++;
        }
    }
    return max_len;
}

int main(){
    char s[128];
    strcpy(s, "pwwkew");
    printf("%d\n", strlen(" "));
    printf("max len: %d\n", lengthOfLongestSubstring(s));
    return 0;
}

#include <string.h>
#define max(a, b) ((a > b) ? a : b)

int lengthOfLongestSubstring(char* s) {
    int i = 0, j = 1, k, flag, max_len = 0;
    for(i = 0; s[i] != '\0'; i++){
        flag = 0;
        for(k = i; k < j; k++){
            if(s[k] == s[j]){
                i++;
                k = j;
            }
        }
        max_len = max(max_len, j - i);
        if(s[j] != '\0')
            j++;
        else
            i++;
    }
    return max_len;
}