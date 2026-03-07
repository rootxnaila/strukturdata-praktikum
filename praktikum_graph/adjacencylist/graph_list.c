#include <stdio.h>
#include "graph_list.h"

void initGraphList(GraphList *g) {
    g->numVertices = 0;
    for (int i = 0; i < MAX_VERTEX; i++) {
        g->head[i] = NULL; // list kosong
    }
}

void addVertexList(GraphList *g, char name) {
    if (g->numVertices < MAX_VERTEX) {
        g->vertices[g->numVertices] = name;
        g->numVertices++;
    }
}

int getIndexList(GraphList *g, char name) {
    for (int i = 0; i < g->numVertices; i++) {
        if (g->vertices[i] == name) return i;
    }
    return -1;
}

void addEdgeList(GraphList *g, char src, char dest, int weight) {
    int srcIdx = getIndexList(g, src);
    int destIdx = getIndexList(g, dest);

    if (srcIdx != -1 && destIdx != -1) {
        // create new node
        EdgeNode *newNode = (EdgeNode*) malloc(sizeof(EdgeNode));
        newNode->destIndex = destIdx;
        newNode->weight = weight;
        
        // insert first ke linked list 
        newNode->next = g->head[srcIdx];
        g->head[srcIdx] = newNode;
    }
}

void printGraphList(GraphList g) {
    printf("--- ADJACENCY LIST ---\n");
    for (int i = 0; i < g.numVertices; i++) {
        printf("%c -> ", g.vertices[i]);
        EdgeNode *temp = g.head[i];
        while (temp != NULL) {
            printf("(%c, %d) ", g.vertices[temp->destIndex], temp->weight);
            temp = temp->next;
        }
        printf("\n");
    }
}

void destroyGraphList(GraphList *g) {
    for (int i = 0; i < g->numVertices; i++) {
        EdgeNode *temp = g->head[i];
        while (temp != NULL) {
            EdgeNode *hapus = temp;
            temp = temp->next;
            free(hapus);
        }
        g->head[i] = NULL;
    }
    g->numVertices = 0;
}