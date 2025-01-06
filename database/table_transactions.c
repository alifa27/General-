#include <stdio.h>

#define MAX_LENGTH 100

typedef struct {
    int id_transaction;
    int id_client; // Foreign Key vers la table des clients
    char immatriculation_voiture[MAX_LENGTH]; // Foreign Key vers la table des voitures (plaques d'immatriculation)
    char date_transaction[MAX_LENGTH];
    char type_transaction[MAX_LENGTH]; // "Vente" ou "Location"
    int montant; // Montant de la transaction
} Transaction;

int main() {
    // Liste des transactions
    Transaction transactions[] = {
        {1, 1, "DT-315-XT", "01/01/2023", "Vente", 67000},
        {2, 2, "FK-480-CT", "15/02/2023", "Vente", 130000},
        {3, 3, "WW-631-QE", "20/03/2023", "Location", 800},
        {4, 4, "EH-557-JL", "10/04/2023", "Vente", 85000},
        {5, 5, "HA-687-HZ", "05/05/2023", "Location", 3500},
        {6, 6, "EW-922-JN", "30/05/2023", "Vente", 120000},
        {7, 7, "QR-909-XE", "12/06/2023", "Location", 1400},
        {8, 8, "GP-558-YF", "01/07/2023", "Location", 1200},
        {9, 9, "WW-631-QE", "14/08/2023", "Vente", 85000},
        {10, 10, "EH-557-JL", "25/09/2023", "Location", 1000},
        {11, 11, "QR-909-XE", "10/10/2023", "Location", 1700},
        {12, 12, "CD-202-YZ", "20/11/2023", "Vente", 280000},
        {13, 14, "AB-101-ZX", "05/12/2023", "Vente", 1175000},
        {14, 15, "KL-606-ZQ", "20/12/2023", "Location", 600},
        {15, 12, "EW-922-JN", "30/12/2023", "Vente", 250000},
    };

    return 0;
}
