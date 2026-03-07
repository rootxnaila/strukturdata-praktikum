#ifndef GRAPH_MATRIX_H
#define GRAPH_MATRIX_H

#define MAX_VERTEX 10

typedef struct {
    char vertices[MAX_VERTEX]; // array untuk menyimpan nama vertex 
    int edges[MAX_VERTEX][MAX_VERTEX]; // matrix ketetanggaan untuk bobot (weight)
    int numVertices; // jumlah vertex saat ini
} GraphMatrix;

void initGraph(GraphMatrix *g);
void addVertex(GraphMatrix *g, char name);
int getVertexIndex(GraphMatrix *g, char name);
void addEdge(GraphMatrix *g, char src, char dest, int weight);
void printGraph(GraphMatrix g);

#endif