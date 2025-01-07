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

#endif
