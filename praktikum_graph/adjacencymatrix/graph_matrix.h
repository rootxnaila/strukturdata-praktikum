#ifndef GRAPH_MATRIX_H
#define GRAPH_MATRIX_H

#define MAX_VERTEX 10

typedef struct {
    char vertices[MAX_VERTEX];          // Array untuk menyimpan nama vertex (A, B, C, dst)
    int edges[MAX_VERTEX][MAX_VERTEX];  // Matriks ketetanggaan untuk bobot (weight)
    int numVertices;                    // Jumlah vertex saat ini
} GraphMatrix;

void initGraph(GraphMatrix *g);
void addVertex(GraphMatrix *g, char name);
int getVertexIndex(GraphMatrix *g, char name);
void addEdge(GraphMatrix *g, char src, char dest, int weight);
void printGraph(GraphMatrix g);

#endif