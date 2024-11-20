#include "graph.c"

int main(){
	graph g;
	initGraph(&g, 5);
	insertUndirectedEdge(&g, 1, 2, 1);
	insertUndirectedEdge(&g, 1, 3, 2);
	insertUndirectedEdge(&g, 1, 4, 3);
	insertUndirectedEdge(&g, 2, 3, 4);
	insertUndirectedEdge(&g, 3, 4, 5);
	insertUndirectedEdge(&g, 3, 5, 6);
	insertUndirectedEdge(&g, 4, 5, 7);
	graphBFS(g, 5);
	printf("\n");
	graphDFS(g, 1);
	printf("\n");
	displayGraph(g);
	deleteGraph(&g);
	return 0;
}