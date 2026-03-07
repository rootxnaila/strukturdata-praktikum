#include <stdio.h>
#include <stdlib.h>
#include "array.h"

// initialization / create
void initArray(Array *arr) {
    arr->data = NULL; 
    arr->size = 0;
    arr->capacity = 0;
}

// allocate (pesan memori)
void allocate(Array *arr, int capacity) {
    // minta memori ke sistem operasi (heap)
    arr->data = (int*) malloc(capacity * sizeof(int));
    
    if (arr->data != NULL) {
        arr->capacity = capacity;
        arr->size = 0;
        printf("Info: Berhasil alokasi memori untuk %d elemen.\n", capacity);
    } else {
        printf("Error: Gagal alokasi memori!\n");
    }
}

// isEmpty
int isEmpty(Array arr) {
    return arr.size == 0;
}

// insert / add
void insert(Array *arr, int value) {
    // cek apakah jumlah data masih muat di kapasitas yang dipesan
    if (arr->size < arr->capacity) {
        arr->data[arr->size] = value;
        arr->size++;
    } else {
        printf("Error: Array Penuh! (Kapasitas max: %d)\n", arr->capacity);
    }
}

// remove / delete
void removeAt(Array *arr, int index) {
    if (index < 0 || index >= arr->size) {
        printf("Error: Index tidak valid!\n");
        return;
    }

    for (int i = index; i < arr->size - 1; i++) {
        arr->data[i] = arr->data[i + 1];
    }
    arr->size--;
}

// search
int search(Array arr, int value) {
    for (int i = 0; i < arr.size; i++) {
        if (arr.data[i] == value) {
            return i;
        }
    }
    return -1;
}

// destroy / deallocate
void destroy(Array *arr) {
    if (arr->data != NULL) {
        free(arr->data); // hapus memori di heap
        arr->data = NULL; 
    }
    arr->size = 0;
    arr->capacity = 0;
    printf("Info: Memori array telah dibebaskan.\n");
}

// deallocate 
void deallocate(Array *arr) {
    destroy(arr);
}

// length
int length(Array arr) {
    return arr.size;
}