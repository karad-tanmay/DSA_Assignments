#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

void init(graph *g, int size){
	if(size <= 0)
		return;
	g->size = size;
	g->arr = (AdjListNode**)calloc(size, sizeof(AdjListNode*));
	return;
}

void insertEdge(graph *g, int start, int dest, int edgeWeight){
	if(start >= g->size && dest >= g->size)
		return;
	AdjListNode *nn = (AdjListNode*)malloc(sizeof(AdjListNode));
	if(!nn)
		return;
	nn->destVertex = dest;
	nn->edgeWeight = edgeWeight;
	nn->next = g->arr[start];
	g->arr[start] = nn;
	return;
}

void displayGraph(graph g){
	AdjListNode *p;
	for(int i = 0; i < g.size; i++){
		p = g.arr[i];
		printf("Edges of %d: ", i);
		while(p != NULL){
			printf("%d ", p->destVertex);
			p = p->next;
		}
		printf("\n");
	}
	return;
}

void graphBFS(graph g, int start){
	if(start >= g.size)
		return;
	int *visited = (int*)calloc(g.size, sizeof(int));
	int *queue = (int*)calloc(g.size, sizeof(int));
	int front = 0, rear = 0;
	queue[rear++] = start;
	int curr = start;
	AdjListNode *p;
	printf("%d ", curr);
	visited[curr] = 1;
	while(front != rear){
		curr = queue[front++];
		p = g.arr[curr];
		while(p != NULL){
			if(visited[p->destVertex] == 0){
				queue[rear++] = p->destVertex;
				printf("%d ", p->destVertex);
				visited[p->destVertex] = 1;
			}
			p = p->next;
		}
	}
	free(queue);
	free(visited);
	return;
}

void graphDFS(graph g, int start){
	if(start >= g.size)
		return;
	int *visited = (int*)calloc(g.size, sizeof(int));
	int *stack = (int*)calloc(g.size, sizeof(int));
	int top = -1, curr = start;
	AdjListNode *p;
	stack[++top] = start;
	printf("%d ", curr);
	visited[curr] = 1;
	while(top != -1){
		p = g.arr[curr];
		while(p != NULL){
			if(visited[p->destVertex] == 0){
				stack[++top] = curr;
				curr = p->destVertex;
				printf("%d ", curr);
				visited[curr] = 1;
				break;
			}
			p = p->next;
		}
		if(p == NULL)
			curr = stack[top--];
	}
	free(visited);
	free(stack);
	return;
}

void freeGraph(graph *g){
	AdjListNode *p;
	for(int i = 0; i < g->size; i++){
		p = g->arr[i];
		while(p != NULL){
			g->arr[i] = p->next;
			free(p);
			p = g->arr[i];
		}
	}
	free(g->arr);
	g->arr = NULL;
	g->size = 0;
	return;
}