#include <stdio.h>
#include <string.h>
#include "student.h"

void init(student *list, long long rollno, char *fn, char *mn, char *ln, char gen, int day, int mon, int year, int cs, int eng, int math){
    list->rollno = rollno;
    strcpy(list->name.firstname, fn);
    strcpy(list->name.middlename, mn);
    strcpy(list->name.lastname, ln);
    list->gender = gen;
    list->date.day = day;
    list->date.month = mon;
    list->date.year = year;
    list->marks.cs = cs;
    list->marks.eng = eng;
    list->marks.math = math;
    return;
}

void display_data(student *list, int i){
    printf("Student Record:\n");
    printf("    Name: %s %s %s.\n", list[i].name.firstname, list[i].name.middlename, list[i].name.lastname);
    printf("    MIS no.: %lli.\n", list[i].rollno);
    printf("    Date of Birth: %d/%d/%d.\n", list[i].date.day, list[i].date.month, list[i].date.year);
    printf("    Gender: %c.\n", list[i].gender);
    printf("    Academic Record:\n");
    printf("        English: %d.\n", list[i].marks.eng);
    printf("        Mathematics: %d.\n", list[i].marks.math);
    printf("        Computer Science: %d.\n", list[i].marks.cs);
    return;
}

void get_record(student *list, int list_size, char *name){
    for(int i = 0; i < list_size; i++){
        if(strcmp(list[i].name.firstname, name) == 0){
            display_data(list, i);
        }
    }
    return;
}

void display_if_fail(student *list, int list_size){
    float temp;
    for(int i = 0; i < list_size; i++){
        temp = (float)(list[i].marks.eng + list[i].marks.math + list[i].marks.cs) / 300;
        if(temp < 0.4)
            printf("\n%s %s %s (aggregate below 40%).", list[i].name.firstname, list[i].name.middlename, list[i].name.lastname);
    }
    return;
}