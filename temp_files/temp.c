#include <stdio.h>
#include <stdlib.h>
// #include "doubly.h"

typedef struct node{
	int data;
	struct node* prev;
	struct node* next;
}node;

typedef struct DLL{
	struct node* front;
	struct node* rear;
}DLL;

void init(DLL *l);
int len(DLL l);
void append(DLL *l, int d);
int isEmpty(DLL *l);
void display(DLL *l);
void insert_beg(DLL *l, int d);
// void insert_end(DLL *l, int d);
void insert_pos(DLL *l, int pos, int d);
void remove_end(DLL *l);
void remove_beg(DLL *l);
void remove_pos(DLL *l, int pos);
void displayRL(DLL *l);
void displayLR(DLL *l);
void display_list_node(DLL l);

void init(DLL *l){
    l->front = NULL;
    l->rear = NULL;
    return;
}

int len(DLL l){
    int i = 0;
    node *p = l.front;
    while(p != NULL){
        p = p->next;
        i++;
    }
    return i;
}


void append(DLL *l, int d){
    node *nn = (node *)malloc(sizeof(node));  // Allocate memory for the new node
   
    nn->data = d;
    nn->prev = NULL;
    nn->next = NULL;
	node *q = l->rear;
    if (l->front == NULL) {  // List is empty
        l->front = nn;
        l->rear = nn;
    }
        else {
        q->next = nn;  // Attach the new node at the end
        nn->prev = q;
        l->rear = nn;
     }
     return;
}

void display(DLL *l){
	node *p;
	p = l->front;
	while (p != NULL){
		printf("%d ", p->data);
		p = p->next;
	}
    return;
}

void insert_beg(DLL *l, int d){
	node *nn = (node *)malloc(sizeof(node));
	node *p = l->front;
	if(nn){
		nn->data = d;
		nn->prev = NULL;
		nn->next = l->front; 
	}
  		if (l->front == NULL) {  // If the list is empty
        	l->front = nn;
		l->rear = nn;  
	}
		else{
		p->prev = nn;
		l->front = nn;
		}
	return;
} 

// void insert_end(DLL *l, int d){
// 	node *nn = (node *)malloc(sizeof(node));
	
// 	if(nn){
// 		nn->data = d;
// 		nn->next = NULL;
// 		nn->prev = l->rear;
// 	}
// 		if(l->rear == NULL){
// 			l->front = nn;
// 			l->rear = nn;
// 		}
// 		else{
// 			l->rear->next = nn;
// 			l->rear = nn;		
		// }
// 	return;
// }

int isEmpty(DLL *l) {
    return l->front == NULL;  // Returns 1 if empty, otherwise 0
}

void insert_pos(DLL *l, int pos, int d){
	node *nn = (node *)malloc(sizeof(node));
	if(nn){
		nn->data = d;
		nn->prev = NULL;
		nn->next = NULL;
	}
	
	node *p = l->front;
    	int i = 1;
    	
    	while (p != NULL && i < pos - 1) { 
        p = p->next;
        i++;
    	}
    	
	if (p == NULL) {  
        printf("Position out of bounds. Inserting at the end.\n");
        append(l, d);
    	}
    	else {
        nn->next = p->next;
        nn->prev = p;

        if (p->next != NULL) {  // Handle non-tail insertion
            p->next->prev = nn;
        } else {
            l->rear = nn;  // Update the rear if we're at the end
        }

        p->next = nn;
    }
	return;
}

void remove_beg(DLL *l){
    if (l->front == NULL) { 
        printf("The list is empty, nothing to remove.\n");
        return;
    }
	node* p = l->front;
    if(l->front == l->rear){
        l->front = l->rear = NULL;
    }
    else{
    	l->front = p->next;
        p->next->prev = NULL;
    }
	free(p);
	return;
}

void remove_end(DLL *l) {
    if (l->rear == NULL) { 
        printf("The list is empty, nothing to remove.\n");
        return;
    }

    node *p = l->rear;
    if (l->front == l->rear) { // If there's only one element in the list
        l->front = l->rear = NULL;
    } else {
        l->rear = p->prev;
        p->prev->next = NULL;
    }

    free(p);
    return;
}

void remove_pos(DLL *l, int pos){
    if (l->front == NULL) { 
        printf("The list is empty, nothing to remove.\n");
        return;
    }
    if(pos < 0 || pos >= len(*l)){
        return;
    }

	if(pos == 0){
		remove_beg(l);
		return;
	}

    if(pos == len(*l) - 1){
        remove_end(l);
        return;
    }

	int i = 0;
	node *p = l->front;
	node *q = NULL;
	while(i < pos){
		q = p;
		p = p->next;
		i++;
	}
	q->next = p->next;
    p->next->prev = q;
	free(p);
	return;
}

void displayLR(DLL *l) {
    node *p = l->front;
    if(!p) {
        return;
    }
    do {
        printf("%d ", p->data);
        p = p->next;
    }while(p != NULL);
}

void displayRL(DLL *l){
    node *p = l->rear;
    //printf("%d ", p->data);
    if(!p) {
        return;
    }
    while(p != NULL){
        printf("%d ", p->data);
        p = p->prev;
    }
}

void display_list_node(DLL l){
    if(l.front == NULL)
        return;
    node *p = l.front;
    int i = 0;
    while(p != NULL){
        printf("Node %d:\n\tData: %d\n\tPrevious Node Address: %p\n\tCurrent Node Address: %p\n\tNext Node Address: %p\n", i, p->data, p->prev, p, p->next);
        i++;
        p = p->next;
    }
    return;
}

int main(){
	DLL l;
	init(&l);
	append(&l, 8);
	append(&l, 9);
	append(&l, 2);
	
	printf("Append the elements: ");
	display(&l);
	printf("\n");
	
	insert_beg(&l, 4);
	printf("Display at the begining: ");
	display(&l);
	printf("\n");
	
	// insert_end(&l, 5);
	// printf("Insert at end: ");
	// display(&l);
	// printf("\n");
	
	isEmpty(&l);
	
	insert_pos(&l, 1, 2);
	printf("Insert at postion: ");
	display(&l);
	printf("\n");
	

	remove_beg(&l);
	printf("Remove a begining: ");
	display(&l);
	printf("\n");
	
    display_list_node(l);

	remove_end(&l);
	printf("Remove at end: ");
	display(&l);
	printf("\n");
	
	remove_pos(&l, 1);
	printf("Remove at postion: ");
	display(&l);
	printf("\n");
	
	append(&l, 9);
	append(&l, 5);
    display(&l);
	// displayLR(&l);
    printf("test0\n");
	displayRL(&l);
return 0;
}