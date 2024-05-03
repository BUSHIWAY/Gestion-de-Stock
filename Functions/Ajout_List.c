#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Headers/Struct.h"
#include "../Headers/colors.h"

// La fonctions responsible pour Ajouter un produit à la liste
Prod* Add(Prod* prod, int choice){
    Prod product;

    // Obtenir de l'utilisateur les elements de ce produit
    printf("\nEntrer l\'ID du produit >> ");
    scanf("%d", &product.id);
    rewind(stdin);
    printf("Entrer Le nom du produit >> ");
    fgets(product.name, sizeof(product.name), stdin);
    rewind(stdin);
    printf("Entrer La description du produit >> ");
    fgets(product.Description, sizeof(product.Description), stdin);
    rewind(stdin);
    printf("Entrer Le nom de l\'utilisateur >> ");
    fgets(product.Username, sizeof(product.Username), stdin);
    rewind(stdin);
    printf("Entrer Le prix du produit >> ");
    scanf("%f", &product.price);
    printf("Entrer La quantite du produit >> ");
    scanf("%d", &product.Quantity);
    printf("Entrer Le seuil d'alerte de stock >> ");
    scanf("%d", &product.Alert_threshold);
    printf("Entrer La date de derniere entrer en stock (JJ/DD/AA) >> ");
    scanf("%d/%d/%d", &product.d_last_enter.day, &product.d_last_enter.month, &product.d_last_enter.year);
    printf("Entrer La date de derniere sortie en stock (JJ/DD/AA) >> ");
    scanf("%d/%d/%d", &product.d_last_exit.day, &product.d_last_exit.month, &product.d_last_exit.year);


    // Affecter ces valeur à une variable pointeur qui va t-être insérer à la liste chainée
    Prod* product_obj = (Prod*)malloc(sizeof(Prod));
    product_obj->id = product.id;
    strcpy(product_obj->Description, product.Description);
    strcpy(product_obj->name, product.name);
    strcpy(product_obj->Username, product.Username);
    product_obj->price = product.price;
    product_obj->Quantity = product.Quantity;
    product_obj->Alert_threshold = product.Alert_threshold;
    product_obj->d_last_enter.day = product.d_last_enter.day;
    product_obj->d_last_enter.month = product.d_last_enter.month;
    product_obj->d_last_enter.year = product.d_last_enter.year;
    product_obj->d_last_exit.day = product.d_last_exit.day;
    product_obj->d_last_exit.month = product.d_last_exit.month;
    product_obj->d_last_exit.year = product.d_last_exit.year;
    
    // Ajouter le produit au debut de la liste
    if ( choice == 1 ) {
        product_obj->prev = prod;
        product_obj->next = prod->next;
        product_obj->next->prev = product_obj;
        prod->next = product_obj;
        return prod;
    }

    // Ajouter le produit à la fin de la liste
    else if ( choice == 2 ) {
        product_obj->next = prod;
        product_obj->prev = prod->prev;
        product_obj->prev->next = product_obj;
        prod->prev = product_obj;
        return prod;
    }    

    // Ajouter le produit à la position voulue
    else if ( choice == 3 ) {
        Prod* added = prod->next;
        int position;

        printf(ANSI_MAGENTA "\nEntrer La position voulue >> " ANSI_RESET);
        scanf("%d", &position);

        while(added != prod){
            
            if (position <= 1) {
                product_obj->next = added;
                product_obj->prev = added->prev;
                product_obj->prev->next = product_obj;
                added->prev = product_obj;
                return prod;
            }

            position--;
            added = added->next;
        }

        puts(ANSI_RED "\nErreur : position n\'existe pas!!\n" ANSI_RESET);
        return prod;
    }
}