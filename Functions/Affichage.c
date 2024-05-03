#include <stdio.h>
#include <stdlib.h>
#include "../Headers/Struct.h"
#include "../Headers/colors.h"


// La procédure sert à afficher le contenu de chaque produit de la liste
void print(Prod* prod) {
    Prod* product = prod->next;
    int counter = 0;
    printf("Products: \n");
    
    // Vérifier si la liste est vide
    if (prod->next == prod) {
        printf(ANSI_RED "\n*************** Aucun produit a afficher ***************\n\n" ANSI_RESET);
        return;
    }

    // Parcourir la liste et afficher chaque produit de cette manière
    do {
        counter++;
        printf(ANSI_BLUE "\n*************** Product %d  ***************\n\n" ANSI_RESET, counter);
        printf("id :" ANSI_CYAN " %d\n" ANSI_RESET, product->id);
        printf("Nom du produit :"ANSI_CYAN " %s" ANSI_RESET, product->name);
        printf("description :" ANSI_CYAN " %s" ANSI_RESET, product->Description);
        printf("Nom d\'utilisateur :"ANSI_CYAN " %s" ANSI_RESET, product->Username);
        printf("Prix :" ANSI_CYAN " %.2f\n" ANSI_RESET, product->price);
        printf("Quantite :" ANSI_CYAN " %d\n" ANSI_RESET, product->Quantity);
        printf("Seuil d\'alerte de stock :" ANSI_CYAN " %d\n" ANSI_RESET, product->Alert_threshold);
        printf("Date de derniere entree en stock =" ANSI_CYAN " %d/%d/%d\n" ANSI_RESET, product->d_last_enter.day, product->d_last_enter.month, product->d_last_enter.year);
        printf("Date de derniere sortie de stock =" ANSI_CYAN " %d/%d/%d\n" ANSI_RESET, product->d_last_exit.day, product->d_last_exit.month, product->d_last_exit.year);

        printf("\n");

        product = product->next;
    } while (product != prod);
}