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

// Fonction d'affichage pour le tableau des transactions
void afficherTransactions(Transaction transactions[]) {
    int taille = sizeof(transactions) / sizeof(transactions[0]);
    printf("\nListe des Transactions :\n");
    for (int i = 0; i < taille; i++) {
        printf("ID Transaction: %d, ID Client: %d, Immatriculation Voiture: %s, Date: %s, Type: %s, Montant: %d€\n",
               transactions[i].id_transaction,
               transactions[i].id_client,
               transactions[i].immatriculation_voiture,
               transactions[i].date_transaction,
               transactions[i].type_transaction,
               transactions[i].montant);
    }
}

// Fonction d'affichage pour le tableau des clients
void afficherClients(Client clients[]) {
    int taille = sizeof(clients) / sizeof(clients[0]);
    printf("\nListe des Clients :\n");
    for (int i = 0; i < taille; i++) {
        printf("ID Client: %d, Nom: %s, Prénom: %s, Adresse: %s, Téléphone: %s, Email: %s, Location: %s, Achat: %s\n",
               clients[i].id,
               clients[i].nom,
               clients[i].prenom,
               clients[i].adresse,
               clients[i].telephone,
               clients[i].email,
               clients[i].location ? "Oui" : "Non",
               clients[i].achat ? "Oui" : "Non");