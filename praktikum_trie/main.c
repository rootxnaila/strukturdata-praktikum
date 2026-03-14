#include <stdio.h>
#include "trie.h"

int main() {
    struct TrieNode* root = createNode();

    int pilihan;
    char nama[100];

    do {
        printf("\n=== MENU TRIE KONTAK ===\n");
        printf("1. Insert Nama\n");
        printf("2. Search Nama\n");
        printf("3. Search Prefix\n");
        printf("4. Keluar\n");
        printf("Pilih: ");
        scanf("%d", &pilihan);

        switch(pilihan) {

            case 1:
                printf("Masukkan nama (huruf kecil): ");
                scanf("%s", nama);
                insert(root, nama);
                printf("Nama berhasil ditambahkan.\n");
                break;

            case 2:
                printf("Masukkan nama yang dicari: ");
                scanf("%s", nama);

                if(search(root, nama))
                    printf("Nama ditemukan.\n");
                else
                    printf("Nama tidak ditemukan.\n");

                break;

            case 3:
                printf("Masukkan prefix: ");
                scanf("%s", nama);

                if(startsWith(root, nama))
                    printf("Ada nama dengan prefix tersebut.\n");
                else
                    printf("Tidak ada nama dengan prefix tersebut.\n");

                break;

            case 4:
                printf("Program selesai.\n");
                break;

            default:
                printf("Pilihan tidak valid.\n");
        }

    } while(pilihan != 4);

    return 0;
}