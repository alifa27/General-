#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100

typedef struct {
    int id;
    char nom[MAX_LENGTH];
    char prenom[MAX_LENGTH];
    char adresse[MAX_LENGTH];
    char telephone[MAX_LENGTH];
    char email[MAX_LENGTH];
    int location; // boolean (0 ou 1)
    int achat;    // boolean (0 ou 1)
} Client;

typedef struct {
    int id_transaction;
    int id_client; // Foreign Key vers la table des clients
    char immatriculation_voiture[MAX_LENGTH]; // Foreign Key vers la table des voitures (plaques d'immatriculation)
    char date_transaction[MAX_LENGTH];
    char type_transaction[MAX_LENGTH]; // "Vente" ou "Location"
    int montant; // Montant de la transaction
} Transaction;

typedef struct {
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

void LowerCase(char *str);

void inputToStorageC(void);
void inputToStorageT(void);
void inputToStorageV(void);

Client saisi_client(void);
Transaction saisi_transaction(void);
Voiture saisi_voiture(void);

void add_client(Client *client);
void add_transaction(Transaction *transaction);
void add_voiture(Voiture *voiture);

Client* charger_clients(int *taille);
Transaction* charger_transactions(int *taille);
Voiture* charger_voitures(int *taille);

int main() {
    
    inputToStorageC();
    
    inputToStorageT();
    
    inputToStorageV();
      
    int tailleC, tailleT, tailleV;  
    
    Client *clients_chargés = charger_clients(&tailleC);
    printf("tailleC : %d\n",tailleC);
    printf(" : %s\n",clients_chargés[tailleC-1].nom);
    
    Voiture *voitures_chargées = charger_voitures(&tailleV);
    printf("tailleV : %d\n",tailleV);
    printf(" : %s\n",voitures_chargées[tailleV-1].immatriculation);
    
    Transaction *transactions_chargées = charger_transactions(&tailleT);
    printf("tailleT : %d\n",tailleT);
    printf(" : %d\n",transactions_chargées[tailleT-1].id_transaction);

    return 0;
}

/*-----------------------------------------Fonction d'éditions----------------------------------------- */

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

    Transaction new_transaction;

    // Demande les données à l'utilisateur pour remplir la structure
    printf("Entrez l'ID de la transaction : ");
    scanf("%d", &new_transaction.id_transaction);

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
    
    Client new_client;

    // Demande les données qui permette de remplir la structure à l'utilisateur
    printf("Entrez l'ID du client : ");				// AMELIORER AUTO INCREMENT
    scanf("%d", &new_client.id);

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
	FILE *fichier_clients = fopen("client.dat", "ab"); 					//ouverture en écriture du fichier clients
	
	
	if (!fichier_clients) {												
        	perror("Erreur lors de l'ouverture du fichier clients");
        	exit(EXIT_FAILURE);
    	}
    	
    	fwrite(client, sizeof(Client), 1, fichier_clients);			//écriture dans le fichier
    	fclose(fichier_clients);
}

void add_transaction(Transaction *transaction){
	FILE *fichier_transaction = fopen("transaction.dat", "ab"); 					//ouverture en écriture du fichier transaction
	
	
	if (!fichier_transaction) {												
        	perror("Erreur lors de l'ouverture du fichier transaction");
        	exit(EXIT_FAILURE);
    	}
    	
    	fwrite(transaction, sizeof(Transaction), 1, fichier_transaction);			//écriture dans le fichier
    	fclose(fichier_transaction);
}

void add_voiture(Voiture *voiture){
	FILE *fichier_voitures = fopen("voiture.dat", "ab"); 					//ouverture en écriture du fichier voiture
	
	
	if (!fichier_voitures) {												
        	perror("Erreur lors de l'ouverture du fichier voitures");
        	exit(EXIT_FAILURE);
    	}
    	
    	fwrite(voiture, sizeof(Voiture), 1, fichier_voitures);			//écriture dans le fichier
    	fclose(fichier_voitures);
}

/*-------------------------- Fonction pour charger le contenue de la BDD-------------------------------------*/


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

    fseek(fichier_clients, 0, SEEK_END);				//fin du fichier
    long taille_fichier = ftell(fichier_clients);		//taille en octet
    rewind(fichier_clients);

    *taille = taille_fichier / sizeof(Client);			//nombre de block, "taille réelle" du tableau
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

    fseek(fichier_transactions, 0, SEEK_END);				//fin du fichier
    long taille_fichier = ftell(fichier_transactions);		//taille en octet
    rewind(fichier_transactions);

    *taille = taille_fichier / sizeof(Transaction);			//nombre de block, "taille réelle" du tableau
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

    fseek(fichier_voitures, 0, SEEK_END);				//fin du fichier
    long taille_fichier = ftell(fichier_voitures);		//taille en octet
    rewind(fichier_voitures);

    *taille = taille_fichier / sizeof(Voiture);			//nombre de block, "taille réelle" du tableau
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


