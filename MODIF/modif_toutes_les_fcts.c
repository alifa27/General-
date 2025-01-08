

//Modif de la structure clients, demande a l'user a chaque étape


int modify_client(Client clients[], int id) {
    int size;
    clients = charger_clients(&size); // Charger la liste des clients

    for (int i = 0; i < size; i++) {
        if (clients[i].id == id && clients[i].status == ' ') {
            printf("Modification des informations du client ID %d:\n", id);

            char new_value[MAX_LENGTH];

            // Modifier le nom
            printf("Nom actuel: %s, Nouveau nom: ", clients[i].nom);
            scanf(" %[^\n]", new_value);
            if (strlen(new_value) > 0) {
                strncpy(clients[i].nom, new_value, MAX_LENGTH);
            }

            // Modifier le prénom
            printf("Prénom actuel: %s, Nouveau prénom: ", clients[i].prenom);
            scanf(" %[^\n]", new_value);
            if (strlen(new_value) > 0) {
                strncpy(clients[i].prenom, new_value, MAX_LENGTH);
            }

            // Modifier l'adresse
            printf("Adresse actuelle: %s, Nouvelle adresse: ", clients[i].adresse);
            scanf(" %[^\n]", new_value);
            if (strlen(new_value) > 0) {
                strncpy(clients[i].adresse, new_value, MAX_LENGTH);
            }

            // Modifier le téléphone
            printf("Téléphone actuel: %s, Nouveau téléphone: ", clients[i].telephone);
            scanf(" %[^\n]", new_value);
            if (strlen(new_value) > 0) {
                strncpy(clients[i].telephone, new_value, MAX_LENGTH);
            }

            // Modifier l'email
            printf("Email actuel: %s, Nouvel email: ", clients[i].email);
            scanf(" %[^\n]", new_value);
            if (strlen(new_value) > 0) {
                strncpy(clients[i].email, new_value, MAX_LENGTH);
            }

            // Modifier le statut de location
            printf("Location actuelle: %d, Nouvelle valeur (0 ou 1): ", clients[i].location);
            int new_location;
            scanf("%d", &new_location);
            clients[i].location = new_location;

            // Modifier le statut d'achat
            printf("Achat actuel: %d, Nouvelle valeur (0 ou 1): ", clients[i].achat);
            int new_achat;
            scanf("%d", &new_achat);
            clients[i].achat = new_achat;

            return 1; // Succès
        }
    }
    return 0; // Échec : ID non trouvé ou déjà supprimé
}






//Modif de la structure transaction, sur le modele de la precedente



int modify_transaction(Transaction transactions[], int id_transaction) {
    int size;
    transactions = charger_transactions(&size); // Charger la liste des transactions

    for (int i = 0; i < size; i++) {
        if (transactions[i].id_transaction == id_transaction && transactions[i].status == ' ') {
            printf("Modification des informations de la transaction ID %d:\n", id_transaction);

            char new_value[MAX_LENGTH];

            // Modifier l'ID client
            printf("ID client actuel: %d, Nouvel ID client: ", transactions[i].id_client);
            int new_id_client;
            scanf("%d", &new_id_client);
            transactions[i].id_client = new_id_client;

            // Modifier l'immatriculation de la voiture
            printf("Immatriculation actuelle: %s, Nouvelle immatriculation: ", transactions[i].immatriculation_voiture);
            scanf(" %[^\n]", new_value);
            if (strlen(new_value) > 0) {
                strncpy(transactions[i].immatriculation_voiture, new_value, MAX_LENGTH);
            }

            // Modifier la date de la transaction
            printf("Date actuelle: %s, Nouvelle date: ", transactions[i].date_transaction);
            scanf(" %[^\n]", new_value);
            if (strlen(new_value) > 0) {
                strncpy(transactions[i].date_transaction, new_value, MAX_LENGTH);
            }

            // Modifier le type de transaction
            printf("Type actuel: %s, Nouveau type: ", transactions[i].type_transaction);
            scanf(" %[^\n]", new_value);
            if (strlen(new_value) > 0) {
                strncpy(transactions[i].type_transaction, new_value, MAX_LENGTH);
            }

            // Modifier le montant
            printf("Montant actuel: %d, Nouveau montant: ", transactions[i].montant);
            int new_montant;
            scanf("%d", &new_montant);
            transactions[i].montant = new_montant;

            return 1; // Succès
        }
    }
    return 0; // Échec : ID non trouvé ou déjà supprimé
}


//modif de voitures


int modify_voiture(Voiture voitures[], const char* immatriculation) {
    int size;
    voitures = charger_voitures(&size); // Charger la liste des voitures

    for (int i = 0; i < size; i++) {
        if (strcmp(voitures[i].immatriculation, immatriculation) == 0 && voitures[i].status == ' ') {
            printf("Modification des informations de la voiture avec immatriculation %s:\n", immatriculation);

            char new_value[MAX_LENGTH];

            // Modifier la marque
            printf("Marque actuelle: %s, Nouvelle marque: ", voitures[i].marque);
            scanf(" %[^
]", new_value);
            if (strlen(new_value) > 0) {
                strncpy(voitures[i].marque, new_value, MAX_LENGTH);
            }

            // Modifier le modèle
            printf("Modèle actuel: %s, Nouveau modèle: ", voitures[i].modele);
            scanf(" %[^
]", new_value);
            if (strlen(new_value) > 0) {
                strncpy(voitures[i].modele, new_value, MAX_LENGTH);
            }

            // Modifier l'année
            printf("Année actuelle: %d, Nouvelle année: ", voitures[i].annee);
            int new_annee;
            scanf("%d", &new_annee);
            voitures[i].annee = new_annee;

            // Modifier le kilométrage
            printf("Kilométrage actuel: %d, Nouveau kilométrage: ", voitures[i].kilometrage);
            int new_kilometrage;
            scanf("%d", &new_kilometrage);
            voitures[i].kilometrage = new_kilometrage;

            // Modifier le prix de vente
            printf("Prix de vente actuel: %d, Nouveau prix de vente: ", voitures[i].prix_vente);
            int new_prix_vente;
            scanf("%d", &new_prix_vente);
            voitures[i].prix_vente = new_prix_vente;

            // Modifier le prix de location par jour
            printf("Prix de location actuel: %d, Nouveau prix de location: ", voitures[i].prix_location_par_jour);
            int new_prix_location;
            scanf("%d", &new_prix_location);
            voitures[i].prix_location_par_jour = new_prix_location;

            // Modifier la date du contrôle technique
            printf("Contrôle technique actuel: %s, Nouvelle date: ", voitures[i].controle_technique);
            scanf(" %[^\n]", new_value);
            if (strlen(new_value) > 0) {
                strncpy(voitures[i].controle_technique, new_value, MAX_LENGTH);
            }

            // Modifier le statut
            printf("Statut actuel: %d (1 = disponible, 0 = vendu), Nouveau statut: ", voitures[i].statut);
            int new_statut;
            scanf("%d", &new_statut);
            voitures[i].statut = new_statut;

            // Modifier la puissance
            printf("Puissance actuelle: %d, Nouvelle puissance: ", voitures[i].puissance);
            int new_puissance;
            scanf("%d", &new_puissance);
            voitures[i].puissance = new_puissance;

            return 1; // Succès
        }
    }
    return 0; // Échec : immatriculation non trouvée ou déjà supprimée
}