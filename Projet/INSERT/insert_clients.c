#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100
#define MAX_CLIENTS 50

typedef struct {
    int id;
    char nom[MAX_LENGTH];
    char prenom[MAX_LENGTH];
    char adresse[MAX_LENGTH];
    char telephone[MAX_LENGTH];
    char email[MAX_LENGTH];
    int location; // boolean (0 ou 1)
    int achat;    // boolean (0 ou 1)
} Clients;

// Fonction pour insérer un nouveau client dans la liste
Clients insert_client(Clients clients[], int *size) {
    if (*size >= MAX_CLIENTS) {
        printf("Erreur : la liste des clients est pleine.\n");
        return (Clients){0}; // Retourne une structure vide en cas d'erreur
    }
 
    Clients new_client;

    // Demande les données qui permette de remplir la structure à l'utilisateur
    printf("Entrez l'ID du client : ");
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

    // Ajoute le nouveau client au tableau
    clients[*size] = new_client;
    (*size)++;

    // Retourne la structure du client inséré
    return new_client;
}

int main() {
    Clients clients[MAX_CLIENTS]; // Tableau pour stocker les clients
    int size = 0; // Taille actuelle du tableau

    char continuer = 'o';

    while (continuer == 'o' || continuer == 'O') {
        Clients nouveau_client = insert_client(clients, &size);

        if (nouveau_client.id != 0) { // Vérifie qu'il n'y a pas eu d'erreur
            printf("Clients ajouté avec succès : ID=%d, Nom=%s, Prénom=%s\n",
                   nouveau_client.id, nouveau_client.nom, nouveau_client.prenom);
        }

        printf("Voulez-vous ajouter un autre client ? (o/n) : ");
        scanf(" %c", &continuer);
    }

    printf("\nListe des clients ajoutés :\n");
    for (int i = 0; i < size; i++) {
        printf("ID: %d, Nom: %s, Prénom: %s, Adresse: %s, Téléphone: %s, Email: %s, Location: %d, Achat: %d\n",
               clients[i].id, clients[i].nom, clients[i].prenom, clients[i].adresse,
               clients[i].telephone, clients[i].email, clients[i].location, clients[i].achat);
    }

    return 0;
}
