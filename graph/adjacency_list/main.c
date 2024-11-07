#include "graph.c"

int main(){
	graph g;
	init(&g, 6);
	insertEdge(&g, 1, 2, 0);
	insertEdge(&g, 1, 3, 0);
	insertEdge(&g, 1, 4, 0);
	insertEdge(&g, 2, 1, 0);
	insertEdge(&g, 2, 3, 0);
	insertEdge(&g, 3, 1, 0);
	insertEdge(&g, 3, 2, 0);
	insertEdge(&g, 3, 4, 0);
	insertEdge(&g, 3, 5, 0);
	insertEdge(&g, 4, 1, 0);
	insertEdge(&g, 4, 3, 0);
	insertEdge(&g, 4, 5, 0);
	insertEdge(&g, 5, 3, 0);
	insertEdge(&g, 5, 4, 0);
	graphBFS(g, 5);
	printf("\n");
	graphDFS(g, 1);
	printf("\n");
	displayGraph(g);
	freeGraph(&g);
	return 0;
}