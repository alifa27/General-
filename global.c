#include <stdio.h>
#include <string.h>

#define TAILLE_COM 250

void interpreteur_commande(char commande[TAILLE_COM]);      // Fonction qui permet de récupérer la ligne de commande du terminal et de séparer les différentes composantes




int main() {

    char commande[TAILLE_COM];
    interpreteur_commande(commande);
    return 0;
}

void interpreteur_commande(char commande[TAILLE_COM]) 
{
    char delim[] = " \t\n"; 
    printf("Commande: ");

    if (fgets(commande, TAILLE_COM, stdin) == NULL) {
        printf("Erreur de lecture. Veuillez réessayer.\n");
    }

    token = strtok(commande, delim);    // Division de la commande en tokens

    if (token == NULL) {

        printf("Aucune commande saisie. Veuillez réessayer.\n");
    }

}


