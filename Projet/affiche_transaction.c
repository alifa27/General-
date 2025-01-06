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
