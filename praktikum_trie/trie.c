#include <stdio.h>
#include <stdlib.h>
#include "trie.h"

struct TrieNode* createNode(){
    struct TrieNode* node = (struct TrieNode*)malloc(sizeof(struct TrieNode));
    node->isEndOfWord = 0 ;
    
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        node->children[i] = NULL;
    }

    return node;
}

void insert(struct TrieNode* root, const char* key){
    struct TrieNode* current = root;
    //looping huruf dari nama kontak
    for (int i=0; key[i] != '\0'; i++){
        int index = key[i] - 'a'; //mengubah karakter ke indeks array
        if (current->children[index] == NULL) {
            current->children[index] = createNode(); //buat node baru jika belum ada
        }
        current = current->children[index]; //lanjut ke node berikutnya
    }
    current->isEndOfWord = 1; //batas akhir nama kontak
}

int search(struct TrieNode* root, const char* key){
    struct TrieNode* current = root;

    for (int i = 0; key[i] != '\0'; i++){
        int index = key[i] - 'a';

        if (current->children[index] == NULL){
            return 0;
        }

        current = current->children[index];
    }

    return (current != NULL && current->isEndOfWord);
}

int startsWith(struct TrieNode* root, const char* prefix){
    struct TrieNode* current = root;

    for (int i = 0; prefix[i] != '\0'; i++){
        int index = prefix[i] - 'a';

        if (current->children[index] == NULL){
            return 0;
        }

        current = current->children[index];
    }

    return 1;
}