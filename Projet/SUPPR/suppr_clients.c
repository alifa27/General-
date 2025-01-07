#include <stdio.h>
#include <string.h>
#define MAX_LENGTH 100
#define MAX_CLIENTS 50

typedef struct {
    char status; // ' ' for active, '*' for deleted
    int id;
    char nom[MAX_LENGTH];
    char prenom[MAX_LENGTH];
    char adresse[MAX_LENGTH];
    char telephone[MAX_LENGTH];
    char email[MAX_LENGTH];
    int location; // boolean (0 ou 1)
    int achat;    // boolean (0 ou 1)
} Client;

// Fonction pour "supprimer" un client par ID (modifie le champ status)
int delete_client(Client clients[], int size, int id) {
    for (int i = 0; i < size; i++) {
        if (clients[i].id == id && clients[i].status == ' ') {
            clients[i].status = '*'; // Marque comme supprimé
            return 1; // Succès
        }
    }
    return 0; // Échec : ID non trouvé ou déjà supprimé
}

int main() {
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

    int size = 12;
    int id_to_delete;

    printf("Liste initiale des clients :\n");
    for (int i = 0; i < size; i++) {
        printf("Status: %c, ID: %d, Nom: %s, Prénom: %s, Adresse: %s, Téléphone: %s, Email: %s, Location: %d, Achat: %d\n",
               clients[i].status, clients[i].id, clients[i].nom, clients[i].prenom, clients[i].adresse,
               clients[i].telephone, clients[i].email, clients[i].location, clients[i].achat);
    }

    printf("\nEntrez l'ID du client à supprimer : ");
    scanf("%d", &id_to_delete);

    if (delete_client(clients, size, id_to_delete)) {
        printf("\nClient avec l'ID %d supprimé avec succès.\n", id_to_delete);
    } else {
        printf("\nAucun client trouvé avec l'ID %d ou déjà supprimé.\n", id_to_delete);
    }

    printf("\nListe des clients après suppression :\n");
    for (int i = 0; i < size; i++) {
        printf("Status: %c, ID: %d, Nom: %s, Prénom: %s, Adresse: %s, Téléphone: %s, Email: %s, Location: %d, Achat: %d\n",
               clients[i].status, clients[i].id, clients[i].nom, clients[i].prenom, clients[i].adresse,
               clients[i].telephone, clients[i].email, clients[i].location, clients[i].achat);
    }

    return 0;
}
