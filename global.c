#include <stdio.h>

#include <string.h>



#define TAILLE_COM 250



void interpreteur_commande(char commande[TAILLE_COM]);

void suppression(Client clients[], int *taille);



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

void suppression(Client clients[], int *taille) {

    int id_suppression, index = -1;



    printf("Quelle est l'ID de la ligne que vous voulez supprimer ? ");

    scanf("%d", &id_suppression);



    // Validation de l'ID

    if (id_suppression < 1) {

        printf("Erreur : l'ID doit être supérieur à 0.\n");

        return;

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

        return;

    }

    printf("La ligne avec l'ID %d a été supprimé avec succès.\n", id_suppression);

}

// Fonction pour supprimer une ligne de la table transaction

void suppression(Client clients[], int *taille) {

    int id_suppression, index = -1;



    printf("Quelle est l'ID du client que vous voulez supprimer ? ");

    scanf("%d", &id_suppression);



    // Validation de l'ID

    if (id_suppression < 1) {

        printf("Erreur : l'ID doit être supérieur à 0.\n");

        return;

    }



    // Rechercher l'index du client à supprimer

    for (int i = 0; i < *taille; i++) {

        if (clients[i].id == id_suppression) {

            index = i;

            break;

        }

    }



    // Si l'ID n'est pas trouvé

    if (index == -1) {

        printf("Erreur : Aucun client trouvé avec l'ID %d.\n", id_suppression);

        return;

    }

    printf("Le client avec l'ID %d a été supprimé avec succès.\n", id_suppression);

}

// Fonction pour supprimer un client de la table

void suppression(Client clients[], int *taille) {

    int id_suppression, index = -1;



    printf("Quelle est l'ID du client que vous voulez supprimer ? ");

    scanf("%d", &id_suppression);



    // Validation de l'ID

    if (id_suppression < 1) {

        printf("Erreur : l'ID doit être supérieur à 0.\n");

        return;

    }



    // Rechercher l'index du client à supprimer

    for (int i = 0; i < *taille; i++) {

        if (clients[i].id == id_suppression) {

            index = i;

            break;

        }

    }



    // Si l'ID n'est pas trouvé

    if (index == -1) {

        printf("Erreur : Aucun client trouvé avec l'ID %d.\n", id_suppression);

        return;

    }

    printf("Le client avec l'ID %d a été supprimé avec succès.\n", id_suppression);

}
