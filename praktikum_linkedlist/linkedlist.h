#ifndef lINKEDlIST_H
#define lINKEDlIST_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct linkedList{
    Node *head;
} linkedList;

//Prototype
void init(linkedList *l);
bool isEmpty(linkedList l);
Node* alocate(int value);
void dealocate(Node *P);

void insertLast(linkedList *l, int value);
void insertAfter(linkedList *l, int key, int value);

void deleteFirst(linkedList *l);
void deleteLast(linkedList *l);

Node* search(linkedList l, int value);
int length(linkedList l);
void destroy(linkedList *l);
void printflist(linkedList *l);

#endif