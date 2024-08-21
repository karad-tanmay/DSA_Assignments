#include <stdio.h>
#include <stdlib.h>
#include "array.h"

// Function to initialize an array with a given size
array* init(array *a, int size){
    // Free existing array memory if not NULL
    if(a != NULL){
        free(a->A);
        free(a);
        a = NULL;
    }
    array *a_tp = NULL;
    // Allocate memory for a new array if size is positive
    if(size > 0){
        a_tp = (array *)malloc(sizeof(array));
        a_tp->A = (int *)malloc(size * sizeof(int));
        a_tp->length = 0;  // Initialize length to 0
        a_tp->size = size; // Set the size of the array
    }
    return a_tp;
}

// Function to append an element to the end of the array
void append(array *a, int x){
    // Check if there is space in the array to append the new element
    if(a->length < a->size){
        a->A[a->length++] = x;  // Add the element and increase length
    }
    return;
}

// Function to insert an element at a specified index in the array
void insert_at_index(array *a, int x, int index){
    // Check if index is within bounds and there is space to insert the element
    if(index >= 0 && index < a->length && a->length < a->size){
        // Shift elements to the right to make space for the new element
        for(int i = a->length; i > index; i--)
            a->A[i] = a->A[i - 1];
        a->A[index] = x;  // Insert the new element
        a->length++;      // Increase the length of the array
    }
    return;
}

// Function to remove an element from a specified index in the array
void remove_at_index(array *a, int index){
    // Check if index is within bounds
    if(index >= 0 && index < a->length){
        // Shift elements to the left to fill the gap
        for(int i = index; i < a->length - 1; i++)
            a->A[i] = a->A[i + 1];
        a->length--;  // Decrease the length of the array
    }
    return;
}

// Function to display all elements of the array
void display(array a){
    // Print each element followed by a space
    for(int i = 0; i < a.length; i++)
        printf("%d ", a.A[i]);
    printf("\n");  // Print a newline at the end
    return;
}

// Function to find the maximum value in the array
int max(array a){
    int max = a.A[0];  // Assume the first element is the maximum
    for(int i = 0; i < a.length; i++){
        if(max < a.A[i])
            max = a.A[i];  // Update max if a larger value is found
    }
    return max;
}

// Function to find the minimum value in the array
int min(array a){
    int min = a.A[0];  // Assume the first element is the minimum
    for(int i = 0; i < a.length; i++){
        if(min > a.A[i])
            min = a.A[i];  // Update min if a smaller value is found
    }
    return min;
}

// Function to reverse the elements of the array
void reverse(array *a){
    int temp;
    // Swap elements from the start and end towards the center
    for(int i = 0, j = a->length - 1; i <= j; i++, j--){
        temp = a->A[i];
        a->A[i] = a->A[j];
        a->A[j] = temp;
    }
    return;
}

// Function to merge two arrays into a new array
array* merge(array a, array b){
    array *c = (array *)malloc(sizeof(array));  // Allocate memory for the merged array
    init(c, a.size + b.size);  // Initialize the merged array with combined size
    // Copy elements from the first array
    for(int i = 0; i < a.length; i++)
        c->A[c->length++] = a.A[i];
    // Copy elements from the second array
    for(int i = 0; i < b.length; i++)
        c->A[c->length++] = b.A[i];
    return c;
}