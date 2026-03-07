#ifndef TREE_H
#define TREE_H

#include <stdio.h>

struct Node {
    int id;
    char nama[100];
    char jabatan[100];
    struct Node *firstChild;
    struct Node *nextSibling;
};
//refina
struct Node* createNode(int id, char nama[], char jabatan[]);
int isEmpty(struct Node* root);
int isLeaf(struct Node* node);

// nai
void addChild(struct Node* parent, struct Node* child);
void displayTree(struct Node* root, int depth);
struct Node* searchNode(struct Node* root, int id);

//zhull
void removeChild(struct Node* parent, struct Node* child);
void deleteSubtree(struct Node* target);
void updateNode(struct Node* target, char namaBaru[], char jabatanBaru[]);
int countSubordinates(struct Node* target);

#endif