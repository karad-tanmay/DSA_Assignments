#include <stdio.h>

int main() {
    char ch;
    printf("Enter a character: ");
    scanf("%c", &ch);

    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
        printf("Character is an Alphabet\n");
    else if (ch >= '0' && ch <= '9')
        printf("Character is a Digit\n");
    else
        printf("Character is a Special Character\n");

    return 0;
}
