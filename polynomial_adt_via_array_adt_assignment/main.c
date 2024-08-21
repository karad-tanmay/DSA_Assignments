#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "polynomial.h"
#include "menu.h"

// Main function
int main(){
    // Pointers to hold polynomial structures
    polynomial *p1 = NULL;
    polynomial *p2 = NULL;
    polynomial *p3 = NULL;

    char cmd[10], user_poly[8];  // Variables to store command and polynomial name
    int is_on = 1;  // Flag to control the program loop
    while(is_on > 0){
        menu_display();  // Display the menu options
        read_cmd(cmd, user_poly);  // Read the command and polynomial name from the user

        // Handle exit command
        if(strcmp("exit", cmd) == 0){
            // Free dynamically allocated memory for all polynomials before exiting
            if (p1 != NULL) {
                free(p1->coef);
                free(p1);
            }
            if (p2 != NULL) {
                free(p2->coef);
                free(p2);
            }
            if (p3 != NULL) {
                free(p3->coef);
                free(p3);
            }
            is_on = -1;  // Set flag to terminate the loop
        }

        // Handle initialization of polynomials
        else if(strcmp("init", cmd) == 0){
            int degree;
            printf("Enter Degree of Polynomial: ");
            scanf("%d", &degree);
            getchar();  // Consume the newline character after scanf
            if(strcmp("poly1", user_poly) == 0)
                p1 = init(p1, degree);  // Initialize polynomial 1
            else if(strcmp("poly2", user_poly) == 0)
                p2 = init(p2, degree);  // Initialize polynomial 2
            else{
                printf("Invalid polynomial name.\n");
                continue;
            }
        }

        // Handle changing coefficients of polynomials
        else if(strcmp("change-coeff", cmd) == 0){
            int expo, ele;
            printf("Enter exponent and new coefficient: ");
            scanf("%d %d", &expo, &ele);
            getchar();  // Consume the newline character after scanf
            if(strcmp("poly1", user_poly) == 0)
                change_coeff(p1, expo, ele);  // Change coefficient of polynomial 1
            else if(strcmp("poly2", user_poly) == 0)
                change_coeff(p2, expo, ele);  // Change coefficient of polynomial 2
            else{
                printf("Invalid polynomial name or polynomial uninitialized.\n");
                continue;
            }
        }

        // Handle displaying polynomials
        else if(strcmp("display", cmd) == 0){
            if(strcmp("poly1", user_poly) == 0 && p1 != NULL)
                display(*p1);  // Display polynomial 1
            else if(strcmp("poly2", user_poly) == 0 && p2 != NULL)
                display(*p2);  // Display polynomial 2
            else if(strcmp("poly3", user_poly) == 0 && p3 != NULL)
                display(*p3);  // Display polynomial 3 (resultant polynomial)
            else{
                printf("Invalid polynomial name or polynomial uninitialized.\n");
                continue;
            }
        }

        // Handle adding polynomials (poly1 + poly2)
        else if(strcmp("add-poly", cmd) == 0 && p1 != NULL && p2 != NULL){
            // Free memory for the previous p3 before reassigning
            if (p3 != NULL) {
                free(p3->coef);
                free(p3);
            }
            p3 = add_poly(*p1, *p2);  // Store the result of addition in p3
        }

        // Handle subtracting polynomials (poly1 - poly2)
        else if(strcmp("sub-poly", cmd) == 0 && p1 != NULL && p2 != NULL){
            // Free memory for the previous p3 before reassigning
            if (p3 != NULL) {
                free(p3->coef);
                free(p3);
            }
            p3 = sub_poly(*p1, *p2);  // Store the result of subtraction in p3
        }

        // Handle invalid commands
        else{
            printf("Invalid Command Name.\n");
            continue;
        }
    }

    return 0;
}