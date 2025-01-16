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
    printf("5. Rechercher un client\n");
    printf("6. Afficher les transactions associées à un client\n");
    printf("0. Retour\n");
    printf("Votre choix : ");
}

void afficher_menu_gestion_transactions() {
    printf("\n--- Gestion des Transactions ---\n");
    printf("1. Ajouter une transaction\n");
    printf("2. Afficher les transactions\n");
    printf("3. Supprimer une transaction\n");
    printf("4. Modifier et sauvegarder une transaction\n");
    printf("5. Rechercher une transaction\n"); 
    printf("0. Retour\n");
    printf("Votre choix : ");
}

void afficher_menu_gestion_voitures() {
    printf("\n--- Gestion des Voitures ---\n");
    printf("1. Ajouter une voiture\n");
    printf("2. Afficher les voitures\n");
    printf("3. Supprimer une voiture\n");
    printf("4. Modifier et sauvegarder une voiture\n");
    printf("5. Rechercher une voiture\n"); 
    printf("0. Retour\n");
    printf("Votre choix : ");
}

void afficher_clients() {
    FILE *f = fopen("client.dat", "rb");
    if (f == NULL) {
        perror("Erreur lors de l'ouverture du fichier client.dat");
        return;
    }

    fseek(f, sizeof(Header), SEEK_SET);
    Client client;
    printf("\n--- Liste des Clients ---\n");
    while (fread(&client, sizeof(Client), 1, f)) {
        if (client.status != '*') { // Ignorer les clients supprimés
            printf("ID: %d, Nom: %s, Prénom: %s, Adresse: %s, Téléphone: %s, Email: %s, Location: %d, Achat: %d\n",
                   client.id, client.nom, client.prenom, client.adresse, client.telephone, client.email,
                   client.location, client.achat);
        }
    }

    fclose(f);
}

void afficher_transactions() {
    FILE *f = fopen("transaction.dat", "rb");
    if (f == NULL) {
        perror("Erreur lors de l'ouverture du fichier transaction.dat");
        return;
    }

    fseek(f, sizeof(Header), SEEK_SET);
    Transaction transaction;
    printf("\n--- Liste des Transactions ---\n");
    while (fread(&transaction, sizeof(Transaction), 1, f)) {
        if (transaction.status != '*') { // Ignorer les transactions supprimées
            printf("ID Transaction: %d, ID Client: %d, Immatriculation: %s, Date: %s, Type: %s, Montant: %d\n",
                   transaction.id_transaction, transaction.id_client, transaction.immatriculation_voiture,
                   transaction.date_transaction, transaction.type_transaction, transaction.montant);
        }
    }

    fclose(f);
}

void afficher_voitures() {
    FILE *f = fopen("voiture.dat", "rb");
    if (f == NULL) {
        perror("Erreur lors de l'ouverture du fichier voiture.dat");
        return;
    }

    fseek(f, sizeof(Header), SEEK_SET);
    Voiture voiture;
    printf("\n--- Liste des Voitures ---\n");
    while (fread(&voiture, sizeof(Voiture), 1, f)) {
        if (voiture.status != '*') { 
            printf("Immat: %s, Marque: %s, Modèle: %s, Année: %d, Km: %d, Prix Vente: %d, Prix Location: %d, CT: %s, Statut: %d, Puissance: %d\n",
                   voiture.immatriculation, voiture.marque, voiture.modele, voiture.annee,
                   voiture.kilometrage, voiture.prix_vente, voiture.prix_location_par_jour,
                   voiture.controle_technique, voiture.statut, voiture.puissance);
        }
    }

    fclose(f);
}

