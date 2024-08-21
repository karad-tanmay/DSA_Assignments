#include "menu.h" 
#include <stdio.h>
#include <string.h>

// Function to read the command and extract the command and polynomial identifier
// 'cmd' stores the command, 'poly' stores the polynomial identifier
void read_cmd(char *cmd, char *poly){
    char *token = NULL, user_ip[20], ch;
    int i = 0;
    printf("Enter your command: ");

    // Reading user input until a newline or EOF is encountered
    while((ch = getchar()) != '\n' && ch != EOF) {
        user_ip[i++] = ch;
    }
    user_ip[i] = '\0';  // Null-terminate the input string

    // Tokenizing the input to extract the command and the polynomial identifier
    token = strtok(user_ip, " ");
    if(token != NULL)
        strcpy(cmd, token);  // Store the command in 'cmd'
    token = strtok(NULL, "\0");
    if(token != NULL)
        strcpy(poly, token);  // Store the polynomial identifier in 'poly'

    return;
}

// Function to display the menu options to the user
void menu_display(){
    printf("\nMenu for Polynomial ADT Program:\n");
    printf("1. Initialize polynomial (format: init poly1).\n");
    printf("2. Display (format: display poly1).\n");
    printf("3. Change Coefficient of any Exponent (format: change-coeff poly1).\n");
    printf("4. Add poly1 and poly2 (format: add-poly).\n");
    printf("5. Subtract poly2 from poly1 (format: sub-poly).\n");
    printf("6. Exit the program (format: exit).\n");
    return;
}
