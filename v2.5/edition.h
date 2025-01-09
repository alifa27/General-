#ifndef EDITION_H
#define EDITION_H
#include "database.h"

void LowerCase(char *str);
void initialize_header(void);
void update_header(char *filename, int nbRecords);

void inputToStorageC(void);
void inputToStorageT(void);
void inputToStorageV(void);

Client saisi_client(void);
Transaction saisi_transaction(void);
Voiture saisi_voiture(void);

void add_client(Client *client);
void add_transaction(Transaction *transaction);
void add_voiture(Voiture *voiture);

Client* charger_clients(int *taille);
Transaction* charger_transactions(int *taille);
Voiture* charger_voitures(int *taille);

int delete_client(Client clients[], int id);
int delete_transaction(Transaction transactions[], int id_transaction);
int delete_voiture(Voiture voitures[], const char *immatriculation);

void deleteToStorageC(int id);
void deleteToStorageT(int id_transaction);
void deleteToStorageV(const char *immatriculation);

void saveToStorageC(int id);
void saveToStorageT(int id_transaction);
void saveToStorageV(const char* immatriculation);

int modify_client(Client clients[], int id, int size);
int modify_transaction(Transaction transactions[], int id_transaction, int size);
int modify_voiture(Voiture voitures[], const char* immatriculation, int size);

void ajouter_base_de_donnees(void);

#endif
