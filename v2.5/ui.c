#include <stdio.h>
#include "database.h"
#include "ui.h"

void afficher_menu_principal(void) {
    printf("\n--- Menu Principal ---\n");
    printf("1. Gestion des clients\n");
    printf("2. Gestion des transactions\n");
    printf("3. Gestion des voitures\n");
    printf("4. Importer les données de simulation\n");
    printf("0. Quitter\n");
    printf("Votre choix : ");
}

void afficher_menu_gestion_clients() {
    printf("\n--- Gestion des Clients ---\n");
    printf("1. Ajouter un client\n");
    printf("2. Afficher les clients\n");
    printf("3. Supprimer un client\n");
    printf("4. Modifier et sauvegarder un client\n");
    printf("0. Retour\n");
    printf("Votre choix : ");
}

void afficher_menu_gestion_transactions() {
    printf("\n--- Gestion des Transactions ---\n");
    printf("1. Ajouter une transaction\n");
    printf("2. Afficher les transactions\n");
    printf("3. Supprimer une transaction\n");
    printf("4. Modifier et sauvegarder une transaction\n");
    printf("0. Retour\n");
    printf("Votre choix : ");
}

void afficher_menu_gestion_voitures() {
    printf("\n--- Gestion des Voitures ---\n");
    printf("1. Ajouter une voiture\n");
    printf("2. Afficher les voitures\n");
    printf("3. Supprimer une voiture\n");
    printf("4. Modifier et sauvegarder une voiture\n");
    printf("0. Retour\n");
    printf("Votre choix : ");
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
        printf("Status: %c, ID: %d, Nom: %s, Prenom: %s, Adresse: %s, Tel: %s, Email: %s, Location: %d, Achat: %d\n",
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
        printf("Status: %c, ID Transaction: %d, ID Client: %d, Immat: %s, Date: %s, Type: %s, Montant: %d\n",
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
        printf("Status: %c, Immat: %s, Marque: %s, Modele: %s, Annee: %d, Km: %d, Prix Vente: %d, Prix Location: %d, Controle Technique: %s, Statut: %d, Puissance: %d\n",
               voiture.status, voiture.immatriculation, voiture.marque, voiture.modele, voiture.annee,
               voiture.kilometrage, voiture.prix_vente, voiture.prix_location_par_jour, voiture.controle_technique,
               voiture.statut, voiture.puissance);
    }

    fclose(f);
}

