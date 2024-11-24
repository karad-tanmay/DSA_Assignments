typedef struct graph{
    int **adjMatrix;
    int numVertices;
}graph;

void initGraph(graph *g, int size);
void insertEdge(graph *g, int start, int end, int weight);
void insertUndirectedEdge(graph *g, int start, int end, int weight);
void removeEdge(graph *g, int start, int end);
void removeUndirectedEdge(graph *g, int start, int end);
void graphBFS(graph g, int start);
void graphDFS(graph g, int start);
void displayGraph(graph g);
void deleteGraph(graph *g);

// Prim's Algo for MST
int minWeight(int *weight, int *visited, graph g);
void printPrims(int *parent, int *weight, graph g);
void prims(graph g, int start);