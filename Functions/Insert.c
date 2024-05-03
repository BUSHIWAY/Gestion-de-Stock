#include <stdio.h>
#include "../Headers/Struct.h"
#include "../Headers/colors.h"

// La procédure responsable à insérer la liste des produits au fichier "Stock.txt"
void Insert(Prod *products_list){
    Prod* product_obj = products_list->next;

    // Vérifier si la liste des produits est vide
    if (product_obj != products_list) {

        // Ouvrir le fichier "Stock.txt"
        FILE* file = fopen("Stock/stock.txt", "w");
        
        // Vérifier si le fichier "Stock.txt" est ouvert
        if (file == NULL) {
            puts(ANSI_YELLOW "\n\nWarning : Impossible d\'acceder au fichier (la liste n'a pas ete enregistrer).\n\n" ANSI_RESET);
            fclose(file);
            return;
        }

        // Ecrire chaque produit dans le fichier "Stock.txt" à cette forme
        while (product_obj != products_list) {
            fprintf(file, "*******************************\n");
            fprintf(file, "ID:\n");
            fprintf(file, "%d\n", product_obj->id);
            fprintf(file, "Nom:\n");
            fprintf(file, "%s", product_obj->name);
            fprintf(file, "Description:\n");
            fprintf(file, "%s", product_obj->Description);
            fprintf(file, "Nom de L\'utilisateur:\n");
            fprintf(file, "%s", product_obj->Username);
            fprintf(file, "PRIX:\n");
            fprintf(file, "%d\n", product_obj->price);
            fprintf(file, "Quantite:\n");
            fprintf(file, "%d\n", product_obj->Quantity);
            fprintf(file, "Seuil d\'alerte de stock:\n");
            fprintf(file, "%d\n", product_obj->Quantity);
            fprintf(file, "Date de derniere entree de stock:\n");
            fprintf(file, "%d\n", product_obj->d_last_enter.day);
            fprintf(file, "%d\n", product_obj->d_last_enter.month);
            fprintf(file, "%d\n", product_obj->d_last_enter.year);
            fprintf(file, "Date de derniere sortie de stock:\n");
            fprintf(file, "%d\n", product_obj->d_last_exit.day);
            fprintf(file, "%d\n", product_obj->d_last_exit.month);
            fprintf(file, "%d\n", product_obj->d_last_exit.year);

            product_obj = product_obj->next;
        }
        
        fclose(file);
        puts(ANSI_GREEN "\n\nProduit ajoute au fichier avec succes.\n\n" ANSI_RESET); 
    }



}