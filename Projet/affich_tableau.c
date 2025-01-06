/ Fonction d'affichage pour le tableau des clients
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
    }
}
