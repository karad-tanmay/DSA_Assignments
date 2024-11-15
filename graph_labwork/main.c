#include "graph.c"

int main(){
    graph g;
    initGraph(&g, 9);
    insertUndirectedEdge(&g, 'a', 'b', 2);
    insertUndirectedEdge(&g, 'a', 'c', 4);
    insertUndirectedEdge(&g, 'a', 'd', 6);
    insertUndirectedEdge(&g, 'c', 'b', 5);
    insertUndirectedEdge(&g, 'c', 'd', 1);
    insertUndirectedEdge(&g, 'c', 'e', 2);
    insertUndirectedEdge(&g, 'd', 'h', 4);
    insertUndirectedEdge(&g, 'd', 'f', 3);
    insertUndirectedEdge(&g, 'e', 'f', 1);
    insertUndirectedEdge(&g, 'e', 'g', 5);
    insertUndirectedEdge(&g, 'e', 'i', 3);
    insertUndirectedEdge(&g, 'g', 'f', 4);

    graphBFS(g, 'i');
    printf("\n");
    graphDFS(g, 'i');
    printf("\n");

    displayGraph(g);

    deleteGraph(&g);
    // printf("test0");
    return 0;
}