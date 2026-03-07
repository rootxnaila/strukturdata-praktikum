#include <stdio.h>
#include "stack.h"

int main() {
    Stack S;
    initStack(&S);

    printf("=== IMPLEMENTASI STACK (LINKED LIST) ===\n");
    printf("Kapasitas Max (SIZE_INIT): %d\n\n", SIZE_INIT);

    push(&S, 10);
    push(&S, 20);
    push(&S, 30);
    push(&S, 40);
    push(&S, 50);
    push(&S, 60); 

    printStack(S);

    printf("\nElemen Top saat ini: %d\n", getTop(S));
    printf("\nPop elemen: %d\n", pop(&S)); 
    printf("Pop elemen: %d\n", pop(&S));   
    
    printStack(S);
    printf("Elemen Top sekarang: %d\n", getTop(S));

    printf("\nPop sisa elemen...\n");
    pop(&S); pop(&S); pop(&S); 
    pop(&S); 

    printf("Apakah kosong? %s\n", isEmpty(S) ? "Ya" : "Tidak");

    return 0;
}