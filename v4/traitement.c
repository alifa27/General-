#include "traitement.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Fonction pour convertir une chaîne en majuscules
void toUpperCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = toupper(str[i]);
    }
}

// Fonction pour convertir une chaîne en minuscules
void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

// Recherche dans le tableau des voitures par plaque d'immatriculation (en majuscules)
void rechercherVoiture(Voiture voitures[], int taille) {
    char plaqueRecherche[MAX_LENGTH];
    char plaqueTemp[MAX_LENGTH];
    int trouve = 0;

    printf("Entrez la plaque d'immatriculation à rechercher (en majuscules) : ");
    scanf("%s", plaqueRecherche);

    toUpperCase(plaqueRecherche);

    for (int i = 0; i < taille; i++) {
        if (voitures[i].status == '*') {
            continue; // Ignorer les voitures marquées comme supprimées
        }

        strcpy(plaqueTemp, voitures[i].immatriculation);
        toUpperCase(plaqueTemp);

        if (strcmp(plaqueTemp, plaqueRecherche) == 0) {
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

// Recherche dans le tableau des transactions par ID
void rechercherTransaction(Transaction transactions[], int taille) {
    int id_transaction;
    printf("Entrez l'ID de la transaction à rechercher : ");
    scanf("%d", &id_transaction);

    for (int i = 0; i < taille; i++) {
        if (transactions[i].status == '*') {
            continue; // Ignorer les transactions marquées comme supprimées
        }

        if (transactions[i].id_transaction == id_transaction) {
            printf("Transaction trouvée :\n");
            printf("ID Transaction: %d, ID Client: %d, Immatriculation Voiture: %s, Date: %s, Type: %s, Montant: %d€\n",
                   transactions[i].id_transaction,
                   transactions[i].id_client,
                   transactions[i].immatriculation_voiture,
                   transactions[i].date_transaction,
                   transactions[i].type_transaction,
                   transactions[i].montant);
            return;
        }
    }
    printf("Erreur : Aucune transaction trouvée avec l'ID '%d'.\n", id_transaction);
}

// Recherche dans le tableau des clients par nom (insensible à la casse)
void rechercherClient(Client clients[], int taille) {
    char nomRecherche[MAX_LENGTH];
    char nomTemp[MAX_LENGTH];
    int trouve = 0;

    printf("Entrez le nom du client à rechercher (insensible à la casse) : ");
    scanf("%s", nomRecherche);

    toLowerCase(nomRecherche);

    for (int i = 0; i < taille; i++) {
        if (clients[i].status == '*') {
            continue; // Ignorer les clients marqués comme supprimés
        }

        strcpy(nomTemp, clients[i].nom);
        toLowerCase(nomTemp);

        if (strcmp(nomTemp, nomRecherche) == 0) {
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
