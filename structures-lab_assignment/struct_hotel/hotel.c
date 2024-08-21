#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hotel.h"

void init(hotel *list, char *name, char* address, int grade, int num_rooms, int charge){
    strcpy(list->name, name);
    strcpy(list->address, address);
    list->grade = grade;
    list->num_rooms = num_rooms;
    list->room_charges = charge;
    return;
}

void get_by_grade(hotel *list, int list_size, int grade){
    for(int i = 0; i < list_size; i++){
        if(list[i].grade == grade)
            printf("%s\n", list[i].name);
    }
    return;
}

void get_by_charge(hotel *list, int list_size, int charge){
    for(int i = 0; i < list_size; i++){
        if(list[i].room_charges <= charge)
            printf("%s\n", list[i].name);
    }
    return;
}