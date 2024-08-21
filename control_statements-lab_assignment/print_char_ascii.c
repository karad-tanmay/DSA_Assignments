#include <stdio.h>
#include <ctype.h>

int main() {
    char ch;
    while(1){
        printf("Enter a character ('*' to quit): ");
        scanf(" %c", &ch);
        if(ch == '*')
            break;
        printf("Character: %c\n", ch);
        printf("ASCII Value: %d\n", ch);
        if (islower(ch)) 
            printf("Uppercase: %c\n", toupper(ch));
        else if (isupper(ch))
            printf("Lowercase: %c\n", tolower(ch));
        else
            printf("Not an alphabetic character.\n");
        printf("\n");
    }
    return 0;
}
