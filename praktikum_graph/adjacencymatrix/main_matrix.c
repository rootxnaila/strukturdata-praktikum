#include <stdio.h>
#include "graph_matrix.h"

int main() {
    GraphMatrix G;
    initGraph(&G);

    addVertex(&G, 'A');
    addVertex(&G, 'B');
    addVertex(&G, 'C');

    // Sesuai gambar slide dosen:
    addEdge(&G, 'A', 'B', 5);
    addEdge(&G, 'B', 'A', 7);
    addEdge(&G, 'B', 'C', 8);
    addEdge(&G, 'C', 'B', 6);

    printGraph(G);
    return 0;
}