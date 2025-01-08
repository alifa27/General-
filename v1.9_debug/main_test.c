#include "edition.h"
#include<stdio.h>
#include <stdlib.h>


void afficher_clients();
void afficher_transactions();
void afficher_voitures();



int main() {

	initialize_header();

    // Initialisation de la base de données
    printf("Initialisation de la base de données...\n");
    ajouter_base_de_donnees();

    // Afficher la base de données avant suppression
    printf("\nBase de données initiale :\n");

    printf("\n=== Clients ===\n");
    afficher_clients();

    printf("\n=== Transactions ===\n");
    afficher_transactions();

    printf("\n=== Voitures ===\n");
    afficher_voitures();

    // Suppression d'un enregistrement (par exemple, un client)
    int id_client_supprime = 3; // ID du client à supprimer
    printf("\nSuppression du client avec ID %d...\n", id_client_supprime);
    deleteToStorageC(id_client_supprime);
    
    // Suppression d'un enregistrement (par exemple, une voiture)
    char id_voiture_supprime[9] = "EH-557-JL"; // ID voiture à supprimer
    printf("\nSuppression voiture avec imm %s...\n", id_voiture_supprime);
    deleteToStorageV(id_voiture_supprime);
    
    // Suppression d'un enregistrement (par exemple, une transaction)
    int id_transaction_supprime = 3; // ID du client à supprimer
    printf("\nSuppression transaction avec ID %d...\n", id_transaction_supprime);
    deleteToStorageT(id_transaction_supprime);

    // Réafficher la base de données après suppression
    printf("\nBase de données après suppression :\n");

    printf("\n=== Clients ===\n");
    afficher_clients();

    printf("\n=== Transactions ===\n");
    afficher_transactions();

    printf("\n=== Voitures ===\n");
    afficher_voitures();

    return 0;
}

void afficher_clients() {
    FILE *f = fopen("client.dat", "rb");
    if (f == NULL) {
        perror("Erreur lors de l'ouverture du fichier clients.txt");
        return;
    }
	
	fseek(f, sizeof(Header), SEEK_SET);
    Client client;
    while (fread(&client, sizeof(Client), 1, f)) {
        printf("Status: %d, ID: %d, Nom: %s, Prenom: %s, Adresse: %s, Tel: %s, Email: %s, Location: %d, Achat: %d\n",
               client.status, client.id, client.nom, client.prenom, client.adresse, client.telephone, client.email,
               client.location, client.achat);
    }

    fclose(f);
}

void afficher_transactions() {
    FILE *f = fopen("transaction.dat", "rb");
    if (f == NULL) {
        perror("Erreur lors de l'ouverture du fichier transactions.txt");
        return;
    }
	fseek(f, sizeof(Header), SEEK_SET);
    Transaction transaction;
    while (fread(&transaction, sizeof(Transaction), 1, f)) {
        printf("Status: %d, ID Transaction: %d, ID Client: %d, Immat: %s, Date: %s, Type: %s, Montant: %d\n",
               transaction.status, transaction.id_transaction, transaction.id_client, transaction.immatriculation_voiture,
               transaction.date_transaction, transaction.type_transaction, transaction.montant);
    }

    fclose(f);
}

void afficher_voitures() {
    FILE *f = fopen("voiture.dat", "rb");
    if (f == NULL) {
        perror("Erreur lors de l'ouverture du fichier voitures.txt");
        return;
    }
	fseek(f, sizeof(Header), SEEK_SET);
    Voiture voiture;
    while (fread(&voiture, sizeof(Voiture), 1, f)) {
        printf("Status: %d, Immat: %s, Marque: %s, Modele: %s, Annee: %d, Km: %d, Prix Vente: %d, Prix Location: %d, Controle Technique: %s, Statut: %d, Puissance: %d\n",
               voiture.status, voiture.immatriculation, voiture.marque, voiture.modele, voiture.annee,
               voiture.kilometrage, voiture.prix_vente, voiture.prix_location_par_jour, voiture.controle_technique,
               voiture.statut, voiture.puissance);
    }

    fclose(f);
}
