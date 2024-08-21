#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hotel.h"
#define LIST_SIZE 5

int main(){
    hotel list[LIST_SIZE];
    init(&list[0], "ABC INN", "ABC Square", 1, 15, 500);
    init(&list[1], "XYZ INN", "XYZ Square", 2, 15, 1000);
    init(&list[2], "Tiptop International", "ABC Road", 1, 15, 600);
    init(&list[3], "MNO Hotel", "ABC Station", 2, 15, 1200);
    init(&list[4], "JW Mariott", "XYZ Road", 3, 15, 2500);

    int temp;
    printf("Enter Hotel Grade(1-3): ");
    scanf("%d", &temp);
    get_by_grade(list, LIST_SIZE, temp);

    printf("Enter Hotel Charge(1-3): ");
    scanf("%d", &temp);
    get_by_charge(list, LIST_SIZE, temp);

    return 0;
}