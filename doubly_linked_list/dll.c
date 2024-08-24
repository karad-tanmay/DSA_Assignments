#include <stdio.h>
#include <stdlib.h>
#include "dll.h"

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void init(DLL *l){
    l->front = NULL;
    l->rear = NULL;
    return;
}

void isEmpty(DLL l){
    return (l.front == NULL);
}

int len(DLL l){
    node *p = l.front;
    int i = 0;
    while(p != NULL){
        i++;
        p = p->next;
    }
    return i;
}

// display funcs-
void display(DLL l);
void display_list_node(DLL l);
void display_node(node n, char *var_name);

// insert funcs-
void append(DLL *l, int x);
void insert_at_pos(DLL *l, int x, int index);
void insert_at_beg(DLL *l, int x);

// remove funcs-
int remove_at_beg(DLL *l);
int remove_at_pos(DLL *l, int index);
int remove_at_end(DLL *l);

int lin_search(DLL l, int x);
void sort_list(DLL *l);
int isPalindrome(DLL l);
void remove_dupl(DLL *l);

void free_list(DLL *l);