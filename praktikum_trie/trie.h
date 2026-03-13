#ifndef TRIE_H
#define TRIE_H

#define ALPHABET_SIZE 26 

//represents struktur node trie
struct TrieNode {
    struct TrieNode* children[ALPHABET_SIZE];
    int isEndOfWord; //1 jika node ini adalah akhir dari nama kontak, 0 jika tidak
};

struct TrieNode* createNode();
void insert(struct TrieNode* root, const char* key);

int search(struct TrieNode* root, const char* key);
int startsWith (struct TrieNode* root, const char* prefix);

#endif