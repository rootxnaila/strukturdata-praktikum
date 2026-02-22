#include <stdio.h>
#include "graph_matrix.h"

// 1. Create Graph (Inisialisasi)
void initGraph(GraphMatrix *g) {
    g->numVertices = 0;
    for (int i = 0; i < MAX_VERTEX; i++) {
        for (int j = 0; j < MAX_VERTEX; j++) {
            g->edges[i][j] = 0; // 0 menandakan tidak ada edge
        }
    }
}

// 2. Add Vertex (Tambah Simpul)
void addVertex(GraphMatrix *g, char name) {
    if (g->numVertices < MAX_VERTEX) {
        g->vertices[g->numVertices] = name;
        g->numVertices++;
    } else {
        printf("Graf Penuh!\n");
    }
}

// Fungsi bantu cari index
int getVertexIndex(GraphMatrix *g, char name) {
    for (int i = 0; i < g->numVertices; i++) {
        if (g->vertices[i] == name) return i;
    }
    return -1;
}

// 3. Add Edge (Tambah Busur/Jalur berbobot)
void addEdge(GraphMatrix *g, char src, char dest, int weight) {
    int srcIndex = getVertexIndex(g, src);
    int destIndex = getVertexIndex(g, dest);

    if (srcIndex != -1 && destIndex != -1) {
        // Graf Berarah (Directed): Hanya src -> dest
        g->edges[srcIndex][destIndex] = weight;
    } else {
        printf("Vertex tidak ditemukan!\n");
    }
}

// 4. Print
void printGraph(GraphMatrix g) {
    printf("--- ADJACENCY MATRIX ---\n  ");
    for (int i = 0; i < g.numVertices; i++) {
        printf("%c ", g.vertices[i]);
    }
    printf("\n");
    for (int i = 0; i < g.numVertices; i++) {
        printf("%c ", g.vertices[i]);
        for (int j = 0; j < g.numVertices; j++) {
            printf("%d ", g.edges[i][j]);
        }
        printf("\n");
    }
}