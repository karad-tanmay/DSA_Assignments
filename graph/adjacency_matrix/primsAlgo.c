#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "graph.h"

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