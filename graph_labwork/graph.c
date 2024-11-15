#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

int get_index(char ch){
	return (int)ch - 97;
}

void initGraph(graph *g, int size){
	if(size <= 0)
		return;
	g->arr = (node**)calloc(size, sizeof(node*));
	g->size = size;
	return;
}

void insertEdge(graph *g, char start, char end, int weight){
	int start_in = get_index(start);
	// printf("start_in: %d\n", start_in);
	if(!(start_in >= 0 && start_in < g->size))
		return;
	// printf("test1\n");
	node *nn = (node*)malloc(sizeof(node));
	if(nn == NULL)
		return;
	nn->vertex = end;
	nn->edgeWeight = weight;
	nn->next = NULL;

	node *p = g->arr[start_in];
	if(p == NULL){
		g->arr[start_in] = nn;
		return;
	}
	while(p->next != NULL)
		p = p->next;
	p->next = nn;
	return;
}

void insertUndirectedEdge(graph *g, char start, char end, int weight){
	insertEdge(g, start, end, weight);
	insertEdge(g, end, start, weight);
	return;
}

void removeEdge(graph *g, char start, char end){
	int start_in = get_index(start);
	if(!(start_in >= 0 && start_in < g->size))
		return;
	node *p = g->arr[start_in], *q;
	while(p != NULL && p->vertex != end){
		q = p;
		p = p->next;
	}
	if(p == NULL)
		return;
	if(p == g->arr[start_in])
		g->arr[start_in] = p->next;
	else
		q->next = p->next;
	free(p);
	return;
}

void removeUndirectedEdge(graph *g, char start, char end){
	removeEdge(g, start, end);
	removeEdge(g, end, start);
	return;
}

void graphBFS(graph g, char start){
	int start_in = get_index(start);
	if(!(start_in >= 0 && start_in < g.size))
		return;
	int *visited = (int*)calloc(g.size, sizeof(int));
	int *queue = (int*)calloc(g.size, sizeof(int));
	int front = 0, rear = 0;
	printf("%c ", start);
	visited[start_in] = 1;
	queue[rear++] = start_in;
	while(front != rear){
		start_in = queue[front++];
		node *p = g.arr[start_in];
		while(p != NULL){
			int index = get_index(p->vertex);
			if(visited[index] == 0){
				printf("%c ", p->vertex);
				visited[index] = 1;
				queue[rear++] = index;
			}
			p = p->next;
		}
	}
	return;
}

void graphDFS(graph g, char start){
	int start_in = get_index(start);
	if(!(start_in >= 0 && start_in < g.size))
		return;
	int *visited = (int*)calloc(g.size, sizeof(int));
	int *stack = (int*)calloc(g.size, sizeof(int));
	int top = -1, flag = 0;
	printf("%c ", start);
	visited[start_in] = 1;
	stack[++top] = start_in;
	while(top != -1){
		int start_in = stack[top--];
		node *p = g.arr[start_in];
		if(flag)
			stack[++top] = start_in;
		flag = 0;
		while(p != NULL){
			int index = get_index(p->vertex);
			if(visited[index] == 0){
				flag = 1;
				printf("%c ", p->vertex);
				visited[index] = 1;
				stack[++top] = index;
				break;
			}
			p = p->next;
		}
	}
	return;
}

void displayGraph(graph g){
	node *p;
	for(int i = 0; i < g.size; i++){
		p = g.arr[i];
		printf("Edges of %c: ", i + 97);
		while(p != NULL){
			printf("%c ", p->vertex);
			p = p->next;
		}
		printf("\n");
	}
	return;
}

void deleteGraph(graph *g){
	for(int i = 0; i < g->size; i++){
		node *p = g->arr[i];
		while(p != NULL){
			g->arr[i] = p->next;
			free(p);
			p = g->arr[i];
		}
	}
	free(g->arr);
	g->size = 0;
	return;
}