#include<stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100

void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

void rechercherClient(Client clients[], int taille) {
    char nomRecherche[MAX_LENGTH];
    char nomTemp[MAX_LENGTH];
    int trouve = 0;

    printf("Entrez le nom du client à rechercher (insensible à la casse) : ");
    scanf("%s", nomRecherche);

    // Convertir le nom recherché en minuscules
    toLowerCase(nomRecherche);

    // Parcourir le tableau des clients
    for (int i = 0; i < taille; i++) {
        // Copier le nom du client pour le comparer en minuscules
        strcpy(nomTemp, clients[i].nom);
        toLowerCase(nomTemp);

        if (strcmp(nomTemp, nomRecherche) == 0) {
            // Si une correspondance est trouvée, afficher le client
            printf("\nClient trouvé :\n");
            printf("ID: %d\n", clients[i].id);
            printf("Nom: %s\n", clients[i].nom);
            printf("Prénom: %s\n", clients[i].prenom);
            printf("Adresse: %s\n", clients[i].adresse);
            printf("Téléphone: %s\n", clients[i].telephone);
            printf("Email: %s\n", clients[i].email);
            printf("Location: %s\n", clients[i].location ? "Oui" : "Non");
            printf("Achat: %s\n", clients[i].achat ? "Oui" : "Non");
            trouve = 1;
        }
    }

    if (!trouve) {
        printf("Erreur : Aucun client trouvé avec ce nom.\n");
    }
}
