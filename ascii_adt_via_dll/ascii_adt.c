#include <stdio.h>
#include <stdlib.h>
#include "ascii_adt.h"

void init_ASCII(DLL *l)
{
    l->front = NULL;
    l->rear = NULL;
    return;
}

int isEmpty(DLL l)
{
    return (l.front == NULL);
}

void ASCII_of(char c, DLL *l)
{
    int ascii_val = (int)c;
    while (ascii_val > 0)
    {
        insert_at_beg(l, ascii_val % 10);
        ascii_val /= 10;
    }
    return;
}

void traverse(DLL l)
{
    if (isEmpty(l))
        return;
    node *p = l.front;
    while (p != NULL)
    {
        printf("%d", p->data);
        p = p->next;
    }
    printf("\n");
    return;
}

void insert_at_beg(DLL *l, int x)
{
    node *nn = (node *)malloc(sizeof(node));
    nn->data = x;
    nn->prev = NULL;
    nn->next = NULL;
    if (isEmpty(*l))
    {
        l->front = nn;
        l->rear = nn;
        return;
    }
    node *p = l->front;
    p->prev = nn;
    l->front = nn;
    nn->next = p;
    return;
}

void destroy(DLL *l)
{
    if (isEmpty(*l))
        return;
    node *p = l->front;
    while (p != NULL)
    {
        l->front = p->next;
        free(p);
        p = l->front;
    }
    l->front = NULL;
    l->rear = NULL;
}