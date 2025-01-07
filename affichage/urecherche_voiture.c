#include <stdio.h>

// Recherche dans le tableau des voitures par immatriculation
void rechercherVoiture(Voiture voitures[], int taille) {
    char immatriculation[MAX_LENGTH];
    printf("Entrez l'immatriculation de la voiture à rechercher : ");
    scanf("%s", immatriculation);

    for (int i = 0; i < taille; i++) {
        if (strcmp(voitures[i].immatriculation, immatriculation) == 0) {
            printf("Voiture trouvée :\n");
            printf("Immatriculation: %s, Marque: %s, Modèle: %s, Année: %d, Kilométrage: %d km, Prix Vente: %d€, Prix Location/Jour: %d€, CT: %s, Statut: %s, Puissance: %d ch\n",
                   voitures[i].immatriculation,
                   voitures[i].marque,
                   voitures[i].modele,
                   voitures[i].annee,
                   voitures[i].kilometrage,
                   voitures[i].prix_vente,
                   voitures[i].prix_location_par_jour,
                   voitures[i].controle_technique,
                   voitures[i].statut ? "Disponible" : "Vendu",
                   voitures[i].puissance);
            return;
        }
    }
    printf("Erreur : Aucune voiture trouvée avec l'immatriculation '%s'.\n", immatriculation);