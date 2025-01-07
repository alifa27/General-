#include<stdio.h>
#include <string.h>

#define MAX_LENGTH 100

// Recherche dans le tableau des transactions par ID
void rechercherTransaction(Transaction transactions[], int taille) {
    int id_transaction;
    printf("Entrez l'ID de la transaction à rechercher : ");
    scanf("%d", &id_transaction);

    for (int i = 0; i < taille; i++) {
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
