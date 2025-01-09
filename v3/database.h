#ifndef DATABASE_H
#define DATABASE_H

#define MAX_LENGTH 100

// Structure de l'en-tête
typedef struct {
    short lastUpdateYear;      // Année de dernière mise à jour
    short lastUpdateMonth;     // Mois de dernière mise à jour
    short lastUpdateDay;       // Jour de dernière mise à jour
    int nbRecords;             // Nombre d'enregistrements dans le fichier
    short lengthHeader;        // Taille de l'en-tête
    short lengthRecord;        // Taille de l'enregistrement
} Header;

typedef struct {
	char status; 
    int id_transaction;
    int id_client; // Foreign Key vers la table des clients
    char immatriculation_voiture[MAX_LENGTH]; // Foreign Key vers la table des voitures (plaques d'immatriculation)
    char date_transaction[MAX_LENGTH];
    char type_transaction[MAX_LENGTH]; // "Vente" ou "Location"
    int montant; // Montant de la transaction
} Transaction;

typedef struct {
	char status;
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
	char status;
    int id;
    char nom[MAX_LENGTH];
    char prenom[MAX_LENGTH];
    char adresse[MAX_LENGTH];
    char telephone[MAX_LENGTH];
    char email[MAX_LENGTH];
    int location; // boolean (0 ou 1)
    int achat;    // boolean (0 ou 1)
} Client;

#endif
