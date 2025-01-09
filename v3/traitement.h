#ifndef TRAITEMENT_H
#define TRAITEMENT_H

#include "database.h"

void toUpperCase(char *str);
void toLowerCase(char *str);

void rechercherVoiture(Voiture voitures[], int taille);
void rechercherTransaction(Transaction transactions[], int taille);
void rechercherClient(Client clients[], int taille);

#endif 
