#include<stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX_LENGTH 100

// Fonction pour convertir une chaîne en majuscules
void toUpperCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = toupper(str[i]);
    }
}

// Recherche dans le tableau des voitures par plaque d'immatriculation (en majuscules)
void rechercherVoiture(Voiture voitures[], int taille) {
    char plaqueRecherche[MAX_LENGTH];
    char plaqueTemp[MAX_LENGTH];
    int trouve = 0;

    printf("Entrez la plaque d'immatriculation à rechercher (en majuscules) : ");
    scanf("%s", plaqueRecherche);

    // Convertir la plaque recherchée en majuscules
    toUpperCase(plaqueRecherche);

    // Parcourir le tableau des voitures
    for (int i = 0; i < taille; i++) {
        // Copier la plaque de la voiture pour la comparer en majuscules
        strcpy(plaqueTemp, voitures[i].immatriculation);
        toUpperCase(plaqueTemp);

        if (strcmp(plaqueTemp, plaqueRecherche) == 0) {
            // Si une correspondance est trouvée, afficher la voiture
            printf("\nVoiture trouvée :\n");
            printf("Immatriculation: %s\n", voitures[i].immatriculation);
            printf("Marque: %s\n", voitures[i].marque);
            printf("Modèle: %s\n", voitures[i].modele);
            printf("Année: %d\n", voitures[i].annee);
            printf("Kilométrage: %d\n", voitures[i].kilometrage);
            printf("Prix de vente: %d\n", voitures[i].prix_vente);
            printf("Prix location par jour: %d\n", voitures[i].prix_location_par_jour);
            printf("Contrôle technique: %s\n", voitures[i].controle_technique);
            printf("Statut: %s\n", voitures[i].statut ? "Disponible" : "Vendu");
            printf("Puissance: %d\n", voitures[i].puissance);
            trouve = 1;
        }
    }

    if (!trouve) {
        printf("Erreur : Aucune voiture trouvée avec cette plaque.\n");
    }
}
