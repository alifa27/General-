void afficherVoitures(Voiture voitures[]) {
    int taille = sizeof(voitures) / sizeof(voitures[0]);
    printf("\nListe des Voitures :\n");
    for (int i = 0; i < taille; i++) {
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
    }
}

