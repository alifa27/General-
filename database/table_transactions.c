#include <stdio.h>

#define MAX_LENGTH 100

typedef struct {
    int id_transaction;
    int id_client; // Foreign Key vers la table des clients
    int id_voiture; // Foreign Key vers la table des voitures
    char date_transaction[MAX_LENGTH];
    char type_transaction[MAX_LENGTH]; // "Vente" ou "Location"
    int montant; // Montant de la transaction
} Transaction;

int main() {
    // Liste des transactions
    Transaction transactions[] = {
        {1, 1, 1, "01/01/2023", "Vente", 67000},
        {2, 2, 5, "15/02/2023", "Vente", 130000},
        {3, 3, 6, "20/03/2023", "Location", 800},
        {4, 4, 3, "10/04/2023", "Vente", 85000},
        {5, 5, 12, "05/05/2023", "Location", 3500},
        {6, 6, 2, "30/05/2023", "Vente", 120000},
        {7, 7, 7, "12/06/2023", "Location", 1400},
        {8, 8, 9, "01/07/2023", "Location", 1200},
        {9, 9, 6, "14/08/2023", "Vente", 85000},
        {10, 10, 3, "25/09/2023", "Location", 1000},
        {11, 11, 7, "10/10/2023", "Location", 1700},
        {12, 12, 8, "20/11/2023", "Vente", 280000},
        {13, 14, 10, "05/12/2023", "Vente", 1175000},
        {14, 15, 11, "20/12/2023", "Location", 600},
        {15, 12, 2, "30/12/2023", "Vente", 250000},
    };

    return 0;
}
