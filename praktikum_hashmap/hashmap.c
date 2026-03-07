#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashmap.h"

//init indeks tabel 
void initHashMap(struct Node* hashTable[]) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = NULL;
    }
}

//ascii dari string key
int hashFunction(char* key) {
    int sum = 0;
    for (int i = 0; key[i] != '\0'; i++) {
        sum += key[i]; 
    }
    return sum % TABLE_SIZE; 
}

//insert data ke hash table
void insertBook(struct Node* hashTable[], char* kode, char* judul, char* pengarang) {
    int index = hashFunction(kode); 

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->kode_buku, kode);
    strcpy(newNode->judul, judul);
    strcpy(newNode->pengarang, pengarang);
    newNode->next = NULL;

    if (hashTable[index] == NULL) {
        hashTable[index] = newNode;
    } else {
        newNode->next = hashTable[index];
        hashTable[index] = newNode;
    }
}

//search
void searchBook(struct Node* hashTable[], char* kode) {
    int index = hashFunction(kode); 
    struct Node* temp = hashTable[index];

    //crosscheck data
    while (temp != NULL) {
        if (strcmp(temp->kode_buku, kode) == 0) {
            printf("\n>> [DITEMUKAN] Kode: %s | Judul: %s | Pengarang: %s\n", temp->kode_buku, temp->judul, temp->pengarang);
            return;
        }
        temp = temp->next;
    }
    printf("\n>> [TIDAK DITEMUKAN] Buku dengan kode '%s' tidak ada di sistem.\n", kode);
}

//tampil isi hashtable
void displayHashMap(struct Node* hashTable[]) {
    printf("\n=== HASHMAP (TABEL KATALOG PERPUSTAKAAN) ===\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("Index [%d]: ", i);
        struct Node* temp = hashTable[i];
        
        if (temp == NULL) {
            printf("Kosong\n");
        } else {
            while (temp != NULL) {
                printf("-> [%s: %s] ", temp->kode_buku, temp->judul);
                temp = temp->next;
            }
            printf("\n");
        }
    }
    printf("================================================\n");
}