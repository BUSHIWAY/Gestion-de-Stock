#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "../Headers/Struct.h"
#include "../Headers/colors.h"

// La fonction sert à modifier un élement d'un produit de la liste
Prod* Edit(Prod* prod){
    Prod* product_index = prod->next;
    int id;
    char element[50];

    // Vérifier si la liste est vide
    if (prod->next == prod) {
        puts(ANSI_RED "Error: La liste des produits est vide!" ANSI_RESET);
        return prod;
    }

    // Obtenir le produit à modifier via son ID
    printf(ANSI_MAGENTA "\nl\'ID du produit a modifier >> " ANSI_RESET);
    scanf("%d", &id);

    while (product_index != prod) {

        // Si le produit est trouvée accèder cet algorithm
        if (product_index->id == id) {

            // Afficher le menu des élements du produit valable à modifier
            printf(ANSI_BLUE "\n\tid" ANSI_RESET " \t- Pour modifier \n");
            printf(ANSI_BLUE "\tdescription" ANSI_RESET " \t- Pour modifier \n");
            printf(ANSI_BLUE "\tnomproduit" ANSI_RESET " \t- Pour modifier \n");
            printf(ANSI_BLUE "\tnomutilisateur" ANSI_RESET " \t- Pour modifier \n");
            printf(ANSI_BLUE "\tprix" ANSI_RESET " \t- Pour modifier \n");
            printf(ANSI_BLUE "\tquantite" ANSI_RESET " \t- Pour modifier \n");
            printf(ANSI_BLUE "\tseuil" ANSI_RESET " \t- Pour modifier \n");
            printf(ANSI_BLUE "\tdateentree" ANSI_RESET " \t- Pour modifier \n");
            printf(ANSI_BLUE "\tdatesortie" ANSI_RESET " \t- Pour modifier \n");

            // Obtenir l'élement à modifier
            rewind(stdin);
            printf(ANSI_MAGENTA "\nEntrer l\'element que vous voulez modifier >> " ANSI_RESET);
            fgets(element, sizeof(element), stdin);

            // Mettre les lettres du variable élement en miniscule pour une recherche facile 
            for (int i = 0; i < strlen(element); i++) element[i] = tolower(element[i]);


            //**** La recherche du choix de l'utilisateur pour executer
            if (!strcmp(element, "id\n")) {
                printf("\nEntrer le nouveau ID du produit >> ");
                scanf("%d", &product_index->id);

            }
            
            else if (!strcmp(element, "description\n")) {
                printf("Entrer la nouvelle description du produit >> ");
                fgets(product_index->Description, sizeof(product_index->Description), stdin);
            }

            else if (!strcmp(element, "nomproduit\n")) {
                printf("Entrer le nouveau nom du produit >> ");
                fgets(product_index->name, sizeof(product_index->name), stdin);
            }
            
            else if (!strcmp(element, "nomutilisateur\n")) {
                printf("Entrer le nouveau nom d\'utilisateur du produit >> ");
                fgets(product_index->Username, sizeof(product_index->Username), stdin);
            }
            
            else if (!strcmp(element, "prix\n")) {
                printf("Entrer le nouveau prix : ");
                scanf("%f", &product_index->price);
            }
            
            else if (!strcmp(element, "quantite\n")) {
                printf("Entrer la nouvelle quantite >> ");
                scanf("%d", &product_index->Quantity);
            }

            else if (!strcmp(element, "seuil\n")) {
                printf("Entrer le nouveau seuil d'alerte de stock >> ");
                scanf("%d", &product_index->Alert_threshold);
            }
            
            else if (!strcmp(element, "dateentree\n")) {
                printf("Entrer la nouvelle date de derniere entree en stock (sous forme : JJ/MM/AA) >> ");
                scanf("%d/%d/%d", &product_index->d_last_enter.day, &product_index->d_last_enter.month, &product_index->d_last_enter.year);
            }
            
            else if (!strcmp(element, "datesortie\n")) {
                printf("Entrer la nouvelle date de derniere sortie en stock (sous forme : JJ/MM/AA) >> ");
                scanf("%d/%d/%d", &product_index->d_last_exit.day, &product_index->d_last_exit.month, &product_index->d_last_exit.year);
            }
            
            else printf(ANSI_RED "\nErreur : element inconnu!!\n" ANSI_RESET);
            return prod;
        }
        product_index = product_index->next;
    }

    puts(ANSI_RED "\nError : Cet ID n\'existe pas!!\n" ANSI_RESET);
    return prod;
}