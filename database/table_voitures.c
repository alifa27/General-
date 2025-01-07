#include <stdio.h>

#define MAX_LENGTH 100

typedef struct {
    char immatriculation[MAX_LENGTH];
    char marque[MAX_LENGTH];
    char modele[MAX_LENGTH];
    int annee;
    int kilometrage;
    int prix_vente;
    int prix_location_par_jour;
    char controle_technique[MAX_LENGTH];
    int statut; // 1: disponible, 0: vendu
    int puissance;
} Voiture;

int main() {
    // Liste des voitures
    Voiture voitures[] = {
        {"DT-315-XT", "porsche", "cayman", 2015, 78000, 67000, 800, "09/11/2023", 1, 385},
        {"EW-922-JN", "porsche", "cayman gt4rs", 2018, 23400, 120000, 1000, "0", 0, 510},
        {"EH-557-JL", "porsche", "911 gt3rs", 2016, 65400, 85000, 1200, "01/07/2024", 1, 510},
        {"GP-558-YF", "porsche", "911 gt3rs", 2023, 970, 250000, 1700, "0", 1, 510},
        {"FK-480-CT", "mercedes", "gt63", 2016, 54300, 130000, 1400, "04/07/2024", 1, 509},
        {"HA-687-HZ", "pontiac", "firebird", 1973, 240000, 40000, 600, "0", 0, 350},
        {"WW-631-QE", "mclaren", "senna", 2017, 11892, 1175000, 3500, "07/03/2021", 1, 650},
        {"AB-101-ZX", "ferrari", "488 spider", 2019, 12000, 300000, 1500, "03/05/2023", 1, 670},
        {"CD-202-YZ", "lamborghini", "huracan", 2022, 8000, 280000, 1800, "12/10/2023", 1, 640},
        {"EF-303-XW", "bugatti", "chiron", 2020, 5000, 2500000, 5000, "15/02/2024", 1, 1500},
        {"GH-404-YV", "tesla", "model s plaid", 2021, 20000, 150000, 1200, "20/09/2023", 1, 1020},
        {"IJ-505-WT", "aston martin", "dbs superleggera", 2018, 30000, 250000, 1300, "05/01/2024", 1, 715},
        {"KL-606-ZQ", "bmw", "m5 cs", 2021, 15000, 180000, 1100, "22/06/2023", 1, 635},
        {"MN-707-WR", "audi", "rs6 avant", 2019, 40000, 120000, 900, "01/01/2023", 1, 600},
        {"OP-808-YT", "toyota", "supra", 2020, 18000, 50000, 500, "10/11/2023", 1, 340},
        {"QR-909-XE", "chevrolet", "corvette c8", 2021, 15000, 90000, 700, "11/03/2024", 1, 495},
        {"ST-010-ZW", "ford", "mustang gt", 2017, 60000, 40000, 600, "12/04/2023", 1, 450},
    };

    return 0;
}
