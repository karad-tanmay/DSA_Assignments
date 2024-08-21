typedef struct timer{
    int hours;
    int mins;
    int secs;
}timer;

void init(timer *a, int hrs, int mins, int secs);
void display(timer a);
void display_msg();
int compare_time(timer start, timer end);
void timer_count(timer start, timer end);