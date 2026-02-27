#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"

struct Node* createNode(int id, char nama[], char jabatan[]) {

     struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Gagal mengalokasikan memori untuk node baru.\n");
        exit(1);
    }

    newNode->id = id;
    strcpy(newNode->nama, nama);
    strcpy(newNode->jabatan, jabatan);

    newNode->firstChild = NULL;
    newNode->nextSibling = NULL;

    return newNode;
}