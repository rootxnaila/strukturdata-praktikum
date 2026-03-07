
#include <stdio.h>
#include "linkedlist.h"

int main() {
    linkedList L;
    init(&L);

    //insertlast
    insertLast(&L, 5);
    insertLast(&L, 10);
    insertLast(&L, 15);

    printf("List awal:\n");
    printflist(&L);

    //insertAfter
    insertAfter(&L, 10, 12);
    printf("setelah insert 12 setelah 10:\n");
    printflist(&L);

    //deleteFirst
    deleteFirst(&L);
    printf("Setelah deleteFirst:\n");
    printflist(&L);

    //deleteLast
    deleteLast(&L);
    printf("setelah deleteLast:\n");
    printflist(&L);

    //Search
    if (search(L, 12) != NULL)
        printf("Data 12 ditemukan\n");

    //Length
    printf("panjang list: %d\n", length(L));

    //Destroy
    destroy(&L);
    printf("Setelah destroy:\n");
    printflist(&L);

    return 0;
}