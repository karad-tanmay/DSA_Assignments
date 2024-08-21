#include <stdio.h>

int main() {
    char ch;
    printf("Enter a character: ");
    scanf("%c", &ch);

    if (ch >= 'A' && ch <= 'Z')
        printf("Character is Uppercase\n");
    else if (ch >= 'a' && ch <= 'z')
        printf("Character is Lowercase\n");
    else
        printf("Character is not an Alphabet\n");

    return 0;
}
