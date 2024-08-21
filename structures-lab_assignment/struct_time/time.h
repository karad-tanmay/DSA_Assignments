typedef struct time{
    int hours;
    int mins;
    int secs;
}time;

void init(time *a, int hrs, int mins, int secs);
void display(time a);
time* add_time(time a, time b);
time* sub_time(time a, time b);