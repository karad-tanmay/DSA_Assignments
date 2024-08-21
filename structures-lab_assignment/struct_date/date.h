typedef struct date{
    int day;
    int month;
    int year;
}date;

void init(date *a, int day, int month, int year);
void display(date a);
int is_valid(date a);