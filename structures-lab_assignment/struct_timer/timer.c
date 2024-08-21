#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include "timer.h"

void init(timer *a, int hrs, int mins, int secs){
    a->hours = hrs;
    a->mins = mins;
    a->secs = secs;
    return;
}

void display(timer a){
    printf("%dhrs %dmins %dsecs\n", a.hours, a.mins, a.secs);
    return;
}

void display_msg(){
    printf("   _____                 _   _____                _ _ \n");
    printf("  / ____|               | | |  __ \               | | |\n");
    printf(" | |  __  ___   ___   __| | | |  | | __ _ _   _  | | |\n");
    printf(" | | |_ |/ _ \ / _ \ / _` | | |  | |/ _` | | | | | | |\n");
    printf(" | |__| | (_) | (_) | (_| | | |__| | (_| | |_| | |_|_|\n");
    printf("  \ _____|\ ___/ \ ___/ \ __,_| |_____/ \ __,_|\ __, | (_|_)\n");
    printf("                                           __/ |      \n");
    printf("                                          |___/      \n");
    return;
}

int compare_time(timer start, timer end) {
    if (start.hours > end.hours)
        return 1;
    else if (start.hours == end.hours) {
        if (start.mins > end.mins)
            return 1;
        else if (start.mins == end.mins) {
            if (start.secs >= end.secs)
                return 1;
        }
    }
    return 0;
}

void timer_count(timer start, timer end){
    while(!compare_time(start, end)){
        start.secs++;
        if(start.secs == 60){
            start.mins++;
            start.secs = 0;
        }
        if(start.mins == 60){
            start.hours++;
            start.mins = 0;
        }
        system("cls");
        display_msg();
        printf("Present Time: ");
        display(start);
        printf("End Time: ");
        display(end);
        Sleep(1000);
    }
    system("cls");
    return;
}