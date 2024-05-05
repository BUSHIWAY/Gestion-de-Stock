#include <stdio.h>
#include <stdlib.h>
#include "../Headers/Struct.h"
#include "../Headers/colors.h"


// La fonction responsable à supprimer un produit de la liste
Prod* Delete(Prod* prod, int choice){

    // Vérifier si la liste est vide
	if ( prod->next == prod) {
        puts(ANSI_RED "\nError : Aucun produit a supprimer!\n" ANSI_RESET);
		return prod;
    }
    
    // Vérifier si le produit à supprimer est le premier
	if ( choice == 1 ) {
        Prod* p = prod->next;
		p->prev->next = p->next;
		p->next->prev = p->prev;
		free(p);
		return prod;

    } 
    
    // Vérifier si le produit à supprimer est le dernier
    else if ( choice == 2 ) {
		Prod* p = prod->prev;
		p->prev->next = p->next;
		p->next->prev = p->prev;
		free(p);
		return prod;

    } 
    
    // Vérifier si le choix est de supprimer un produit d'une position donnee
    else if ( choice == 3 ) {
        Prod* deleted = prod->next;
        int position;

        printf(ANSI_MAGENTA "\nEntrer La position voulue >> " ANSI_RESET);
        scanf("%d", &position);

        while(deleted != prod){
            
            if (position <= 1) {
                deleted->prev->next = deleted->next;
                deleted->next->prev = deleted->prev;
                free(deleted);
                return prod;
            }

            position--;
            deleted = deleted->next;
        }
        
        puts("\nError : position n\'existe pas!!\n");
        return prod;
    }     
}
