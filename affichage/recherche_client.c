#include<stdio.h>


// Recherche dans le tableau des clients par nom
void rechercherClient(Client clients[], int taille) {
    char nom[MAX_LENGTH];
    printf("Entrez le nom du client à rechercher : ");
    scanf("%s", nom);

    for (int i = 0; i < taille; i++) {
        if (strcmp(clients[i].nom, nom) == 0) {
            printf("Client trouvé :\n");
            printf("ID Client: %d, Nom: %s, Prénom: %s, Adresse: %s, Téléphone: %s, Email: %s, Location: %s, Achat: %s\n",
                   clients[i].id,
                   clients[i].nom,
                   clients[i].prenom,
                   clients[i].adresse,
                   clients[i].telephone,
                   clients[i].email,
                   clients[i].location ? "Oui" : "Non",
                   clients[i].achat ? "Oui" : "Non");
            return;
        }
    }
    printf("Erreur : Aucun client trouvé avec le nom '%s'.\n", nom);
}