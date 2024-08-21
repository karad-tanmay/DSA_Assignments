#include <stdio.h>
#include <string.h>
#include "menu.h"

// Function to read the command and array name from user input
void read_cmd(char *cmd, char *arr){
    char *token = NULL, user_ip[15];  // Buffer to store user input
    int i = 0;
    printf("Enter your command: ");
    char ch;
    // Read user input until newline or EOF
    while((ch = getchar()) != '\n' && ch != EOF) {
        user_ip[i++] = ch;
    }
    user_ip[i] = '\0';  // Null-terminate the string
    // Extract the command from the user input
    token = strtok(user_ip, " ");
    if(token != NULL)
        strcpy(cmd, token);  // Copy command to cmd
    // Extract the array name from the user input
    token = strtok(NULL, "\0");
    if(token != NULL)
        strcpy(arr, token);  // Copy array name to arr
    return;
}

// Function to display the menu options for the Array ADT Program
void menu_display(){
    printf("\nMenu for Array ADT Program:\n");
    printf("1. Initialize array (format: init arr1).\n");  // Option to initialize an array
    printf("2. Append (format: append arr1).\n");         // Option to append an element to an array
    printf("3. Insert Element (format: insert arr1).\n"); // Option to insert an element at a specific index
    printf("4. Remove Element (format: remove arr1).\n"); // Option to remove an element from the array
    printf("5. Max Element of Array (format: max arr1).\n"); // Option to find the maximum element in the array
    printf("6. Min Element of Array (format: min arr1).\n"); // Option to find the minimum element in the array
    printf("7. Reverse Array (format: reverse arr1).\n"); // Option to reverse the array
    printf("8. Merge Array (format: merge).\n");          // Option to merge two arrays
    printf("9. Exit (format: exit).\n");                  // Option to exit the program
    return;
}