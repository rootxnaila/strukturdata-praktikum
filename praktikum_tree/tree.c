#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"

struct Node* createNode(int id, char nama[], char jabatan[]) {

     struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Gagal mengalokasikan memori untuk node baru.\n");
        exit(1);
    }

    newNode->id = id;
    strcpy(newNode->nama, nama);
    strcpy(newNode->jabatan, jabatan);

    newNode->firstChild = NULL;
    newNode->nextSibling = NULL;

    return newNode;
}

int isEmpty(struct Node* root) {
    return (root == NULL);
}

int isLeaf(struct Node* node) {
    return (node->firstChild == NULL);
}
//nai
// add bawahan (child)
void addChild(struct Node* parent, struct Node* child){
    if(parent == NULL || child == NULL) return;
    //if parent has nochild at all
    if (parent->firstChild == NULL) {
        parent->firstChild = child;
    } 
    //if parent has child, add sibling
    else {
        //if parent has child, add sibling
        struct Node* temp = parent->firstChild;
        while (temp->nextSibling != NULL) {
            temp = temp->nextSibling; 
        }
        temp->nextSibling = child; // add new child di sebelah anak terakhir
    }
}
    //show struktur organisasi (pre-order traversal)
void displayTree(struct Node* root, int depth) {
    if (root == NULL) return;

    // create spasi biar kelihatan mana atasan mana bawahan
    for (int i = 0; i < depth; i++) {
        printf("    "); // 4 spasi per level
    }
    
    // garis panah/cabang kalau dia bawahan
    if (depth > 0) {
        printf("|- ");
    }
    
    // print node
    printf("[%d] %s (%s)\n", root->id, root->nama, root->jabatan);

    //  call rekursif untuk anak anaknya (level/depth nambah 1)
    displayTree(root->firstChild, depth + 1);
    
    // call rekursif untuk rekan/saudaranya (level/depth tetap)
    displayTree(root->nextSibling, depth);
}

//find pegawai based on ID
struct Node* searchNode(struct Node* root, int id) {
    if (root == NULL) return NULL;
    
    // id cocok sama node saat ini, kembalikan nodenya
    if (root->id == id) return root;

    // kl belum ketemu, cari ke bawah (ke anak anaknya)
    struct Node* foundNode = searchNode(root->firstChild, id);
    if (foundNode != NULL) return foundNode; // kl ketemu di anak, langsung kembalikan

    // kl di anak ngga ada, cari ke samping (ke saudara saudaranya)
    return searchNode(root->nextSibling, id);
}

//RemoveChild (Hapus Bawahan)
void removeChild(struct Node* parent, struct Node* child) {
    if (parent == NULL || child == NULL) return;

    struct Node* curr = parent->firstChild;
    struct Node* prev = NULL;

    while (curr != NULL) {
        if (curr == child) {
            if (prev == NULL) {
                parent->firstChild = curr->nextSibling;
            } else {
                prev->nextSibling = curr->nextSibling;
            }
            return;
        }
        prev = curr;
        curr = curr->nextSibling;
    }
}

// menghapus node + seluruh subtree-nya
void deleteSubtree(struct Node* target) {
    if (target == NULL) return;

    struct Node* child = target->firstChild;

    while (child != NULL) {
        struct Node* next = child->nextSibling;
        deleteSubtree(child);     // hapus anak dulu
        child = next;
    }
}
//UpdateNote (Perbarui)
void updateNode(struct Node* target, char namaBaru[], char jabatanBaru[]) { //edit data pegawai
    if (target == NULL) return; //ganti nama jabatan
    
    strcpy(target->nama, namaBaru); //node gak ada, ga bisa ganti
    strcpy(target->jabatan, jabatanBaru); //ganti nama lama ke baru

}
//countSubordinates (Hitung)
int countSubordinates(struct Node* target) { //hitung jumlah pegawai
    if (target == NULL) return 0; //balikin jumlah bawahan
    
    int total = 0; //gak ada ya = bawahan 0
    struct Node* child = target->firstChild; //var jumlah bawahan
    
    while (child != NULL) { //hitung anak 1
        total++; //next selagi punya
        total += countSubordinates(child); //anak hitung satu
        child = child->nextSibling; //hitung cucu
        }
        
        return total; 
} 



