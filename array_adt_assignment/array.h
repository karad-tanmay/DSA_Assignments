// Definition of the array structure
typedef struct array
{
    int *A;     // Pointer to the dynamically allocated array
    int length; // Number of elements currently in the array
    int size;   // Maximum capacity of the array
} array;

// Function prototypes

// Function to initialize an array with a given size
array *init(array *a, int size);

// Function to append an element at the end of the array
void append(array *a, int x);

// Function to insert an element at a specified index in the array
void insert_at_index(array *a, int x, int index);

// Function to remove an element from a specified index in the array
void remove_at_index(array *a, int index);

// Function to display all elements of the array
void display(array a);

// Function to find the maximum value in the array
int max(array a);

// Function to find the minimum value in the array
int min(array a);

// Function to reverse the elements of the array
void reverse(array *a);

// Function to merge two arrays into a new array
array *merge(array a, array b);