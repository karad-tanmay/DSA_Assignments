#include "graph.c"
// #include "primsAlgo.c"

int main(){
	graph g;
	init(&g, 6);
	insertUndirectedEdge(&g, 0, 1, 2);
	insertUndirectedEdge(&g, 0, 3, 4);
	insertUndirectedEdge(&g, 1, 3, 1);
	insertUndirectedEdge(&g, 1, 2, 3);
	insertUndirectedEdge(&g, 2, 5, 4);
	insertUndirectedEdge(&g, 3, 4, 2);
	insertUndirectedEdge(&g, 4, 5, 1);
	graphBFS(g, 5);
	printf("\n");
	graphDFS(g, 1);
	printf("\n");
	displayGraph(g);
	prims(g, 0);
	freeGraph(&g);
	return 0;
}