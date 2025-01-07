#include <stdio.h>

#define MAX_LENGTH 100
#define MAX_TRANSACTIONS 50

typedef struct {
    char status; // ' ' for active, '*' for deleted
    int id_transaction;
    int id_client; // Foreign Key vers la table des clients
    char immatriculation_voiture[MAX_LENGTH]; // Foreign Key vers la table des voitures (plaques d'immatriculation)
    char date_transaction[MAX_LENGTH];
    char type_transaction[MAX_LENGTH]; // "Vente" ou "Location"
    int montant; // Montant de la transaction
} Transaction;

// Prototype des fonctions de suppression des structures reliées
void suppr_voitures(const char *immatriculation);
void suppr_clients(int id_client);

// Fonction pour "supprimer" une transaction par ID (modifie le champ status et appelle les fonctions reliées)
int delete_transaction(Transaction transactions[], int size, int id_transaction) {
    for (int i = 0; i < size; i++) {
        if (transactions[i].id_transaction == id_transaction && transactions[i].status == ' ') {
            // Récupère les clés étrangères avant suppression
            int id_client = transactions[i].id_client;
            char immatriculation[MAX_LENGTH];
            snprintf(immatriculation, MAX_LENGTH, "%s", transactions[i].immatriculation_voiture);

            // Marque la transaction comme supprimée
            transactions[i].status = '*';

            // Appelle les fonctions de suppression associées
            suppr_voitures(immatriculation);
            suppr_clients(id_client);

            return 1; // Succès
        }
    }
    return 0; // Échec : transaction non trouvée ou déjà supprimée
}

int main() {
    Transaction transactions[] = {
        {' ', 1, 1, "DT-315-XT", "01/01/2023", "Vente", 67000},
        {' ', 2, 2, "FK-480-CT", "15/02/2023", "Vente", 130000},
        {' ', 3, 3, "WW-631-QE", "20/03/2023", "Location", 800},
        {' ', 4, 4, "EH-557-JL", "10/04/2023", "Vente", 85000},
        {' ', 5, 5, "HA-687-HZ", "05/05/2023", "Location", 3500},
        {' ', 6, 6, "EW-922-JN", "30/05/2023", "Vente", 120000},
        {' ', 7, 7, "QR-909-XE", "12/06/2023", "Location", 1400},
        {' ', 8, 8, "GP-558-YF", "01/07/2023", "Location", 1200},
        {' ', 9, 9, "WW-631-QE", "14/08/2023", "Vente", 85000},
        {' ', 10, 10, "EH-557-JL", "25/09/2023", "Location", 1000},
        {' ', 11, 11, "QR-909-XE", "10/10/2023", "Location", 1700},
        {' ', 12, 12, "CD-202-YZ", "20/11/2023", "Vente", 280000},
        {' ', 13, 5, "AB-101-ZX", "05/12/2023", "Vente", 1175000},
        {' ', 14, 9, "KL-606-ZQ", "20/12/2023", "Location", 600},
        {' ', 15, 12, "EW-922-JN", "30/12/2023", "Vente", 250000},
    };

    int size = 15;
    int id_to_delete;

    printf("Liste initiale des transactions :\n");
    for (int i = 0; i < size; i++) {
        printf("Status: %c, ID Transaction: %d, ID Client: %d, Immatriculation: %s, Date: %s, Type: %s, Montant: %d\n",
               transactions[i].status, transactions[i].id_transaction, transactions[i].id_client,
               transactions[i].immatriculation_voiture, transactions[i].date_transaction,
               transactions[i].type_transaction, transactions[i].montant);
    }

    printf("\nEntrez l'ID de la transaction à supprimer : ");
    scanf("%d", &id_to_delete);

    if (delete_transaction(transactions, size, id_to_delete)) {
        printf("\nTransaction avec l'ID %d supprimée avec succès.\n", id_to_delete);
    } else {
        printf("\nAucune transaction trouvée avec l'ID %d ou déjà supprimée.\n", id_to_delete);
    }

    printf("\nListe des transactions après suppression :\n");
    for (int i = 0; i < size; i++) {
        printf("Status: %c, ID Transaction: %d, ID Client: %d, Immatriculation: %s, Date: %s, Type: %s, Montant: %d\n",
               transactions[i].status, transactions[i].id_transaction, transactions[i].id_client,
               transactions[i].immatriculation_voiture, transactions[i].date_transaction,
               transactions[i].type_transaction, transactions[i].montant);
    }

    return 0;
}
