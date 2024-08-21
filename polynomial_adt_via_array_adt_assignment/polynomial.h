// Structure definition for a polynomial
typedef struct polynomial {
    int degree;    // Degree of the polynomial
    int *coef;     // Pointer to an array holding the coefficients of the polynomial
} polynomial;

// Function prototype to initialize a polynomial with a specified degree
// Takes a pointer to a polynomial and an integer representing the degree
// Returns a pointer to the initialized polynomial
polynomial* init(polynomial *p, int degree);

// Function prototype to display a polynomial
// Takes a polynomial as an argument and prints it in a readable format
void display(polynomial p);

// Function prototype to change a specific coefficient of the polynomial
// Takes a pointer to a polynomial, the exponent, and the new coefficient as arguments
void change_coeff(polynomial *p, int expo, int coeff);

// Function prototype to add two polynomials
// Takes two polynomials as arguments and returns a pointer to a new polynomial representing the sum
polynomial* add_poly(polynomial p1, polynomial p2);

// Function prototype to subtract one polynomial from another
// Takes two polynomials as arguments and returns a pointer to a new polynomial representing the difference
polynomial* sub_poly(polynomial p1, polynomial p2);