#include "database.h"
#include "edition.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

/*-------------------------------------------Entête-------------------------------------------*/

void initialize_header(void) {
    // Initialiser l'en-tête
    Header header;
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);

    // Remplir l'en-tête
    header.lastUpdateYear = tm->tm_year + 1900; // Année actuelle
    header.lastUpdateMonth = tm->tm_mon + 1;    // Mois actuel
    header.lastUpdateDay = tm->tm_mday;         // Jour actuel
    header.nbRecords = 0;                       // Pas d'enregistrements initialement
    header.lengthHeader = sizeof(Header);       // Taille de l'en-tête
    
    //client
    FILE *fichier_clients = fopen("client.dat", "wb");
    if (!fichier_clients) {
        perror("Erreur d'ouverture du fichier");
        return;
    }
    header.lengthRecord = sizeof(Client);       // Taille d'un enregistrement : Client
    fwrite(&header, sizeof(Header), 1, fichier_clients);
    fclose(fichier_clients);
    
    //transaction
    FILE *fichier_transactions = fopen("transaction.dat", "wb");
    if (!fichier_transactions) {
        perror("Erreur d'ouverture du fichier");
        return;
    }
    header.lengthRecord = sizeof(Transaction);       // Taille d'un enregistrement : Transaction
    fwrite(&header, sizeof(Header), 1, fichier_transactions);
    fclose(fichier_transactions);
    
    //voiture
    FILE *fichier_voitures = fopen("voiture.dat", "wb");
    if (!fichier_voitures) {
        perror("Erreur d'ouverture du fichier");
        return;
    }
    header.lengthRecord = sizeof(Voiture);       // Taille d'un enregistrement : Voiture
    fwrite(&header, sizeof(Header), 1, fichier_voitures);
    fclose(fichier_voitures);
}


void update_header(char *filename, int nbRecords){
    
    FILE *file = fopen(filename, "r+b");

    if (!file) {
        perror("Erreur d'ouverture du fichier");
        return;
    }

    // Lire l'en-tête
    Header header;
    fread(&header, sizeof(Header), 1, file);
    
    // Mettre à jour l'en-tête
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);

    header.lastUpdateYear = tm->tm_year + 1900; // Année actuelle
    header.lastUpdateMonth = tm->tm_mon + 1;    // Mois actuel
    header.lastUpdateDay = tm->tm_mday;         // Jour actuel
    header.nbRecords = nbRecords;               // Mettre à jour le nombre d'enregistrements

    // Revenir au début du fichier pour écrire l'en-tête
    fseek(file, 0, SEEK_SET);

    // Réécrire l'en-tête mis à jour
    fwrite(&header, sizeof(Header), 1, file);

    fclose(file);
}


/*-----------------------------------------Fonction d'éditions-----------------------------------------*/

/* Saisi et sauvergarde :
*	-Clients
*	-Transaction
*	-Voiture
*/

void inputToStorageC(void){
	Client newClient = saisi_client();
	add_client(&newClient);
}

void inputToStorageT(void){
	Transaction newTransaction = saisi_transaction();
	add_transaction(&newTransaction);
}

void inputToStorageV(void){
	Voiture newVoiture = saisi_voiture();
	add_voiture(&newVoiture);
}


/* Saisi par l'utilisateur :
*	-Clients
*	-Transaction
*	-Voiture
*/

// Fonction pour convertir une chaîne en minuscules
void LowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

// Fonction pour insérer une nouvelle voiture dans la liste
Voiture saisi_voiture(void) {

    Voiture new_voiture;

    // Demande les données à l'utilisateur pour remplir la structure
    printf("Entrez l'immatriculation de la voiture : ");
    scanf(" %[^\n]", new_voiture.immatriculation);

    printf("Entrez la marque de la voiture : ");
    scanf(" %[^\n]", new_voiture.marque);
    LowerCase(new_voiture.marque); // Convertit en minuscules

    printf("Entrez le modèle de la voiture : ");
    scanf(" %[^\n]", new_voiture.modele);
    LowerCase(new_voiture.modele); // Convertit en minuscules

    printf("Entrez l'année de la voiture : ");
    scanf("%d", &new_voiture.annee);

    printf("Entrez le kilométrage de la voiture : ");
    scanf("%d", &new_voiture.kilometrage);

    printf("Entrez le prix de vente de la voiture : ");
    scanf("%d", &new_voiture.prix_vente);

    printf("Entrez le prix de location par jour de la voiture : ");
    scanf("%d", &new_voiture.prix_location_par_jour);

    printf("Entrez la date du contrôle technique (JJ/MM/AAAA) : ");
    scanf(" %[^\n]", new_voiture.controle_technique);

    printf("La voiture est-elle disponible ? (1 = oui, 0 = non) : ");
    scanf("%d", &new_voiture.statut);

    printf("Entrez la puissance de la voiture (en chevaux) : ");
    scanf("%d", &new_voiture.puissance);

    // Retourne la structure de la voiture insérée
    return new_voiture;
}


// Fonction pour insérer une nouvelle transaction dans la liste
Transaction saisi_transaction(void) {

	char *filename="transaction.dat";
	FILE *fichier_transactions = fopen(filename, "rb");
	Header header;
    fread(&header, sizeof(Header), 1, fichier_transactions);
    int taille = header.nbRecords;
    fclose(fichier_transactions);	
	
    Transaction new_transaction;

    // Demande les données à l'utilisateur pour remplir la structure
    new_transaction.id_transaction=taille+1;

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

    // Retourne la structure de la transaction insérée
    return new_transaction;
}

// Fonction pour insérer un nouveau client dans la liste
Client saisi_client(void) {

	char *filename="client.dat";
	FILE *fichier_clients = fopen(filename, "rb");
	Header header;
    fread(&header, sizeof(Header), 1, fichier_clients);
    int taille = header.nbRecords;
    fclose(fichier_clients);
    
    Client new_client;

    // Demande les données qui permette de remplir la structure à l'utilisateur
    new_client.id=taille+1;

    printf("Entrez le nom du client : ");
    scanf(" %[^\n]", new_client.nom);

    printf("Entrez le prénom du client : ");
    scanf(" %[^\n]", new_client.prenom);

    printf("Entrez l'adresse du client : ");
    scanf(" %[^\n]", new_client.adresse);

    printf("Entrez le téléphone du client : ");
    scanf(" %[^\n]", new_client.telephone);

    printf("Entrez l'email du client : ");
    scanf(" %[^\n]", new_client.email);

    printf("Le client loue-t-il actuellement une voiture ? (1 = oui, 0 = non) : ");
    scanf("%d", &new_client.location);

    printf("Le client a-t-il acheté une voiture ? (1 = oui, 0 = non) : ");
    scanf("%d", &new_client.achat);

    // Retourne la structure du client inséré
    return new_client;
}


/* Ajout dans la bdd
*	-Clients
*	-Transaction
*	-Voiture
*/

void add_client(Client *client){

	char *filename="client.dat";
	FILE *fichier_clients = fopen(filename, "rb");
	Header header;
    fread(&header, sizeof(Header), 1, fichier_clients);
    int taille = header.nbRecords;
	fclose(fichier_clients);
	
	fichier_clients = fopen(filename, "ab"); 					//ouverture en écriture du fichier clients
	
	
	if (!fichier_clients) {												
        	perror("Erreur lors de l'ouverture du fichier clients");
        	exit(EXIT_FAILURE);
    	}
    	
    	fwrite(client, sizeof(Client), 1, fichier_clients);			//écriture dans le fichier
    	fclose(fichier_clients);
    	update_header(filename, taille+1);
    	
    	
}

void add_transaction(Transaction *transaction){
	char *filename="transaction.dat";
	FILE *fichier_transactions = fopen(filename, "rb");
	Header header;
    fread(&header, sizeof(Header), 1, fichier_transactions);
    int taille = header.nbRecords;
	fclose(fichier_transactions);
	
	fichier_transactions = fopen(filename, "ab"); 					//ouverture en écriture du fichier transaction
	
	
	if (!fichier_transactions) {												
        	perror("Erreur lors de l'ouverture du fichier transaction");
        	exit(EXIT_FAILURE);
    	}
    	
    	fwrite(transaction, sizeof(Transaction), 1, fichier_transactions);			//écriture dans le fichier
    	fclose(fichier_transactions);
    	update_header(filename, taille+1);
}

void add_voiture(Voiture *voiture){
	char *filename="voiture.dat";
	FILE *fichier_voitures = fopen(filename, "rb");
	Header header;
    	fread(&header, sizeof(Header), 1, fichier_voitures);
    	int taille = header.nbRecords;
	
	fichier_voitures = fopen(filename, "ab"); 					//ouverture en écriture du fichier voiture
	
	
	if (!fichier_voitures) {												
        	perror("Erreur lors de l'ouverture du fichier voitures");
        	exit(EXIT_FAILURE);
    	}
    	
    	fwrite(voiture, sizeof(Voiture), 1, fichier_voitures);			//écriture dans le fichier
    	fclose(fichier_voitures);
    	update_header(filename, taille+1);
}

/*-------------------------- Fonction pour charger le contenue de la BDD---------------------------------*/


Client* charger_clients(int *taille) {
/*
*	Fonction qui permet d'importer les clients depuis un fichier
*
*	Il faut passer en paramettre l'adresse memoire d'une variable
*	qui stockera la taille du tableau, utile pour la suite
*/

    FILE *fichier_clients = fopen("client.dat", "rb");	//ouverture en lecture du fichier clients
    if (!fichier_clients) {							
        perror("Erreur lors de l'ouverture du fichier clients");
        *taille = 0;
        return NULL;
    }
    
	Header header;
    fread(&header, sizeof(Header), 1, fichier_clients);
    *taille = header.nbRecords;
    
	fseek(fichier_clients, sizeof(header), SEEK_SET);		//nombre de block, "taille réelle" du tableau
	
    if (*taille == 0) {
        fclose(fichier_clients);
        return NULL; 									// Aucun client dans le fichier
    }

    Client *clients = malloc(*taille * sizeof(Client));	// Allocation dynamique du tableau
    if (!clients) {
        perror("Erreur d'allocation mémoire");
        fclose(fichier_clients);
        *taille = 0;
        return NULL;
    }

    fread(clients, sizeof(Client), *taille, fichier_clients);		//Lecture dans le fichier
    fclose(fichier_clients);

    return clients;
}

Transaction* charger_transactions(int *taille) {
/*
*	Fonction qui permet d'importer les transactions depuis un fichier
*
*	Il faut passer en paramettre l'adresse memoire d'une variable
*	qui stockera la taille du tableau, utile pour la suite
*/

    FILE *fichier_transactions = fopen("transaction.dat", "rb");	//ouverture en lecture du fichier transactions
    if (!fichier_transactions) {							
        perror("Erreur lors de l'ouverture du fichier transactions");
        *taille = 0;
        return NULL;
    }

    Header header;
    fread(&header, sizeof(Header), 1, fichier_transactions);
    *taille = header.nbRecords;
    
	fseek(fichier_transactions, sizeof(header), SEEK_SET);			//nombre de block, "taille réelle" du tableau
    
    if (*taille == 0) {
        fclose(fichier_transactions);
        return NULL; 									// Aucune transaction dans le fichier
    }

    Transaction *transactions = malloc(*taille * sizeof(Transaction));	// Allocation dynamique du tableau
    if (!transactions) {
        perror("Erreur d'allocation mémoire");
        fclose(fichier_transactions);
        *taille = 0;
        return NULL;
    }

    fread(transactions, sizeof(Transaction), *taille, fichier_transactions);		//Lecture dans le fichier
    fclose(fichier_transactions);

    return transactions;
}

Voiture* charger_voitures(int *taille) {
/*
*	Fonction qui permet d'importer les voitures depuis un fichier
*
*	Il faut passer en paramettre l'adresse memoire d'une variable
*	qui stockera la taille du tableau, utile pour la suite
*/

    FILE *fichier_voitures = fopen("voiture.dat", "rb");	//ouverture en lecture du fichier voitures
    if (!fichier_voitures) {							
        perror("Erreur lors de l'ouverture du fichier voitures");
        *taille = 0;
        return NULL;
    }


    Header header;
    fread(&header, sizeof(Header), 1, fichier_voitures);
    *taille = header.nbRecords;
    
	fseek(fichier_voitures, sizeof(header), SEEK_SET);	//nombre de block, "taille réelle" du tableau
    
    if (*taille == 0) {
        fclose(fichier_voitures);
        return NULL; 									// Aucune voiture dans le fichier
    }

    Voiture *voitures = malloc(*taille * sizeof(Voiture));	// Allocation dynamique du tableau
    if (!voitures) {
        perror("Erreur d'allocation mémoire");
        fclose(fichier_voitures);
        *taille = 0;
        return NULL;
    }

    fread(voitures, sizeof(Voiture), *taille, fichier_voitures);		//Lecture dans le fichier
    fclose(fichier_voitures);

    return voitures;
}
