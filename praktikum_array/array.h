#ifndef ARRAY_H
#define ARRAY_H

#include <stdlib.h> 


typedef struct {
    int *data;      
    int size;
    int capacity;   
} Array;

void initArray(Array *arr);
int isEmpty(Array arr);
void allocate(Array *arr, int capacity); 
void deallocate(Array *arr);
void insert(Array *arr, int value);
void removeAt(Array *arr, int index);
int search(Array arr, int value);
void destroy(Array *arr);
int length(Array arr);

#endif