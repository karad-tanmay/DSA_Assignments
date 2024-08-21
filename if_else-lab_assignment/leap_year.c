#include <stdio.h>

int main() {
    int year;
    printf("Enter a year: ");
    scanf("%d", &year);

    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        printf("Year is a Leap Year\n");
    else
        printf("Year is not a Leap Year\n");

    return 0;
}
