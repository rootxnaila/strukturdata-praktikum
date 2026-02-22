#ifndef GRAPH_LIST_H
#define GRAPH_LIST_H

#include <stdlib.h>

#define MAX_VERTEX 10

//node untuk linkedlist
typedef struct tEdgeNode{
    int destIndex; //index vertex tujuan
    int weight; //bobot edge
    struct tEdgeNode *next;
} EdgeNode;

typedef struct {
    char vertices[MAX_VERTEX]; //nama vertex          
    EdgeNode* head[MAX_VERTEX]; //array of linkedlist
    int numVertices;                   
} GraphList;

void initGraphList(GraphList *g);
void addVertexList(GraphList *g, char name);
int getIndexList(GraphList *g, char name);
void addEdgeList(GraphList *g, char src, char dest, int weight);
void printGraphList(GraphList g);
void destroyGraphList(GraphList *g); // Hapus memori

#endif