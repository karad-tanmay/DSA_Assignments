#include<stdio.h>
#include<stdlib.h>
#include"polynomial.h"

// Function to initialize a polynomial with a specified degree
// Frees any previously allocated memory for the polynomial and its coefficients if not NULL
// Prompts the user to enter coefficients for the polynomial
polynomial* init(polynomial *p, int deg){
    if(p != NULL){
        free(p->coef);  // Free memory allocated for coefficients
        free(p);        // Free memory allocated for the polynomial structure
        p = NULL;
    }
    polynomial *p_tp = NULL;
    if(deg >= 0){  // Check if degree is non-negative
        p_tp = (polynomial *)malloc(sizeof(polynomial));  // Allocate memory for the polynomial
        p_tp->degree = deg;
        p_tp->coef = (int *)malloc((deg + 1) * sizeof(int));  // Allocate memory for coefficients
        int temp;
        for(int i = p_tp->degree; i >= 0; i--){  // Loop to input coefficients
            printf("Enter Coefficient for exponent %d: ", i);
            scanf("%d", &temp);
            getchar();
            p_tp->coef[i] = temp;  // Store the coefficient
        }
    }
    return p_tp;
}

// Function to display a polynomial in a readable format
// Displays the polynomial with correct signs and exponents
void display(polynomial p){
    int flag;
    // For the highest exponent (degree)
    if(p.coef[p.degree] > 0){
        printf("%dx^%d ", p.coef[p.degree], p.degree);
        flag = 1;
    }
    else if(p.coef[p.degree] < 0){
        printf("- %dx^%d ", -1 * p.coef[p.degree], p.degree);
        flag = 1;
    }

    // For exponents from (degree - 1) to 2
    for(int i = p.degree - 1; i > 1; i--){
        if(p.coef[i] > 0){
            printf("+ %dx^%d ", p.coef[i], i);
            flag = 1;
        }
        else if(p.coef[i] < 0){
            printf("- %dx^%d ", -1 * p.coef[i], i);
            flag = 1;
        }
    }

    // For exponent 1
    if(p.degree > 1){
        if(p.coef[1] > 0){
            printf("+ %dx ", p.coef[1]);
            flag = 1;
        }
        else if(p.coef[1] < 0){
            printf("- %dx ", -1 * p.coef[1]);
            flag = 1;
        }
    }

    // For exponent 0 (constant term)
    if(p.degree > 0){
        if(p.coef[0] > 0){
            printf("+ %d ", p.coef[0]);
            flag = 1;
        }
        else if(p.coef[0] < 0){
            printf("- %d ", -1 * p.coef[0]);
            flag = 1;
        }
    }

    if(flag == 1)
        printf("= 0\n");

    return;
}

// Function to change a specific coefficient of the polynomial
// Takes the exponent and the new coefficient as arguments
void change_coeff(polynomial *p, int expo, int coeff){
    if(expo >= 0 && expo <= p->degree){
        p->coef[expo] = coeff;  // Modify the coefficient for the given exponent
    }
    return;
}

// Function to add two polynomials and return the result as a new polynomial
polynomial* add_poly(polynomial p1, polynomial p2){
    int temp, i;
    polynomial *p = (polynomial *)malloc(sizeof(polynomial));
    if(p1.degree > p2.degree){  // Determine the highest degree between the two polynomials
        p->degree = p1.degree;
        temp = p2.degree;
    }
    else{
        p->degree = p2.degree;
        temp = p1.degree;
    }
    p->coef = (int *)malloc(sizeof(int) * (p->degree + 1));  // Allocate memory for coefficients
    for(i = 0; i <= temp; i++)
        p->coef[i] = p1.coef[i] + p2.coef[i];  // Add corresponding coefficients
    for(i = temp + 1; i <= p1.degree; i++)
        p->coef[i] = p1.coef[i];  // Copy remaining coefficients from p1
    for(i = temp + 1; i <= p2.degree; i++)
        p->coef[i] = p2.coef[i];  // Copy remaining coefficients from p2
    return p;
}

// Function to subtract one polynomial from another and return the result as a new polynomial
polynomial* sub_poly(polynomial p1, polynomial p2){
    polynomial *p = (polynomial *)malloc(sizeof(polynomial));
    int temp, i;
    if(p1.degree > p2.degree){  // Determine the highest degree between the two polynomials
        p->degree = p1.degree;
        temp = p2.degree;
    }
    else{
        p->degree = p2.degree;
        temp = p1.degree;
    }
    p->coef = (int *)malloc(sizeof(int) * (p->degree + 1));  // Allocate memory for coefficients
    for(i = 0; i <= temp; i++)
        p->coef[i] = p1.coef[i] - p2.coef[i];  // Subtract corresponding coefficients
    for(i = temp + 1; i <= p1.degree; i++)
        p->coef[i] = p1.coef[i];  // Copy remaining coefficients from p1
    for(i = temp + 1; i <= p2.degree; i++)
        p->coef[i] = -1 * p2.coef[i];  // Copy remaining coefficients from p2 with sign negated
    return p;
}