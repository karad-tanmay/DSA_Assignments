#include <stdio.h>
#define MAX_SIZE 128

typedef struct Name{
    char firstname[MAX_SIZE];
    char middlename[MAX_SIZE];
    char lastname[MAX_SIZE];
}Name;

typedef struct DOB{
    int day;
    int month;
    int year;
}DOB;

typedef struct Marks{
    int eng;
    int math;
    int cs;
}Marks;

typedef struct student{
    long long rollno;
    Name name;
    char gender;
    DOB date;
    Marks marks;
}student;

void init(student *list, long long rollno, char *fn, char *mn, char *ln, char gen, int day, int mon, int year, int cs, int eng, int math);
void display_data(student *list, int i);
void get_record(student *list, int list_size, char *name);
void display_if_fail(student *list, int list_size);