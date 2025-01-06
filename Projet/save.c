#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void add_clients(Client *clients);
Client* charger_clients(int *taille);

int main() {
    // Exemple d'utilisation
    Client clients[12] = {
        {1, "Dupont", "Theo", "12 allée de la marmotte", "06.19.87.55.49", "dupont.theo@firefox.fr", 1, 0},
        {2, "Jean", "neymar", "11 rue des abricots", "06.63.27.63.28", "jeanneymar@fatigue.com", 0, 1},
        {3, "Elie", "copter", "28 rue sainte cecile", "07.62.85.42.84", "Eliecopter@pilote.tv", 0, 1},
        {4, "Moratille", "marco", "172 rue du val", "07.38.05.81.05", "marco.moratille@goat.fr", 1, 0},
        {5, "Abdelfettah", "Selim", "1 avenue Marc Durando", "06.17.18.19.20", "selim.abdelfettah@solitude.ru", 1, 0},
        {6, "Abdelfettah", "Imene", "1 avenue Marc Durando", "06.07.08.09.10", "imene.abdelfettah@solitude.ru", 1, 1},
        {7, "Abdelfettah", "Karim", "1 avenue Marc Durando", "04.94.32.21.21", "Karim.abdelfettah@solitude.ru", 0, 1},
        {8, "Terry", "Bouraima", "18 rue de la crasse", "07.67.07.44.01", "terry@terry.terry", 1, 1},
        {9, "Garnier", "Luc", "9 boulevard parfum", "06.06.06.06.06", "Lucgarnier90@outlook.com", 1, 0},
        {10, "Lambert", "Julien", "3 impasse aberrante", "07.56.65.65.65", "JulienLambert92780@gmail.com", 1, 1},
        {11, "Chastel", "Baptiste", "137 allée des roses", "07.81.10.02.10", "baptistechastel@gmail.com", 1, 0},
        {12, "Fahs", "Ali", "96 avenue francois cuzin", "07.64.02.32.06", "alilebg@gmail.com", 1, 1},
    };
    
    
    Client newClient = {12, "meh", "Ali", "96 avenue francois cuzin", "07.64.02.32.06", "alilebg@gmail.com", 1, 1};
    add_clients(&newClient);
      
    int taille;  
    Client *clients_chargés = charger_clients(&taille);
    printf("taille : %d\n",taille);
    printf(" : %s\n",clients_chargés[taille-1].nom);

    return 0;
}

void add_clients(Client *clients){
	FILE *fichier_clients = fopen("client.dat", "ab"); 					//ouverture en écriture du fichier clients
	
	
	if (!fichier_clients) {												
        	perror("Erreur lors de l'ouverture du fichier clients");
        	exit(EXIT_FAILURE);
    	}
    	
    	fwrite(clients, sizeof(Client), 1, fichier_clients);			//écriture dans le fichier
    	fclose(fichier_clients);
}

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


