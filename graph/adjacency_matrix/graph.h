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