#include <stdio.h>
#include <ctype.h>

int main(){
    char text[100], ch;
    int vowels = 0, i = 0;
    printf("Enter text: ");
    while((ch = getchar()) != '\n' && ch != EOF) {
        text[i++] = ch;
    }
    text[i] = '\0';
    for(i = 0; text[i] != '\0'; i++){
        ch = text[i];
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
            vowels++;
    }
    printf("Number of vowels: %d.\n", vowels);
    return 0;
}
