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


/*--------------------------------------------Suppression-----------------------------------------------*/

void deleteToStorageC(int id) {
    FILE *fichier_clients = fopen("client.dat", "r+b");
    if (!fichier_clients) {
        perror("Erreur lors de l'ouverture du fichier clients");
        return;
    }

    Header header;
    fread(&header, sizeof(Header), 1, fichier_clients);

    // Vérifie que l'ID est valide
    if (id < 1 || id > header.nbRecords) {
        printf("ID invalide : %d\n", id);
        fclose(fichier_clients);
        return;
    }

    // Marquer le client comme supprimé
    fseek(fichier_clients, header.lengthHeader + (id - 1) * header.lengthRecord, SEEK_SET);

    Client client;
    fread(&client, sizeof(Client), 1, fichier_clients);
    if (client.status == '*') {
        printf("Le client avec ID %d est déjà supprimé.\n", id);
    } else {
        client.status = '*';
        fseek(fichier_clients, -sizeof(Client), SEEK_CUR);
        fwrite(&client, sizeof(Client), 1, fichier_clients);
        printf("Client avec ID %d supprimé avec succès.\n", id);
    }

    fclose(fichier_clients);
}



void deleteToStorageT(int id_transaction) {
    FILE *fichier_transactions = fopen("transaction.dat", "r+b");
    if (!fichier_transactions) {
        perror("Erreur lors de l'ouverture du fichier transactions");
        return;
    }

    Header header;
    fread(&header, sizeof(Header), 1, fichier_transactions);

    if (id_transaction < 1 || id_transaction > header.nbRecords) {
        printf("ID de transaction invalide : %d\n", id_transaction);
        fclose(fichier_transactions);
        return;
    }

    fseek(fichier_transactions, header.lengthHeader + (id_transaction - 1) * header.lengthRecord, SEEK_SET);

    Transaction transaction;
    fread(&transaction, sizeof(Transaction), 1, fichier_transactions);
    if (transaction.status == '*') {
        printf("La transaction avec ID %d est déjà supprimée.\n", id_transaction);
    } else {
        transaction.status = '*';
        fseek(fichier_transactions, -sizeof(Transaction), SEEK_CUR);
        fwrite(&transaction, sizeof(Transaction), 1, fichier_transactions);
        printf("Transaction avec ID %d supprimée avec succès.\n", id_transaction);
    }

    fclose(fichier_transactions);
}




void deleteToStorageV(const char *immatriculation) {
    FILE *fichier_voitures = fopen("voiture.dat", "r+b");
    if (!fichier_voitures) {
        perror("Erreur lors de l'ouverture du fichier voitures");
        return;
    }

    Header header;
    fread(&header, sizeof(Header), 1, fichier_voitures);

    Voiture voiture;
    int position = -1;

    // Rechercher la voiture par immatriculation
    for (int i = 0; i < header.nbRecords; i++) {
        fread(&voiture, sizeof(Voiture), 1, fichier_voitures);
        if (strcmp(voiture.immatriculation, immatriculation) == 0) {
            position = i;
            break;
        }
    }

    if (position == -1) {
        printf("Aucune voiture trouvée avec l'immatriculation %s.\n", immatriculation);
    } else if (voiture.status == '*') {
        printf("La voiture avec immatriculation %s est déjà supprimée.\n", immatriculation);
    } else {
        voiture.status = '*';
        fseek(fichier_voitures, header.lengthHeader + position * header.lengthRecord, SEEK_SET);
        fwrite(&voiture, sizeof(Voiture), 1, fichier_voitures);
        printf("Voiture avec immatriculation %s supprimée avec succès.\n", immatriculation);
    }

    fclose(fichier_voitures);
}





int delete_client(Client clients[], int id) {
	int size;
	clients = charger_clients(&size);
    for (int i = 0; i < size; i++) {
        if (clients[i].id == id && clients[i].status == ' ') {
            clients[i].status = '*'; // Marque comme supprimé
            return 1; // Succès
        }
    }
    return 0; // Échec : ID non trouvé ou déjà supprimé
}


int delete_transaction(Transaction transactions[], int id_transaction) {
    int size;
	transactions = charger_transactions(&size);    
    for (int i = 0; i < size; i++) {
        if (transactions[i].id_transaction == id_transaction && transactions[i].status == ' ') {
            // Récupère les clés étrangères avant suppression
            //int id_client = transactions[i].id_client;
            //char immatriculation[MAX_LENGTH];
            //snprintf(immatriculation, MAX_LENGTH, "%s", transactions[i].immatriculation_voiture);

            // Marque la transaction comme supprimée
            transactions[i].status = '*';

            // Appelle les fonctions de suppression associées -> on verra plus tard
            //suppr_voitures(immatriculation);
            //suppr_clients(id_client);

            return 1; // Succès
        }
    }
    return 0; // Échec : transaction non trouvée ou déjà supprimée
}

int delete_voiture(Voiture voitures[], const char *immatriculation) {
	int size;
	voitures = charger_voitures(&size); 
    for (int i = 0; i < size; i++) {
        if (strcmp(voitures[i].immatriculation, immatriculation) == 0 && voitures[i].status == ' ') {
            voitures[i].status = '*'; // Marque comme supprimé
            return 1; // Succès
        }
    }
    return 0; // Échec : immatriculation non trouvée ou déjà supprimée
}

void ajouter_base_de_donnees(void) {
    // Clients
    Client clients[] = {
        {' ', 1, "dupont", "theo", "12 allee de la marmotte", "06.19.87.55.49", "dupont.theo@firefox.fr", 1, 0},
        {' ', 2, "jean", "neymar", "11 rue des abricots", "06.63.27.63.28", "jeanneymar@fatigue.com", 0, 1},
        {' ', 3, "elie", "copter", "28 rue sainte cecile", "07.62.85.42.84", "eliecopter@pilote.tv", 0, 1},
        {' ', 4, "moratille", "marco", "172 rue du val", "07.38.05.81.05", "marco.moratille@goat.fr", 1, 0},
        {' ', 5, "abdelfettah", "selim", "1 avenue marc durando", "06.17.18.19.20", "selim.abdelfettah@solitude.ru", 1, 0},
        {' ', 6, "abdelfettah", "imene", "1 avenue marc durando", "06.07.08.09.10", "imene.abdelfettah@maman.selim", 1, 1},
        {' ', 7, "abdelfettah", "karim", "1 avenue marc durando", "04.94.32.21.21", "karim.abdelfettah@papa.selim", 0, 1},
        {' ', 8, "bouraima", "terry", "18 rue de la crasse", "07.67.07.44.01", "terry@terry.terry", 1, 1},
        {' ', 9, "garnier", "luc", "9 boulevard parfum", "06.06.06.06.06", "lucgarnier90@outlook.com", 1, 0},
        {' ', 10, "lambert", "julien", "3 impasse aberrante", "07.56.65.65.65", "julienlambert92780@gmail.com", 1, 1},
        {' ', 11, "chastel", "baptiste", "137 allee des roses", "07.81.10.02.10", "baptistechastel@gmail.com", 1, 0},
        {' ', 12, "fahs", "ali", "96 avenue francois cuzin", "07.64.02.32.06", "alilebg@gmail.com", 1, 1},
    };

    for (int i = 0; i < sizeof(clients) / sizeof(clients[0]); i++) {
        add_client(&clients[i]);
    }

    // Transactions
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

    for (int i = 0; i < sizeof(transactions) / sizeof(transactions[0]); i++) {
        add_transaction(&transactions[i]);
    }

    // Voitures
    Voiture voitures[] = {
        {' ', "DT-315-XT", "Porsche", "Cayman", 2015, 78000, 67000, 800, "09/11/2023", 1, 385},
        {' ', "EW-922-JN", "Porsche", "Cayman GT4RS", 2018, 23400, 120000, 1000, "0", 0, 510},
        {' ', "EH-557-JL", "Porsche", "911 GT3RS", 2016, 65400, 85000, 1200, "01/07/2024", 1, 510},
        {' ', "GP-558-YF", "Porsche", "911 GT3RS", 2023, 970, 250000, 1700, "0", 1, 510},
        {' ', "FK-480-CT", "Mercedes", "GT63", 2016, 54300, 130000, 1400, "04/07/2024", 1, 509},
        {' ', "HA-687-HZ", "Pontiac", "Firebird", 1973, 240000, 40000, 600, "0", 0, 350},
        {' ', "WW-631-QE", "Mclaren", "Senna", 2017, 11892, 1175000, 3500, "07/03/2021", 1, 650},
        {' ', "AB-101-ZX", "Ferrari", "488 Spider", 2019, 12000, 300000, 1500, "03/05/2023", 1, 670},
        {' ', "CD-202-YZ", "Lamborghini", "Huracan", 2022, 8000, 280000, 1800, "12/10/2023", 1, 640},
        {' ', "EF-303-XW", "Bugatti", "Chiron", 2020, 5000, 2500000, 5000, "15/02/2024", 1, 1500},
    };

    for (int i = 0; i < sizeof(voitures) / sizeof(voitures[0]); i++) {
        add_voiture(&voitures[i]);
    }

    printf("Base de données initialisée avec succès !\n");
}

