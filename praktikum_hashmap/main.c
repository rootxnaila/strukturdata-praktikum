#include <stdio.h>
#include "hashmap.h"

int main() {
    struct Node* hashTable[TABLE_SIZE];

    initHashMap(hashTable);

    //input data
    insertBook(hashTable, "B001", "The C Programming Language", "Dennis M Ritchie");
    insertBook(hashTable, "B002", "Cybook", "John Doe");
    insertBook(hashTable, "B003", "Pemrograman Web Dasar", "Aaron");
    insertBook(hashTable, "A112", "Pengantar Basis Data ", "Tukijan");
    insertBook(hashTable, "C999", "Pengantar Kecerdasan Buatan", "Suparman");

    displayHashMap(hashTable);

    printf("\n[Simulasi Pencarian]");
    
    printf("\nMencari data buku B002...");
    searchBook(hashTable, "B002");

    printf("\nMencari data buku Z000 (Data yang tidak ada)...");
    searchBook(hashTable, "Z000");

    return 0;
}