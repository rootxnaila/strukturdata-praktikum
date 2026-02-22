#ifndef STACK_H
#define STACK_H

#include <stdbool.h>
#include <stdlib.h>

#define SIZE_INIT 5  

typedef struct tElmtStack {
    int info;
    struct tElmtStack *next;
} ElmtStack;

typedef struct {
    ElmtStack *top;  
    int curSize;     
} Stack;

void initStack(Stack *S);
ElmtStack* allocate(int value);
void deallocate(ElmtStack *p);

void push(Stack *S, int value);  
int pop(Stack *S);               
int getTop(Stack S);             
bool isEmpty(Stack S);
bool isFull(Stack S);

void printStack(Stack S);

#endif