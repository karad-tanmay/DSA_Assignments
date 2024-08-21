#include "student.h"
#include <stdio.h>
#include <string.h>
#define LIST_SIZE 5

int main(){
    student list[LIST_SIZE];

    init(&list[0], 612303001, "John", "Michael", "Doe", 'M', 15, 8, 2002, 85, 90, 88);
    init(&list[1], 612303002, "Alice", "Marie", "Smith", 'F', 22, 11, 2003, 38, 25, 45);
    init(&list[2], 612303003, "Robert", "James", "Brown", 'M', 9, 3, 2001, 76, 80, 83);
    init(&list[3], 612303004, "Emily", "Rose", "Johnson", 'F', 30, 5, 2004, 89, 91, 87);
    init(&list[4], 612303005, "David", "Andrew", "Williams", 'M', 18, 12, 2002, 55, 40, 10);

    char temp[128];
    printf("Enter FirstName of Student (in Titlecase): ");
    scanf("%s", temp);
    get_record(list, LIST_SIZE, temp);

    display_if_fail(list, LIST_SIZE);
    return 0;
}