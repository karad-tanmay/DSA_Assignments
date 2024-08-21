#include <stdio.h>
#include "date.h"

void init(date *a, int day, int month, int year){
    a->day = day;
    a->month = month;
    a->year = year;
    return;
}

void display(date a){
    printf("%d/%d/%d\n", a.day, a.month, a.year);
    return;
}

int is_leap(int year){
    int leap_flag = 0;
    if(year % 4 == 0){
        if(year % 100 == 0){
            if(year % 400 == 0)
                leap_flag = 1;
            else
                leap_flag = -1;
        }
        else
            leap_flag = 1;
    }
    else
        leap_flag = -1;

    return leap_flag;
}

int is_valid(date a){
    int valid = -1;
    if(a.day > 0 && a.month > 0 && a.year > 0){
        int leap_flag = is_leap(a.year);
        if(a.month == 1 || a.month == 3 || a.month == 5 || a.month == 7 || a.month == 8 || a.month == 10 || a.month == 12){
            if(a.day <= 31)
                valid = 1;
        }
        else if(a.month == 4 || a.month == 6 || a.month == 5 || a.month == 9 || a.month == 11){
            if(a.day <= 30)
                valid = 1;
        }
        else if(a.month == 2){
            if(leap_flag == 1){
                if(a.day <= 29)
                    valid = 1;
            }
            else{
                if(a.day <= 28)
                    valid = -1;
            }
        }
    }
    return valid;
}