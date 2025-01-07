#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100
#define MAX_TRANSACTIONS 50

typedef struct {
    int id_transaction;
    int id_client; // Foreign Key vers la table des clients
    char immatriculation_voiture[MAX_LENGTH]; // Foreign Key vers la table des voitures (plaques d'immatriculation)
    char date_transaction[MAX_LENGTH];
    char type_transaction[MAX_LENGTH]; // "Vente" ou "Location"
    int montant; // Montant de la transaction
} Transaction;

// Fonction pour convertir une chaîne en minuscules
void LowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

// Fonction pour insérer une nouvelle transaction dans la liste
Transaction insert_transaction(Transaction transactions[], int *size) {
    if (*size >= MAX_TRANSACTIONS) {
        printf("Erreur : la liste des transactions est pleine.\n");
        return (Transaction){0, 0, "", "", "", 0}; // Retourne une structure vide en cas d'erreur
    }

    Transaction new_transaction;

    // Demande les données à l'utilisateur pour remplir la structure
    printf("Entrez l'ID de la transaction : ");
    scanf("%d", &new_transaction.id_transaction);

    printf("Entrez l'ID du client : ");
    scanf("%d", &new_transaction.id_client);

    printf("Entrez l'immatriculation de la voiture : ");
    scanf(" %[^\n]", new_transaction.immatriculation_voiture);

    printf("Entrez la date de la transaction (JJ/MM/AAAA) : ");
    scanf(" %[^\n]", new_transaction.date_transaction);
    LowerCase(new_transaction.date_transaction); // Convertit en minuscules

    printf("Entrez le type de transaction (Vente ou Location) : ");
    scanf(" %[^\n]", new_transaction.type_transaction);
    LowerCase(new_transaction.type_transaction); // Convertit en minuscules

    printf("Entrez le montant de la transaction : ");
    scanf("%d", &new_transaction.montant);

    // Ajoute la nouvelle transaction au tableau
    transactions[*size] = new_transaction;
    (*size)++;

    // Retourne la structure de la transaction insérée
    return new_transaction;
}

int main() {
    Transaction transactions[MAX_TRANSACTIONS]; // Tableau pour stocker les transactions
    int size = 0; // Taille actuelle du tableau

    char continuer = 'o';

    while (continuer == 'o' || continuer == 'O') {
        Transaction nouvelle_transaction = insert_transaction(transactions, &size);

        if (nouvelle_transaction.id_transaction != 0) { // Vérifie qu'il n'y a pas eu d'erreur
            printf("Transaction ajoutée avec succès : ID=%d, ID Client=%d, Immatriculation=%s\n",
                   nouvelle_transaction.id_transaction, nouvelle_transaction.id_client, nouvelle_transaction.immatriculation_voiture);
        }

        printf("Voulez-vous ajouter une autre transaction ? (o/n) : ");
        scanf(" %c", &continuer);
    }

    printf("\nListe des transactions ajoutées :\n");
    for (int i = 0; i < size; i++) {
        printf("ID Transaction: %d, ID Client: %d, Immatriculation: %s, Date: %s, Type: %s, Montant: %d\n",
               transactions[i].id_transaction, transactions[i].id_client, transactions[i].immatriculation_voiture,
               transactions[i].date_transaction, transactions[i].type_transaction, transactions[i].montant);
    }

    return 0;
}
