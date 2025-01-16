#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "edition.h"
#include "ui.h"
#include "traitement.h"

int main() {
    initialize_header();
    int choix_principal;
    do {
        afficher_menu_principal();
        scanf("%d", &choix_principal);
        getchar(); // Consomme le saut de ligne restant

        switch (choix_principal) {
            case 1: {
                int choix_clients;
                do {
                    afficher_menu_gestion_clients();
                    scanf("%d", &choix_clients);
                    getchar();

                    switch (choix_clients) {
                        case 1: {
                            Client client = saisi_client();
                            add_client(&client);
                            printf("Client ajouté avec succès.\n");
                            break;
                        }
                        case 2: {
                            printf("Clients chargés depuis la base de données : \n");
                            afficher_clients();
                            break;
                        }
                        case 3: {
                            int id;
                            printf("Entrez l'ID du client à supprimer : ");
                            scanf("%d", &id);
                            deleteToStorageC(id);
                            break;
                        }
                        case 4: {
                            int id;
                            printf("Entrez l'ID du client à modifier : ");
                            scanf("%d", &id);
                            saveToStorageC(id);
                            break;
                        }
                        case 5: {
                        	int taille_clients;
                       		Client *clients = charger_clients(&taille_clients);
                            rechercherClient(clients, taille_clients);
                            break;
                        }
                        case 6: {
			    int taille_clients;
			    Client *clients = charger_clients(&taille_clients);

			    printf("Recherchez un client pour afficher ses transactions associées :\n");
			    rechercherClient(clients, taille_clients);

			    printf("Entrez l'ID du client sélectionné : ");
			    int id_client;
			    scanf("%d", &id_client);

			    int taille_transactions;
			    Transaction *transactions = charger_transactions(&taille_transactions);

			    printf("\n--- Transactions associées au client ID %d ---\n", id_client);
			    int trouve = 0;

			    for (int i = 0; i < taille_transactions; i++) {
				if (transactions[i].id_client == id_client && transactions[i].status != '*') {
				    printf("ID Transaction: %d, Immat: %s, Date: %s, Type: %s, Montant: %d\n",
					   transactions[i].id_transaction, transactions[i].immatriculation_voiture,
					   transactions[i].date_transaction, transactions[i].type_transaction,
					   transactions[i].montant);
				    trouve = 1;
				}
			    }

			    if (!trouve) {
				printf("Aucune transaction associée à ce client.\n");
			    }
			    break;
			}


                        case 0:
                            printf("Retour au menu principal.\n");
                            break;
                        default:
                            printf("Choix invalide, veuillez réessayer.\n");
                    }
                } while (choix_clients != 0);
                break;
            }
            case 2: {
                int choix_transactions;
                do {
                    afficher_menu_gestion_transactions();
                    scanf("%d", &choix_transactions);
                    getchar();

                    switch (choix_transactions) {
                        case 1: {
                            Transaction transaction = saisi_transaction();
                            add_transaction(&transaction);
                            printf("Transaction ajoutée avec succès.\n");
                            break;
                        }
                        case 2: {
                            printf("Transactions chargées depuis la base de données : \n");
                            afficher_transactions();
                            break;
                        }
                        case 3: {
                            int id;
                            printf("Entrez l'ID de la transaction à supprimer : ");
                            scanf("%d", &id);
                            deleteToStorageT(id);
                            break;
                        }
                        case 4: {
                            int id;
                            printf("Entrez l'ID de la transaction à modifier : ");
                            scanf("%d", &id);
                            saveToStorageT(id);
                            break;
                        }
                        case 5: {
                        	int taille_transactions;
                       		Transaction *transactions = charger_transactions(&taille_transactions);
                            rechercherTransaction(transactions, taille_transactions);
                            break;
                        }
                        case 0:
                            printf("Retour au menu principal.\n");
                            break;
                        default:
                            printf("Choix invalide, veuillez réessayer.\n");
                    }
                } while (choix_transactions != 0);
                break;
            }
            case 3: {
                int choix_voitures;
                do {
                    afficher_menu_gestion_voitures();
                    scanf("%d", &choix_voitures);
                    getchar();

                    switch (choix_voitures) {
                        case 1: {
                            Voiture voiture;
                            printf("Entrez les informations de la voiture :\n");
                            printf("Immatriculation : ");
                            scanf(" %s", voiture.immatriculation);
                            printf("Marque : ");
                            scanf(" %s", voiture.marque);
                            printf("Modèle : ");
                            scanf(" %s", voiture.modele);
                            printf("Année : ");
                            scanf("%d", &voiture.annee);
                            printf("Kilométrage : ");
                            scanf("%d", &voiture.kilometrage);
                            printf("Prix de vente : ");
                            scanf("%d", &voiture.prix_vente);
                            printf("Prix de location par jour : ");
                            scanf("%d", &voiture.prix_location_par_jour);
                            printf("Contrôle technique (date) : ");
                            scanf(" %s", voiture.controle_technique);
                            printf("Statut (1: disponible, 0: vendu) : ");
                            scanf("%d", &voiture.statut);
                            voiture.status = ' ';
                            add_voiture(&voiture);
                            printf("Voiture ajoutée avec succès.\n");
                            break;
                        }
                        case 2: {
                            printf("Voitures chargées depuis la base de données : \n");
                            afficher_voitures();
                            break;
                        }
                        case 3: {
                            char immatriculation[MAX_LENGTH];
                            printf("Entrez l'immatriculation de la voiture à supprimer : ");
                            scanf(" %s", immatriculation);
                            deleteToStorageV(immatriculation);
                            break;
                        }
                        case 4: {
                            char immatriculation[MAX_LENGTH];
                            printf("Entrez l'immatriculation de la voiture à modifier : ");
                            scanf(" %s", immatriculation);
                            saveToStorageV(immatriculation);
                            break;
                        }
                        case 5: {
                        	int taille_voitures;
                       		Voiture *voitures = charger_voitures(&taille_voitures);
                            rechercherVoiture(voitures, taille_voitures);
                            break;
                        }
                        case 0:
                            printf("Retour au menu principal.\n");
                            break;
                        default:
                            printf("Choix invalide, veuillez réessayer.\n");
                    }
                } while (choix_voitures != 0);
                break;
            }
            case 4:
                printf("\nAjout des données de simulation...\n");
                ajouter_base_de_donnees();
                printf("Données de simulation ajoutées avec succès.\n");
                break;

            case 0:
                printf("EXIT \n");
                break;

            default:
                printf("Choix invalide, veuillez réessayer.\n");
        }
    } while (choix_principal != 0);

    return 0;
}

