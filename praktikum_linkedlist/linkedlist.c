#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

//init
void init(linkedList *L) {
    L->head = NULL;
}

//isEmpty
bool isEmpty(linkedList L) {
    return (L.head == NULL);
}

//allocate
Node* allocate(int value) {
    Node *P = (Node*) malloc(sizeof(Node));
    if (P != NULL) {
        P->data = value;
        P->next = NULL;
    }
    return P;
}

//deallocate
void deallocate(Node *P) {
    free(P);
}

//insertLast
void insertLast(linkedList *L, int value) {
    Node *P = allocate(value);

    if (isEmpty(*L)) {
        L->head = P;
    } else {
        Node *temp = L->head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = P;
    }
}

//insertAfter (tambah setelah nilai tertentu)
void insertAfter(linkedList *L, int key, int value) {
    Node *temp = search(*L, key);

    if (temp != NULL) {
        Node *P = allocate(value);
        P->next = temp->next;
        temp->next = P;
    } else {
        printf("data %d tidak ditemukan", key);
    }
}

//deleteFirst
void deleteFirst(linkedList *L) {
    if (!isEmpty(*L)) {
        Node *temp = L->head;
        L->head = temp->next;
        deallocate(temp);
    }
}

//deleteLast
void deleteLast(linkedList *L) {
    if (isEmpty(*L)) return;

    Node *temp = L->head;
    Node *prev = NULL;

    if (temp->next == NULL) {
        L->head = NULL;
        deallocate(temp);
        return;
    }

    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }
    
    prev->next = NULL;
    deallocate(temp);
}

//search
Node* search(linkedList L, int value) {
    Node *temp = L.head;
    while (temp != NULL) {
        if (temp->data == value)
            return temp;
        temp = temp->next;
    }
    return NULL;
}

//length
int length(linkedList L) {
    int count = 0;
    Node *temp = L.head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

//destroy
void destroy(linkedList *L) {
    while (!isEmpty(*L)){
        deleteFirst(L);
    }
}

//print
void printflist(linkedList *L) {
    Node *temp = L->head;
    while (temp != NULL) {
        printf("%d ->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}