#include <stdio.h>
#include "graph_list.h"

int main() {
    GraphList G;
    initGraphList(&G);

    addVertexList(&G, 'A');
    addVertexList(&G, 'B');
    addVertexList(&G, 'C');

    addEdgeList(&G, 'A', 'B', 5);
    addEdgeList(&G, 'B', 'A', 7);
    addEdgeList(&G, 'B', 'C', 8);
    addEdgeList(&G, 'C', 'B', 6);

    printGraphList(G);
    
    destroyGraphList(&G); // clear memori malloc
    return 0;
}