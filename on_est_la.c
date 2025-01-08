#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_LENGTH 100

typedef struct {
    char immatriculation[MAX_LENGTH];
    char marque[MAX_LENGTH];
    char modele[MAX_LENGTH];
    int annee;
    int kilometrage;
    int prix_vente;
    int prix_location_par_jour;
    char controle_technique[MAX_LENGTH];
    int statut; // 1: disponible, 0: vendu
    int puissance;
} Voiture;

typedef struct {
    int id_transaction;
    int id_client;
    char immatriculation_voiture[MAX_LENGTH];
    char date_transaction[MAX_LENGTH];
    char type_transaction[MAX_LENGTH]; // Vente ou Location
    int montant;
} Transaction;

typedef struct {
    int id;
    char nom[MAX_LENGTH];
    char prenom[MAX_LENGTH];
    char adresse[MAX_LENGTH];
    char telephone[MAX_LENGTH];
    char email[MAX_LENGTH];
    int location;
    int achat;
} Client;

// Fonction pour retirer les espaces en début et en fin de chaîne
void trim(char *str) {
    char *start = str;
    while (isspace((unsigned char)*start)) start++; // Supprime les espaces au début
    char *end = str + strlen(str) - 1;
    while (end > start && isspace((unsigned char)*end)) end--; // Supprime les espaces à la fin
    memmove(str, start, end - start + 1);
    str[end - start + 1] = '\0'; // Ajoute le terminateur
}

// Fonction SELECT
void select(const char *query, Voiture *voitures, int nb_voitures, Client *clients, int nb_clients, Transaction *transactions, int nb_transactions) {
    char table[MAX_LENGTH], column[MAX_LENGTH], value[MAX_LENGTH];
    char condition[MAX_LENGTH];

    // Analyse de la commande SQL
    if (sscanf(query, "SELECT * FROM %s WHERE %s = '%[^']'", table, column, value) != 3) {
        printf("Erreur : la commande SQL est mal formatée.\n");
        return;
    }

    trim(table);
    trim(column);
    trim(value);

    printf("Résultats pour la commande : %s\n", query);
    printf("-------------------------------------------------------------------------------\n");

    // Vérifie la table spécifiée
    if (strcasecmp(table, "Voitures") == 0) {
        int found = 0;
        for (int i = 0; i < nb_voitures; i++) {
            if ((strcasecmp(column, "immatriculation") == 0 && strcasecmp(voitures[i].immatriculation, value) == 0) ||
                (strcasecmp(column, "marque") == 0 && strcasecmp(voitures[i].marque, value) == 0) ||
                (strcasecmp(column, "modele") == 0 && strcasecmp(voitures[i].modele, value) == 0)) {
                printf("Voiture %d: %s, %s, %s, Année: %d, Km: %d, Prix Vente: %d\n",
                       i + 1, voitures[i].immatriculation, voitures[i].marque, voitures[i].modele,
                       voitures[i].annee, voitures[i].kilometrage, voitures[i].prix_vente);
                found = 1;
            }
        }
        if (!found) {
            printf("Aucune voiture trouvée pour ce critère.\n");
        }
    } else if (strcasecmp(table, "Clients") == 0) {
        int found = 0;
        for (int i = 0; i < nb_clients; i++) {
            if ((strcasecmp(column, "nom") == 0 && strcasecmp(clients[i].nom, value) == 0) ||
                (strcasecmp(column, "prenom") == 0 && strcasecmp(clients[i].prenom, value) == 0)) {
                printf("Client %d: %s %s, Adresse: %s, Téléphone: %s, Email: %s\n",
                       i + 1, clients[i].nom, clients[i].prenom, clients[i].adresse,
                       clients[i].telephone, clients[i].email);
                found = 1;
            }
        }
        if (!found) {
            printf("Aucun client trouvé pour ce critère.\n");
        }
    } else if (strcasecmp(table, "Transactions") == 0) {
        int found = 0;
        for (int i = 0; i < nb_transactions; i++) {
            if ((strcasecmp(column, "immatriculation_voiture") == 0 &&
                 strcasecmp(transactions[i].immatriculation_voiture, value) == 0) ||
                (strcasecmp(column, "type_transaction") == 0 &&
                 strcasecmp(transactions[i].type_transaction, value) == 0)) {
                printf("Transaction %d: ID Client: %d, Immatriculation: %s, Date: %s, Type: %s, Montant: %d\n",
                       i + 1, transactions[i].id_client, transactions[i].immatriculation_voiture,
                       transactions[i].date_transaction, transactions[i].type_transaction,
                       transactions[i].montant);
                found = 1;
            }
        }
        if (!found) {
            printf("Aucune transaction trouvée pour ce critère.\n");
        }
    } else {
        printf("Erreur : table inconnue '%s'.\n", table);
    }
}

// Fonction principale
int main() {
    Voiture voitures[] = {
        {"DT-315-XT", "Porsche", "Cayman", 2015, 78000, 67000, 800, "09/11/2023", 1, 385},
        {"EH-557-JL", "Porsche", "911 GT3RS", 2016, 65400, 85000, 1200, "01/07/2024", 1, 510},
    };

    Client clients[] = {
        {1, "Dupont", "Theo", "12 allée de la marmotte", "06.19.87.55.49", "dupont.theo@firefox.fr", 1, 0},
        {2, "Jean", "Neymar", "11 rue des abricots", "06.63.27.63.28", "jeanneymar@fatigue.com", 0, 1},
    };

    Transaction transactions[] = {
        {1, 1, "DT-315-XT", "01/01/2023", "Vente", 67000},
        {2, 2, "EH-557-JL", "10/04/2023", "Vente", 85000},
    };

    char query[MAX_LENGTH];
    printf("Entrez votre commande SQL : ");
    fgets(query, sizeof(query), stdin);

    select(query, voitures, 2, clients, 2, transactions, 2);

    return 0;
}
