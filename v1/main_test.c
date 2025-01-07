#include "edition.h"
#include<stdio.h>

int main() {
    
    inputToStorageC();
    
    inputToStorageT();
    
    inputToStorageV();
      
    int tailleC, tailleT, tailleV;  
    
    Client *clients_chargés = charger_clients(&tailleC);
    printf("tailleC : %d\n",tailleC);
    printf(" : %s\n",clients_chargés[tailleC-1].nom);
    
    Voiture *voitures_chargées = charger_voitures(&tailleV);
    printf("tailleV : %d\n",tailleV);
    printf(" : %s\n",voitures_chargées[tailleV-1].immatriculation);
    
    Transaction *transactions_chargées = charger_transactions(&tailleT);
    printf("tailleT : %d\n",tailleT);
    printf(" : %d\n",transactions_chargées[tailleT-1].id_transaction);

    return 0;
}
