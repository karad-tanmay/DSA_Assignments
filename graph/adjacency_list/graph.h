typedef struct AdjListNode{
    int destVertex;
    int edgeWeight;
    struct AdjListNode* next;
}AdjListNode;

typedef struct graph{
    int size;
    AdjListNode **arr;
}graph;

void init(graph *g, int size);
void insertEdge(graph *g, int start, int dest, int edgeWeight);
void insertUndirectedEdge(graph *g, int start, int dest, int edgeWeight);
void displayGraph(graph g);
void graphBFS(graph g, int start);
void graphDFS(graph g, int start);
void freeGraph(graph *g);


// Prim's Algo for MST
int minWeight(int *weight, int *visited, graph g);
void printPrims(int *parent, int *weight, graph g);
void prims(graph g, int start);