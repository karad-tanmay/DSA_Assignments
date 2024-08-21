#include <stdio.h>
#include "fraction.h"

void init(fraction *a, int nume, int denom){
    a->nume = nume;
    a->denom = denom;
    return;
}

void display(fraction a){
    printf("%d/%d\n", a.nume, a.denom);
    return;
}

int cmp_fraction(fraction a, fraction b){
    float tp1, tp2;
    tp1 = ((float)a.nume/(float)a.denom);
    tp2 = ((float)b.nume/(float)b.denom);
    if(tp1 > tp2)
        return 1;
    else if(tp1 < tp2)
        return -1;
    else
        return 0;
}