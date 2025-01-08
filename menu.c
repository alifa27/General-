#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LENGTH 100
#define MAX_VOITURES 100
#define MAX_CLIENTS 100
#define MAX_TRANSACTIONS 100


void menuPrincipal() {
    int choix;

    do {
        printf("\nMENU PRINCIPAL\n");
        printf("1. Afficher les tableaux\n");
        printf("2. Rechercher\n");
        printf("3. Ajouter\n");
        printf("4. Supprimer\n");
        printf("5. Initialiser les données\n");
        printf("6. Quitter\n");
        printf("Entrez votre choix: ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                printf("\nAfficher quel tableau?\n");
                printf("1. Voitures\n2. Clients\n3. Transactions\n");
                int sousChoix;
                scanf("%d", &sousChoix);
                if (sousChoix == 1) afficherVoitures();
                else if (sousChoix == 2) afficherClients();
                else if (sousChoix == 3) afficherTransactions();
                else printf("Choix invalide.\n");
                break;

            case 2:
                printf("\nFonction de recherche à implémenter...\n");
                break;

            case 3:
                printf("\nFonction d'ajout à implémenter...\n");
                break;

            case 4:
                printf("\nFonction de suppression à implémenter...\n");
                break;

            case 5:
                initialiserDonnees();
                printf("\nDonnées initialisées avec succès!\n");
                break;

            case 6:
                printf("\nAu revoir!\n");
                break;

            default:
                printf("\nChoix invalide.\n");
        }
    } while (choix != 6);
}
