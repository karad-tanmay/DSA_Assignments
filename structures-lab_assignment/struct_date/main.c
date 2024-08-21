#include <stdio.h>
#include "date.h"

int main(){
    date a;
    int day, mon, year;
    printf("Enter day, month, year: ");
    scanf("%d %d %d", &day, &mon, &year);
    init(&a, day, mon, year);
    if(is_valid(a) > 0)
        display(a);
    else
        printf("invalid date");
    return 0;
}