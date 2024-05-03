#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Headers/Struct.h"
#include "../Headers/colors.h"

// Fonction sert à affecter les valeurs des élements du produit 2 (prod2) au valeurs des élements du produit 1 (prod1)
Prod* transfer(Prod* prod1, Prod* prod2){
    prod1->id = prod2->id;
    strcpy(prod1->Description, prod2->Description);
    strcpy(prod1->name, prod2->name);
    strcpy(prod1->Username, prod2->Username);
    prod1->price = prod2->price;
    prod1->Quantity = prod2->Quantity;
    prod1->Alert_threshold = prod2->Alert_threshold;
    prod1->d_last_enter.day = prod2->d_last_enter.day;
    prod1->d_last_enter.month = prod2->d_last_enter.month;
    prod1->d_last_enter.year = prod2->d_last_enter.year;
    prod1->d_last_exit.day = prod2->d_last_exit.day;
    prod1->d_last_exit.month = prod2->d_last_exit.month;
    prod1->d_last_exit.year = prod2->d_last_exit.year;

    return prod1;
}

// Fonction sert à trier les produits par ordre alphabétique ou par prix
Prod* Sort(Prod* prod, int choice){

    // Vérifier si la liste des produits est vide
    if (prod->next == prod) {
        puts(ANSI_RED "Error: La liste des produits est vide!" ANSI_RESET);
        return prod;
    }
    
    Prod* tmp = (Prod*)malloc(sizeof(Prod));
    Prod* product_indexI = prod->next;

    // Les boucles de triage par insértion
    // product_indexI est l'indice des élements qui vont t-être comparer avec le reste de la liste
    while (product_indexI != prod) {
        Prod* product_indexJ = prod->next;
        while (product_indexJ != prod) {
            if ( (choice == 1 && strcmp(product_indexI->name, product_indexJ->name) < 0) || (choice == 2 && product_indexI->price < product_indexJ->price) ) {

                // La permutation des élements des produits qui doivent échanger les place dans le liste
                tmp = transfer(tmp, product_indexI);
                product_indexI = transfer(product_indexI, product_indexJ);
                product_indexJ = transfer(product_indexJ, tmp);

            }
            product_indexJ = product_indexJ->next;
        }
        product_indexI = product_indexI->next;
    }

    return prod;
}