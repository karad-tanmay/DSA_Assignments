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
void displayGraph(graph g);
void graphBFS(graph g, int start);
void graphDFS(graph g, int start);
void freeGraph(graph *g);
