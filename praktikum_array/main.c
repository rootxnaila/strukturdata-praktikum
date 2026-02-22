#include <stdio.h>
#include "array.h"

int main() {
    Array arr;

    // init struct
    initArray(&arr);

    // allocate (pesan memori untuk 10 angka)
    allocate(&arr, 10);

    printf("Array kosong? %s\n", isEmpty(arr) ? "Ya" : "Tidak");

    insert(&arr, 10);
    insert(&arr, 20);
    insert(&arr, 30);

    printf("Jumlah elemen: %d\n", length(arr));

    int idx = search(arr, 20);
    if (idx != -1) {
        printf("Data 20 ditemukan di index %d\n", idx);
    } else {
        printf("Data tidak ditemukan\n");
    }

    removeAt(&arr, 1);
    printf("Jumlah elemen setelah delete: %d\n", length(arr));

    // destroy (agar memori ram bersih kembali)
    destroy(&arr);
    
    printf("Array kosong setelah destroy? %s\n", 
           isEmpty(arr) ? "Ya" : "Tidak");

    return 0;
}