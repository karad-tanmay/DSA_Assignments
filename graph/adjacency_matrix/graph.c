#include <stdio.h>
#include <stdlib.h>
#include "../../queue_adt/using_two_stacks/queue.c"
#include "graph.h"

void initGraph(graph *g, int size){
	if(size <= 0)
		return;
	size++;
	g->adjMatrix = (int**)malloc(size * sizeof(int*));
	if(g->adjMatrix == NULL)
		return;
	for(int i = 0; i < size; i++){
		g->adjMatrix[i] = (int*)calloc(size, sizeof(int));
		if(g->adjMatrix[i] == NULL){
			i--;
			for(; i >= 0; i--)
				free(g->adjMatrix[i]);
			free(g->adjMatrix);
			g->adjMatrix = NULL;
			return;
		}
	}
	g->numVertices = size;
	return;
}

void insertEdge(graph *g, int start, int end, int weight){
	if(start >= g->numVertices || end >= g->numVertices)
		return;
	g->adjMatrix[start][end] = weight;
	return;
}

void insertUndirectedEdge(graph *g, int start, int end, int weight){
	insertEdge(g, start, end, weight);
	insertEdge(g, end, start, weight);
	return;
}

void removeEdge(graph *g, int start, int end){
	if(start >= g->numVertices || end >= g->numVertices)
		return;
	g->adjMatrix[start][end] = 0;
	return;
}

void removeUndirectedEdge(graph *g, int start, int end){
	removeEdge(g, start, end);
	removeEdge(g, end, start);
	return;
}

void graphBFS(graph g, int start){
	if(start >= g.numVertices)
		return;
	int *visited = (int*)calloc(g.numVertices, sizeof(int));
	queue q;
	initQueue(&q);
	printf("%d ", start);
	visited[start] = 1;
	enqueue(&q, start);
	while(!isEmptyQueue(q)){
		start = dequeue(&q);
		for(int i = 0; i < g.numVertices; i++){
			if(g.adjMatrix[start][i] > 0 && visited[i] == 0){
				printf("%d ", i);
				visited[i] = 1;
				enqueue(&q, i);
			}
		}
	}
	return;
}

void graphDFS(graph g, int start){ //iterative
	if(start >= g.numVertices)
		return;
	int *visited = (int*)calloc(g.numVertices, sizeof(int));
	int flag = 0;
	stack s;
	initStack(&s);
	printf("%d ", start);
	visited[start] = 1;
	push(&s, start);
	while(!isEmptyStack(s)){
		start = pop(&s);
		if(flag)
			push(&s, start);
		flag = 0;
		for(int i = 0; i < g.numVertices; i++){
			if(g.adjMatrix[start][i] > 0 && visited[i] == 0){
				printf("%d ", i);
				visited[i] = 1;
				push(&s, i);
				flag = 1;
				break;
			}
		}
	}
	return;
}

void displayGraph(graph g){
	for(int i = 0; i < g.numVertices; i++){
		for(int j = 0; j < g.numVertices; j++)
			printf("%d ", g.adjMatrix[i][j]);
		printf("\n");
	}
}

void deleteGraph(graph *g){
	for(int i = 0; i < g->numVertices; i++)
		free(g->adjMatrix[i]);
	free(g->adjMatrix);
	g->adjMatrix = NULL;
	g->numVertices = 0;
	return;
}


// Prims algo funcs-

int minWeight(int *weight, int *visited, graph g)
{
	int min = INT_MAX, min_index = -1;
	for (int i = 0; i < g.numVertices; i++)
	{
		if (visited[i] == 0 && weight[i] < min)
		{
			min = weight[i];
			min_index = i;
		}
	}
	return min_index;
}

void printPrims(int *parent, int *weight, graph g)
{
	for (int i = 0; i < g.numVertices; i++)
	{
		printf("%d -> %d : %d\n", parent[i], i, weight[i]);
	}
	return;
}

void prims(graph g, int start)
{
	int i;
	int *parent = (int *)calloc(g.numVertices, sizeof(int));
	int *weight = (int *)calloc(g.numVertices, sizeof(int));
	int *visited = (int *)calloc(g.numVertices, sizeof(int));
	for (i = 0; i < g.numVertices; i++)
	{
		parent[i] = -1;
		weight[i] = INT_MAX;
	}

	weight[start] = 0;
	for (i = 0; i < g.numVertices - 1; i++)
	{
		int u = minWeight(weight, visited, g);
		visited[u] = 1;
		for (int j = 0; j < g.numVertices; j++)
		{
			if (g.adjMatrix[u][j] != 0 && visited[j] == 0 && g.adjMatrix[u][j] < weight[j])
			{
				parent[j] = u;
				weight[j] = g.adjMatrix[u][j];
			}
		}
	}

	printPrims(parent, weight, g);
	return;
}