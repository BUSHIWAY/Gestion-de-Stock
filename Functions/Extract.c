#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Headers/Struct.h"
#include "../Headers/colors.h"

// Fonction sert à extraire les informations du fichiers "Stock.txt" et les mise dans une liste doublement chainée
Prod* Extract(Prod* prod){
    FILE* file = fopen("Stock/stock.txt", "r");

    int counter = 0;
    
    // Vérifier si le fichier "Stock.txt" est ouvert
    if (file == NULL) {
        puts(ANSI_YELLOW "\n\nWarning : Impossible d\'acceder au fichier.\n\n" ANSI_RESET);
        fclose(file);
        return prod;
    }

    // Vérifier si le fichier "Stock.txt" est vide
    fseek(file, 0, SEEK_END);
    int size = ftell(file);
    rewind(file);
    if (size == 0) {
        puts(ANSI_YELLOW "\n\nWarning : Ce fichier est vide.\n\n" ANSI_RESET);
        fclose(file);
        return prod;
    }

    Prod product;
    int index = 0;
    char line[2000];

    // Tant que le fichier "Stock.txt" n'est pas fini extraire les élements des produits de la liste
    while (fgets(line, sizeof(line), file)){
        switch (index){
            case 0:break;
            case 1:
                fgets(line, sizeof(line), file);
                product.id = atoi(line);
                break;
            
            case 2:
                fgets(line, sizeof(line), file);
                strcpy(product.name, line);
                break;

            case 3:
                fgets(line, sizeof(line), file);
                strcpy(product.Description, line);
                break;

            case 4:
                fgets(line, sizeof(line), file);
                strcpy(product.Username, line);
                break;

            case 5:
                fgets(line, sizeof(line), file);
                product.price = atof(line);
                break;

            case 6:
                fgets(line, sizeof(line), file);
                product.Quantity = atoi(line);
                break;

            case 7:
                fgets(line, sizeof(line), file);
                product.Alert_threshold = atoi(line);
                break;

            case 8:
                fgets(line, sizeof(line), file);
                product.d_last_enter.day = atoi(line);
                fgets(line, sizeof(line), file);
                product.d_last_enter.month = atoi(line);
                fgets(line, sizeof(line), file);
                product.d_last_enter.year = atoi(line);
                break;

            case 9:
                fgets(line, sizeof(line), file);
                product.d_last_exit.day = atoi(line);
                fgets(line, sizeof(line), file);
                product.d_last_exit.month = atoi(line);
                fgets(line, sizeof(line), file);
                product.d_last_exit.year = atoi(line);

                // Affecter les valeur extractées à une variable pointeur qui va t-être insérer à la liste chainée
                Prod* product_obj = malloc(sizeof(Prod));
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

                // Insérer le nouveau produit à la fin liste chainée
                product_obj->next = prod;
                product_obj->prev = prod->prev;
                product_obj->prev->next = product_obj;
                prod->prev = product_obj;

                break;

            default:
                index = 0;
                break;
        }

        index++;
    }

    fclose(file);
    return prod;
}