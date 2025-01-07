#include <stdio.h>

#define MAX_LENGTH 100

typedef struct {
    int id;
    char nom[MAX_LENGTH];
    char prenom[MAX_LENGTH];
    char adresse[MAX_LENGTH];
    char telephone[MAX_LENGTH];
    char email[MAX_LENGTH];
    int location; // boolean (0 ou 1)
    int achat;    // boolean (0 ou 1)
} Client;

int main() {
    // Exemple d'utilisation
    Client clients[] = {
        {1, "dupont", "theo", "12 allee de la marmotte", "06.19.87.55.49", "dupont.theo@firefox.fr", 1, 0},
        {2, "jean", "neymar", "11 rue des abricots", "06.63.27.63.28", "jeanneymar@fatigue.com", 0, 1},
        {3, "elie", "copter", "28 rue sainte cecile", "07.62.85.42.84", "eliecopter@pilote.tv", 0, 1},
        {4, "moratille", "marco", "172 rue du val", "07.38.05.81.05", "marco.moratille@goat.fr", 1, 0},
        {5, "abdelfettah", "selim", "1 avenue marc durando", "06.17.18.19.20", "selim.abdelfettah@solitude.ru", 1, 0},
        {6, "abdelfettah", "imene", "1 avenue marc durando", "06.07.08.09.10", "imene.abdelfettah@maman.selim", 1, 1},
        {7, "abdelfettah", "karim", "1 avenue marc durando", "04.94.32.21.21", "karim.abdelfettah@papa.selim", 0, 1},
        {8, "bouraima", "terry", "18 rue de la crasse", "07.67.07.44.01", "terry@terry.terry", 1, 1},
        {9, "garnier", "luc", "9 boulevard parfum", "06.06.06.06.06", "lucgarnier90@outlook.com", 1, 0},
        {10, "lambert", "julien", "3 impasse aberrante", "07.56.65.65.65", "julienlambert92780@gmail.com", 1, 1},
        {11, "chastel", "baptiste", "137 allee des roses", "07.81.10.02.10", "baptistechastel@gmail.com", 1, 0},
        {12, "fahs", "ali", "96 avenue francois cuzin", "07.64.02.32.06", "alilebg@gmail.com", 1, 1},
    };

    return 0;
}
