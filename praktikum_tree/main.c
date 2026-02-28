#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"

int main() {
    printf("=== TEST PROGRAM COMPANY STRUCTURE (GENERAL TREE) ===\n\n");

    //init root
    struct Node* ceo = createNode(1, "Yang Mulia John Doe", "CEO");

    //create node untuk head division
    struct Node* headIT = createNode(101, "Pak JF", "Head of IT");
    struct Node* headHR = createNode(201, "Bu Siti", "Head of HR");
    struct Node* headFinance = createNode(301, "Bu Rini", "Head of Finance");

    //addchild head division as bawahan CEO
    addChild(ceo, headIT);
    addChild(ceo, headHR);
    addChild(ceo, headFinance);

    //create node staff 
    struct Node* staffIT1 = createNode(102, "Naila", "Staff IT");
    struct Node* staffIT2 = createNode(103, "Zhulva", "Staff IT");
    struct Node* staffIT3 = createNode(104, "Refina", "Staff IT");
    struct Node* staffHR1 = createNode(202, "Kak Kha", "Staff HR");
    struct Node* staffHR2 = createNode(202, "Kak Qinthara", "Staff HR");

    //addchild staff ke divisi masing masing
    addChild(headIT, staffIT1);
    addChild(headIT, staffIT2);
    addChild(headIT, staffIT3);
    addChild(headHR, staffHR1);
    addChild(headHR, staffHR2);

    printf("Bagan Organisasi Saat Ini:\n");
    printf("--------------------------------------------------\n");
    displayTree(ceo, 0); // mulai dr CEO dgn depth 0
    printf("--------------------------------------------------\n\n");

    //test fitur pencarian, searchnode
    int idDicari = 103;
    printf("Mencari Pegawai dengan ID %d...\n", idDicari);
    
    struct Node* hasilCari = searchNode(ceo, idDicari);
    
    if (hasilCari != NULL) {
        printf(">> KETEMU! Data Pegawai: [%d] %s - %s\n", hasilCari->id, hasilCari->nama, hasilCari->jabatan);
    } else {
        printf(">> MAAF, Pegawai dengan ID %d tidak ditemukan.\n", idDicari);
    }

    return 0;
}