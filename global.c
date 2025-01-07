#include <stdio.h>

#include <string.h>



#define TAILLE_COM 250



void interpreteur_commande(char commande[TAILLE_COM]);

Client suppression(Client clients[], int *taille);



int main() {

    char commande[TAILLE_COM];

    suppression(clients, &taille);

    }



    return 0;

}



// Fonction pour lire et interpréter une commande

void interpreteur_commande(char commande[TAILLE_COM]) {

    char delim[] = " \t\n";

    char *token;



    // Lecture de la commande

    printf("Commande: ");

    if (fgets(commande, TAILLE_COM, stdin) == NULL) {

        printf("Erreur de lecture. Veuillez réessayer.\n");

        return;

    }



    // Division de la commande en tokens

    token = strtok(commande, delim);

    if (token == NULL) {

        printf("Aucune commande saisie. Veuillez réessayer.\n");

    }

}



// Fonction pour supprimer une ligne de la table client

Client suppression(Client clients[], int *taille) {

    int id_suppression, index = -1;
    Client new_client;


    printf("Quelle est l'ID de la ligne que vous voulez supprimer ? ");

    scanf("%d", &id_suppression);



    // Validation de l'ID

    if (id_suppression < 1) {

        printf("Erreur : l'ID doit être supérieur à 0.\n");


    }



    // Rechercher l'index de la ligne à supprimer

    for (int i = 0; i < *taille; i++) {

        if (clients[i].id == id_suppression) {

            index = i;

            break;

        }

    }



    // Si l'ID n'est pas trouvé

    if (index == -1) {

        printf("Erreur : Aucune ligne trouvée avec l'ID %d.\n", id_suppression);


    }

    printf("La ligne avec l'ID %d a été supprimé avec succès.\n", id_suppression);
    return new_client
}

// Fonction pour supprimer une ligne de la table transaction

Transaction suppression(Transaction transactions[], int *taille) {

    int id_suppression, index = -1;
    Transaction new_transaction;


    printf("Quelle est l'ID de la ligne que vous voulez supprimer ? ");

    scanf("%d", &id_suppression);



    // Validation de l'ID

    if (id_suppression < 1) {

        printf("Erreur : l'ID doit être supérieur à 0.\n");

      

    }



    // Rechercher l'index de la ligne à supprimer

    for (int i = 0; i < *taille; i++) {

        if (transactions[i].id == id_suppression) {

            index = i;

            break;

        }

    }



    // Si l'ID n'est pas trouvé

    if (index == -1) {

        printf("Erreur : Aucune ligne trouvée avec l'ID %d.\n", id_suppression);

      

    }

    printf("La ligne avec l'ID %d a été supprimé avec succès.\n", id_suppression);
    return new_transaction
}

// Fonction pour supprimer une ligne de la table voitures

Voiture suppression(Voiture voitures[], int *taille) {

    int id_suppression, index = -1;
    Voiture new_voiture;



    printf("Quelle est l'ID de la ligne que vous voulez supprimer ? ");

    scanf("%d", &id_suppression);



    // Validation de l'ID

    if (id_suppression < 1) {

        printf("Erreur : l'ID doit être supérieur à 0.\n");

      

    }



    // Rechercher l'index de la ligne à supprimer

    for (int i = 0; i < *taille; i++) {

        if (voitures[i].id == id_suppression) {

            index = i;

            break;

        }

    }



    // Si l'ID n'est pas trouvé

    if (index == -1) {

        printf("Erreur : Aucune ligne trouvée avec l'ID %d.\n", id_suppression);

      

    }

    printf("La ligne avec l'ID %d a été supprimé avec succès.\n", id_suppression);
    return new_transaction;
}


void COMPARAISON(char token)

{

	char attribut, commande;

		

	if (strcmp(token,FROM) == 0)

		if (FROM(*attribut) == 1)

			if (strcmp(token,id) == 0)

				attribut = id;

			if (strcmp(token,nom) == 0)

				attribut = nom;

			if (strcmp(token,prenom) == 0)

				attribut = prenom;

			if (strcmp(token,adresse) == 0)

				attribut = adresse;

			if (strcmp(token,telephone) == 0)

				attribut = telephone;

			if (strcmp(token,email) == 0)

				attribut = email;

			if (strcmp(token,location) == 0)

				attribut = location;

			if (strcmp(token,achat) == 0)

				attribut = achat;



			else

				printf("Attribut non présent dans la table 1\n");

				

			SELECT(Client clients[]);	

						

			

		if (FROM(*attribut) == 2)

			if (strcmp(token,id) == 0)

				attribut = id;

			if (strcmp(token,nom) == 0)

				attribut = nom;

			if (strcmp(token,prenom) == 0)

				attribut = prenom;

			if (strcmp(token,adresse) == 0)

				attribut = adresse;

			if (strcmp(token,telephone) == 0)

				attribut = telephone;

			if (strcmp(token,email) == 0)

				attribut = email;

			if (strcmp(token,location) == 0)

				attribut = location;

			if (strcmp(token,achat) == 0)

				attribut = achat;

				

			else

				printf("Attribut non présent dans la table 2\n");

				

			SELECT(Transaction transactions[]);

			

		if (FROM(*attribut) == 3)

			if (strcmp(token,id) == 0)

				attribut = id;

			if (strcmp(token,nom) == 0)

				attribut = nom;

			if (strcmp(token,prenom) == 0)

				attribut = prenom;

			if (strcmp(token,adresse) == 0)

				attribut = adresse;

			if (strcmp(token,telephone) == 0)

				attribut = telephone;

			if (strcmp(token,email) == 0)

				attribut = email;

			if (strcmp(token,location) == 0)

				attribut = location;

			if (strcmp(token,achat) == 0)

				attribut = achat;

				

			else

				printf("Attribut non présent dans la table 3\n");	

			

			SELECT(Voiture voitures[]);

		



}
