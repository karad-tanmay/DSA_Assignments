#include <stdio.h>
#include <stdlib.h>
#include "time.h"

void init(time *a, int hrs, int mins, int secs){
    a->hours = hrs;
    a->mins = mins;
    a->secs = secs;
    return;
}

void display(time a){
    printf("%dhrs %dmins %dsecs\n", a.hours, a.mins, a.secs);
    return;
}

time* add_time(time a, time b){
    time *tp = malloc(sizeof(time));
    tp->hours = a.hours + b.hours;
    tp->mins = a.mins + b.mins;
    tp->secs = a.secs + b.secs;
    if(tp->secs >= 60){
        tp->mins++;
        tp->secs -= 60;
    }
    if(tp->mins >= 60){
        tp->hours++;
        tp->mins -= 60;
    }
    return tp;
}

time* sub_time(time a, time b){
    time *tp = malloc(sizeof(time));
    tp->hours = a.hours - b.hours;
    tp->mins = a.mins - b.mins;
    tp->secs = a.secs - b.secs;
    if(tp->secs < 0){
        tp->mins--;
        tp->secs += 60;
    }
    if(tp->mins < 0){
        tp->hours--;
        tp->mins += 60;
    }
    return tp;
}