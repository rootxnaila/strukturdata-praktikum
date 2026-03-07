#include <stdio.h>
#include "stack.h"

void initStack(Stack *S) {
    S->top = NULL;
    S->curSize = 0;
}

ElmtStack* allocate(int value) {
    ElmtStack *newNode = (ElmtStack*) malloc(sizeof(ElmtStack));
    if (newNode != NULL) {
        newNode->info = value;
        newNode->next = NULL;
    }
    return newNode;
}

void deallocate(ElmtStack *p) {
    free(p);
}

bool isEmpty(Stack S) {
    return (S.top == NULL);
}

bool isFull(Stack S) {
    return (S.curSize == SIZE_INIT);
}

void push(Stack *S, int value) {
    if (isFull(*S)) {
        printf("Gagal Push %d: Stack Penuh (Max %d)!\n", value, SIZE_INIT);
    } else {
        ElmtStack *newElement = allocate(value);
        if (newElement != NULL) {
            newElement->next = S->top;
            S->top = newElement;
            
            S->curSize++;
            printf("Push: %d berhasil.\n", value);
        } else {
            printf("Error: Gagal alokasi memori.\n");
        }
    }
}

int pop(Stack *S) {
    if (isEmpty(*S)) {
        printf("Gagal Pop: Stack Kosong!\n");
        return -1; 
    } else {
        ElmtStack *cur_top = S->top; 
        int element = cur_top->info; 
        S->top = cur_top->next;
        deallocate(cur_top); 
        S->curSize--;        
        return element;
    }
}

int getTop(Stack S) {
    if (!isEmpty(S)) {
        return S.top->info;
    }
    return -1; 
}

void printStack(Stack S) {
    ElmtStack *temp = S.top;
    printf("Isi Stack (Top -> Bawah): [ ");
    while (temp != NULL) {
        printf("%d ", temp->info);
        temp = temp->next;
    }
    printf("] (Size: %d)\n", S.curSize);
}