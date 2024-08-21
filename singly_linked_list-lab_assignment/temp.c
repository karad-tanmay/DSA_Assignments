#include <stdio.h>
#include <stdlib.h>

// Definition of the node and list types
typedef struct node {
    int data;
    struct node *next;
} node;

typedef node *list;

// Function prototypes
void init(list *l);
void append(list *l, int x);
void display(list l);
// void traverse(list l); same as display
void insert_at_beg(list *l, int x);
int remove_at_pos(list *l, int pos);
int len(list l);

int main() {
    list l; 

    // Initialize the list
    init(&l);  // Pass the address of the list pointer

    // Append data to the list
    append(&l, 10);
    append(&l, 20);
    insert_at_beg(&l, 15);
    // Dislay the list
    display(l);
    printf("%d\n", remove_at_pos(&l, 2));
    display(l);
    printf("%d\n", len(l));
    // to free allocated memory
    node *p;
    while(l != NULL){
        p = l->next;
        free(l);
        l = p;
    }

    return 0;
}

// Initialize the list to NULL
void init(list *l) {
    *l = NULL;
}

// Append a new node with data x to the list
void append(list *l, int x) {
    node *nn = (node *)malloc(sizeof(node));
    nn->data = x;
    nn->next = NULL;

    if (*l == NULL) {
        *l = nn;
    } else {
        node *p = *l;
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = nn;
    }
}

// Dislay the contents of the list
void display(list l) {
    node *p = l;
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");  // Add a newline at the end for better formatting
}

// void traverse(list l);
void insert_at_beg(list *l, int x){
    node *nn = (node *)malloc(sizeof(node));
    nn->data = x;
    nn->next = *l;
    *l = nn;
    return;
}
int remove_at_pos(list *l, int pos){
    node *p = *l, *q;
    int i = 1;
    while(i < pos - 1){
        p = p->next;
        i++;
    }
    q = p;
    p = p->next;
    q->next = p->next;
    return p->data;
}

int len(list l){
    int i = 0;
    node *p = l;
    while(p != NULL){
        p = p->next;
        i++;
    }
    return i;
}