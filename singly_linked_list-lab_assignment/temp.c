#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define min(a, b) ((a < b) ? a : b)

// Definition of the node and list types
typedef struct node {
    int data;
    struct node *next;
} node;

typedef node* list;

// Function prototypes
void init(list *l);
void append(list *l, int x);
void display(list l);
// void traverse(list l); same as display
void insert_at_beg(list *l, int x);
int remove_at_pos(list *l, int pos);
int len(list l);
void swap(node *n1, node *n2);
void sort_list(list *l);


int main() {
    list l;

    // Initialize the list
    init(&l);  // Pass the address of the list pointer

    // Append data to the list
    append(&l, 10);
    // append(&l, 10);
    append(&l, 20);
    // append(&l, 10);
    // append(&l, 10);
    // append(&l, 20);
    append(&l, 30);
    insert_at_beg(&l, 15);
    // Dislay the list
    display(l);
    // printf("%d\n", remove_at_pos(&l, 2));
    sort_list(&l);
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

// void swapNodes(node **head, int val1, int val2) {
//     // if (val1 == val2) return;

//     // Find prev1, curr1 (node with val1) and prev2, curr2 (node with val2)
//     node *prev1 = NULL, *curr1 = *head;
//     while (curr1 && curr1->data != val1) {
//         prev1 = curr1;
//         curr1 = curr1->next;
//     }

//     node *prev2 = NULL, *curr2 = *head;
//     while (curr2 && curr2->data != val2) {
//         prev2 = curr2;
//         curr2 = curr2->next;
//     }

//     // If either val1 or val2 is not found, return
//     if (!curr1 || !curr2) return;

//     // Update previous nodes' next pointers
//     if (prev1) {
//         prev1->next = curr2;
//     } else {
//         *head = curr2;  // If val1 is head
//     }

//     if (prev2) {
//         prev2->next = curr1;
//     } else {
//         *head = curr1;  // If val2 is head
//     }

//     // Swap the next pointers of curr1 and curr2
//     node *temp = curr1->next;
//     curr1->next = curr2->next;
//     curr2->next = temp;
// }

// void swap(node *n1, node *n2){
//     printf("test9\n");
//     node *temp = (node *)malloc(sizeof(temp));
//     // *temp = *n1;
//     // *n1 = *n2;
//     // *n2 = *temp;
//     temp->next = n1->next;
//     temp->data = n1->data;
//     n1->next = n2->next;
//     n1->data = n2->data;
//     n2->data = temp->data;
//     n2->next = temp->next;
//     free(temp);
//     printf("test10\n");
//     return;
// }

// void sort_list(list *l){
//     node *p = *l, *q = *l, *r = NULL;
//     int minl = 0, temp;
//         printf("test2\n");
//     while(q != NULL){
//         printf("test3\n");
//         minl = INT_MAX;
//         p = q;
//         while(p != NULL){
//             printf("test4\n");
//             temp = minl;
//             minl = min(minl, p->data);
//             printf("test5\n");
//             if(temp > minl){
//                 printf("Test8\n");
//                 r = p;
//             }
//             printf("test6\n");
//             p = p->next;
//             printf("test7\n");
//         }
//         printf("test0\n");
//         swap(q, r);
//         // swapNodes(l, q->data, r->data);
//         printf("test1\n");
//         l = &q;
//         q = r->next;
//     }
//     return;
// }

// void swap(node *prev1, node *prev2){
//     printf("test9\n");
//     node *n1 = prev1->next;
//     node *n2 = prev2->next;
//     printf("test11\n");
//     prev1->next = n2;
//     prev2->next = n1;
//     node *temp = n2->next;
//     n2->next = n1->next;
//     n1->next = temp;
//     printf("test10\n");
//     return;
// }



// void sort_list(list *l){
//     node *p = *l, *q = *l, *r = NULL;
//     int minl = 0;
//         printf("test2\n");
//     while(q != NULL){
//         printf("test3\n");
//         minl = q->data;
//         p = q->next;
//         while(p->next != NULL){
//             printf("test4\n");
//             printf("test5\n");
//             if(minl > p->next->data){
//                 minl = p->data;
//                 printf("Test8\n");
//                 r = p;
//             }
//             printf("test6\n");
//             p = p->next;
//             printf("test7\n");
//         }
//         printf("test0\n");;
//         if(q == *l){
//             swap(*l, r);
//             q = *l;
//             q = q->next;
//         }
//         else{
//             swap(q, r);
//             q = r->next;
//         }
//         printf("test1\n");
//     }
//     return;
// }