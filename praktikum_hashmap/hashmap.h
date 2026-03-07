#ifndef HASHMAP_H
#define HASHMAP_H

#define TABLE_SIZE 10 

struct Node {
    char kode_buku[20]; //key
    char judul[100];    //value
    char pengarang[50]; //value
    struct Node* next;  
};

// deklarasi fungsi hashmap
void initHashMap(struct Node* hashTable[]);
int hashFunction(char* key);
void insertBook(struct Node* hashTable[], char* kode, char* judul, char* pengarang);
void searchBook(struct Node* hashTable[], char* kode);
void displayHashMap(struct Node* hashTable[]);

#endif