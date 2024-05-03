#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../Headers/Struct.h"
#include "../Headers/colors.h"

// Fonction sert à chercher un produit voulu selon le nom du produit ou selon le nom de l'utilisateur du produit
Prod* Search(Prod* prod, int choice){
    Prod* product_index = prod->next;
    char target[50];
    rewind(stdin);

    // Si le choix égale à 1 la recherche va t-être émis selon le nom du produit 
    if (choice == 1) {
        printf(ANSI_MAGENTA "\nEntrer le nom du produit a rechercher >> " ANSI_RESET);
        fgets(target, sizeof(target), stdin);

        // Boucle sert à chercher le produit par son nom
        while (product_index != prod) {
            if (!strcmp(product_index->name, target)) {
                return product_index;
            }
            product_index = product_index->next;
        }
    }

    // Si le choix égale à 1 la recherche va t-être émis selon le nom de l'utilisateur du produit 
    else if (choice == 2) {
        printf(ANSI_MAGENTA "\nEntrer le nom de l\'utilisateur du produit a rechercher >> " ANSI_RESET);
        fgets(target, sizeof(target), stdin);

        // Boucle sert à chercher le produit par le nom de son utilisateur
        while (product_index != prod) {
            if (!strcmp(product_index->Username, target)) {
                return product_index;
            }
            product_index = product_index->next;
        }
    }

    puts(ANSI_RED "\nError : nom n\'existe pas!!\n" ANSI_RESET);
    return prod;

}