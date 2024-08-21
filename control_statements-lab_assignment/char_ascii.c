#include <stdio.h>

int is_digit(char ch){
    if(ch >= '0' && ch <= '9')
        return 1;
    return 0;
}

int is_alpha(char ch){
    if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
        return 1;
    return 0;
}

int is_lower(char ch){
    if(ch >= 'a' && ch <= 'z')
        return 1;
    return 0;
}

int main(){
    char ch;
    printf("Enter a single character or digit: ");
    scanf(" %c", &ch);
    if(is_digit(ch))
        printf("You entered a digit: %c\n", ch);

    else if(is_alpha(ch)){
        printf("You entered a character: %c\n", ch);
        printf("ASCII Value: %d\n", ch);

        if (is_lower(ch)) 
            printf("It's a lowercase letter.\n");
        else
            printf("It's an uppercase letter.\n");
    }
    else
        printf("You entered a special character: %c\n", ch);

    return 0;
}
