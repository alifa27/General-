#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100
#define MAX_VOITURES 50

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

// Fonction pour insérer une nouvelle voiture dans la liste
Voiture insert_voiture(Voiture voitures[], int *size) {
    if (*size >= MAX_VOITURES) {
        printf("Erreur : la liste des voitures est pleine.\n");
        return (Voiture){"", "", "", 0, 0, 0, 0, "", 0, 0}; // Retourne une structure vide en cas d'erreur
    }

    Voiture new_voiture;

    // Demande les données à l'utilisateur pour remplir la structure
    printf("Entrez l'immatriculation de la voiture : ");
    scanf(" %[^\n]", new_voiture.immatriculation);

    printf("Entrez la marque de la voiture : ");
    scanf(" %[^\n]", new_voiture.marque);

    printf("Entrez le modèle de la voiture : ");
    scanf(" %[^\n]", new_voiture.modele);

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

    // Ajoute la nouvelle voiture au tableau
    voitures[*size] = new_voiture;
    (*size)++;

    // Retourne la structure de la voiture insérée
    return new_voiture;
}

int main() {
    Voiture voitures[MAX_VOITURES]; // Tableau pour stocker les voitures
    int size = 0; // Taille actuelle du tableau

    char continuer = 'o';

    while (continuer == 'o' || continuer == 'O') {
        Voiture nouvelle_voiture = insert_voiture(voitures, &size);

        if (strlen(nouvelle_voiture.immatriculation) != 0) { // Vérifie qu'il n'y a pas eu d'erreur
            printf("Voiture ajoutée avec succès : Immatriculation=%s, Marque=%s, Modèle=%s\n",
                   nouvelle_voiture.immatriculation, nouvelle_voiture.marque, nouvelle_voiture.modele);
        }

        printf("Voulez-vous ajouter une autre voiture ? (o/n) : ");
        scanf(" %c", &continuer);
    }

    printf("\nListe des voitures ajoutées :\n");
    for (int i = 0; i < size; i++) {
        printf("Immatriculation: %s, Marque: %s, Modèle: %s, Année: %d, Kilométrage: %d, Prix Vente: %d, Prix Location: %d, Contrôle Technique: %s, Statut: %d, Puissance: %d\n",
               voitures[i].immatriculation, voitures[i].marque, voitures[i].modele, voitures[i].annee,
               voitures[i].kilometrage, voitures[i].prix_vente, voitures[i].prix_location_par_jour,
               voitures[i].controle_technique, voitures[i].statut, voitures[i].puissance);
    }

    return 0;
}
