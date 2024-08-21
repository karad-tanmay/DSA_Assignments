#include <stdio.h>
#include "timer.h"

int main(){
    timer start, end;
    int hrs, mins, secs;
    printf("Enter start time(hrs, mins, secs): ");
    scanf("%d %d %d", &hrs, &mins, &secs);
    init(&start, hrs, mins, secs);

    printf("Enter end time(hrs, mins, secs) (> start time): ");
    scanf("%d %d %d", &hrs, &mins, &secs);
    init(&end, hrs, mins, secs);

    if (start.hours < 0 || start.hours >= 24 || start.mins < 0 || start.mins >= 60 || start.secs < 0 || start.secs >= 60 ||
        end.hours < 0 || end.hours >= 24 || end.mins < 0 || end.mins >= 60 || end.secs < 0 || end.secs >= 60) {
        printf("Invalid time input.\n");
        return 1;
    }

    display(start);
    display(end);

    timer_count(start, end);
    return 0;
}