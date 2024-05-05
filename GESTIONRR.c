#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Headers/Struct.h"
#include "Headers/colors.h"
#include "Functions/global.h"


// Declarer les Macros qui vont prendre comme valeur les lignes du logo

#define HEAD1 ANSI_MAGENTA "  GGGGG    EEEEEE     SSSSS   TTTTTTT    IIIII     OOOO     N    N     AAAAA     IIIII     RRRRRR      RRRRRR  " ANSI_RESET
#define HEAD2 ANSI_MAGENTA " G         E         S           T         I      O    O    NN   N    A     A      I      R      R    R      R " ANSI_RESET
#define BODY1 ANSI_BLUE    " G         E         S           T         I      O    O    N N  N    A     A      I      R      R    R      R " ANSI_RESET
#define BODY2 ANSI_BLUE    " G  GGG    EEEEE      SSSSS      T         I      O    O    N  N N    AAAAAAA      I      RRRRRRR     RRRRRRR  " ANSI_RESET
#define FOOT1 ANSI_CYAN    " G    G    E               S     T         I      O    O    N   NN    A     A      I      R      R    R      R " ANSI_RESET
#define FOOT2 ANSI_CYAN    "  GGGGG    EEEEEE     SSSSS      T       IIIII     OOOO     N    N    A     A    IIIII    R       R   R       R" ANSI_RESET


// La fonction qui permettre d'initialiser la liste doublement chainée
Prod* Initialize(){
	Prod* p; 
	p = (Prod*)malloc(sizeof(Prod));
	p->prev = p;
	p->next = p;
	return p;	
}

// La procédure qui affiche le menu des commandes valables
void Command () {
    printf(ANSI_CYAN "\n\nVoici les commandes a executer :\n" ANSI_RESET);
    printf(ANSI_MAGENTA "\tAffichage : \n" ANSI_RESET);
    printf(ANSI_BLUE "\t\tA" ANSI_RESET " \t- Pour afficher les donnees des produits de la liste.\n");
    printf(ANSI_BLUE "\t\tA" ANSI_RESET " \t- Pour afficher ce menue.\n");
    printf(ANSI_MAGENTA "\tAjout : \n" ANSI_RESET);
    printf(ANSI_BLUE "\t\t1" ANSI_RESET " \t- Pour ajouter un produit au debut de la liste.\n");
    printf(ANSI_BLUE "\t\t2" ANSI_RESET " \t- Pour ajouter un produit a la fin de la liste.\n");
    printf(ANSI_BLUE "\t\t3" ANSI_RESET " \t- Pour ajouter un produit a une position donnee.\n");
    printf(ANSI_MAGENTA "\tSuppression : \n" ANSI_RESET);
    printf(ANSI_BLUE "\t\t4" ANSI_RESET " \t- Pour Supprimer un produit au debut de la liste.\n");
    printf(ANSI_BLUE "\t\t5" ANSI_RESET " \t- Pour Supprimer un produit a la fin de la liste.\n");
    printf(ANSI_BLUE "\t\t6" ANSI_RESET " \t- Pour Supprimer un produit qui est dans une position donnee\n");
    printf(ANSI_MAGENTA "\tModification : \n" ANSI_RESET);
    printf(ANSI_BLUE "\t\t7" ANSI_RESET " \t- Pour modifier un produit de la liste.\n");
    printf(ANSI_MAGENTA "\tRecherche : \n" ANSI_RESET);
    printf(ANSI_BLUE "\t\t8" ANSI_RESET " \t- Pour chercher un produits selon le nom du produit.\n");
    printf(ANSI_BLUE "\t\t9" ANSI_RESET " \t- Pour chercher un produits selon le nom de l\'utilisateur du produit.\n");
    printf(ANSI_MAGENTA "\tTriage : \n" ANSI_RESET);
    printf(ANSI_BLUE "\t\tN" ANSI_RESET " \t- Pour triee la liste des produits selon le nom des produits.\n");
    printf(ANSI_BLUE "\t\tP" ANSI_RESET " \t- Pour triee la liste des produits selon le prix des produits.\n\n");
    printf(ANSI_RED "\t\tE" ANSI_RESET " \t- Pour Sortir\n");
     
}

// La procédure qui affiche les elements du produit trouvée après la recherche
void printProduct(Prod* Founded_product) {
    printf(ANSI_BLUE "\n*************** Produit Trouvee  ***************\n\n" ANSI_RESET);
    printf("id :" ANSI_CYAN " %d\n" ANSI_RESET, Founded_product->id);
    printf("Nom du produit :"ANSI_CYAN " %s" ANSI_RESET, Founded_product->name);
    printf("description :" ANSI_CYAN " %s" ANSI_RESET, Founded_product->Description);
    printf("Nom d\'utilisateur :"ANSI_CYAN " %s" ANSI_RESET, Founded_product->Username);
    printf("Prix :" ANSI_CYAN " %.2f\n" ANSI_RESET, Founded_product->price);
    printf("Quantite :" ANSI_CYAN " %d\n" ANSI_RESET, Founded_product->Quantity);
    printf("Seuil d\'alerte de stock :" ANSI_CYAN " %d\n" ANSI_RESET, Founded_product->Alert_threshold);
    printf("Date de derniere entree en stock =" ANSI_CYAN " %d/%d/%d\n" ANSI_RESET, Founded_product->d_last_enter.day, Founded_product->d_last_enter.month, Founded_product->d_last_enter.year);
    printf("Date de derniere sortie de stock =" ANSI_CYAN " %d/%d/%d\n" ANSI_RESET, Founded_product->d_last_exit.day, Founded_product->d_last_exit.month, Founded_product->d_last_exit.year);
}

// La fonction principale
int main () {

    // Obtenir le nom de l'utilisateur
    char username[50];
    printf("\nEntrez votre nom >>> ");
    rewind(stdin);
    fgets (username, sizeof(username), stdin);
    printf("\n");

    // Saluer l'utilisateur
    printf("******* Bonjour %s\n\n", username);
    
    // Attendre quelques instant pour le programme commence
    unsigned int i;
    for (i = 0; i < 200000000; i++);

    // Initialisation de la liste doublement chainée et extraire les informations du fichier "Stock.txt"
    Prod* products = Initialize();
    products = Extract(products);

    char command;

    // Affichage du logo
    puts(HEAD1);
    puts(HEAD2);
    puts(BODY1);
    puts(BODY2);
    puts(FOOT1);
    puts(FOOT2);

    // Affichage du menu des commandes
    Command();

    // La boucle qui va traiter les commandes de l'utilisateur
    do {

        // obtenir la commande de l'utilisateur
        command: printf(ANSI_CYAN "\nCommand >>>> " ANSI_RESET);
        rewind(stdin);
        scanf("%c", &command);
        command = toupper(command);


        printf("\n");

        // La recherche de la commande exacte et l'éxecution
        switch (command) {

            // L'éxecution de l'affichage
            case 'A':
                print(products);
                break;

            // L'éxecution des commandes de l'ajout
            //****** Ajout au debut
            case '1':
                products = Add(products, 1);
                printf(ANSI_CYAN "\nProduit est ajouter.\n" ANSI_RESET);
                break;

            //****** Ajout a la fin
            case '2':
                products = Add(products, 2);
                printf(ANSI_CYAN "\nProduit est ajouter.\n" ANSI_RESET);
                break;
            
            //****** Ajout d'un element a une position
            case '3':
                products = Add(products, 3);
                printf(ANSI_CYAN "\nProduit est ajouter.\n" ANSI_RESET);
                break;
            
            // L'éxecution des commandes de la suppression
            //****** Suppression au debut
            case '4':
                products = Delete(products, 1);
                printf(ANSI_CYAN "\nProduit est supprimer.\n" ANSI_RESET);
                break;
            
            //****** Suppression a la fin
            case '5':
                products = Delete(products, 2);
                printf(ANSI_CYAN "\nProduit est supprimer.\n" ANSI_RESET);
                break;
            
            //****** Suppression d'un element d'une position
            case '6':
                products = Delete(products, 3);
                printf(ANSI_CYAN "\nProduit est supprimer.\n" ANSI_RESET);
                break;

            // L'éxecution de la modification
            //****** Modification des elements du produit
            case '7':
                products = Edit(products);
                printf(ANSI_CYAN "\nProduit est modifier.\n" ANSI_RESET);
                break;
            
            // L'éxecution des commandes de la recherche
            //****** Recherche par le nom du produit
            case '8':
                Prod* Founded_product1 = Search(products, 1);
                if (Founded_product1 != products) printProduct(Founded_product1);
                break;
            
            //****** Recherche par le nom de l'utilisateur du produit
            case '9':
                Prod* Founded_product2 = Search(products, 2);
                if (Founded_product2 != products) printProduct(Founded_product2);
                break;

            // L'éxecution des commandes du triage
            //****** Triage par les noms des produits
            case 'N':
                products = Sort(products, 1);
                printf(ANSI_CYAN "\nProduit est triee.\n" ANSI_RESET);
                break;
            
            //****** Triage par les prix des produits
            case 'P':
                products = Sort(products, 2);
                printf(ANSI_CYAN "\nProduit est triee.\n" ANSI_RESET);
                break;
            
            // Sortir du programme
            case 'E': break;

            default:
                printf(ANSI_YELLOW "\nThe command is invalid!!!\n" ANSI_RESET);
                goto command;
        }

    } while (command != 'E');

    // Insérer la liste des produits avant de sortir du programme
    Insert(products);

    free(products);
    return 0;
}
