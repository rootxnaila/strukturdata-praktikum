#include <stdio.h>

struct Node {
    int id;
    char nama[100];
    char jabatan[100];
    struct Node *firstChild;
    struct Node *nextSibling;
};

struct Node* createNode(int id, char nama[], char jabatan[]);
int isEmpty(struct Node* root);
int isLeaf(struct Node* node);