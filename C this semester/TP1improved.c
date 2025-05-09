#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define struct Model before struct voiture
struct Model {
    char mois[10];
    int an;
};

struct voiture {
    char marque[20];
    char Tcarburant[20];
    float prix;
    struct Model m;
};

int main() {
    struct voiture vt[5];

    // Saisie des informations des voitures
    for (int i = 0; i < 5; i++) {
        printf("Saisir la marque de la voiture %d : ", i + 1);
        scanf("%s", vt[i].marque);

        printf("Saisir le type de carburant de la voiture %d : ", i + 1);
        scanf("%s", vt[i].Tcarburant);

        printf("Saisir le prix de la voiture %d : ", i + 1);
        scanf("%f", &vt[i].prix);

        printf("Saisir le mois de production de la voiture %d : ", i + 1);
        scanf("%s", vt[i].m.mois);

        printf("Saisir l'année de production de la voiture %d : ", i + 1);
        scanf("%d", &vt[i].m.an);
    }

    // Affichage du tableau formaté
    printf("\n+----------------+--------------+--------+------------+------+\n");
    printf("| Marque        | Carburant    | Prix   | Mois Prod  | Année |\n");
    printf("+----------------+--------------+--------+------------+------+\n");

    for (int i = 0; i < 5; i++) {
        printf("| %s | %s | %6.2f | %s | %4d |\n",
               vt[i].marque, vt[i].Tcarburant, vt[i].prix, vt[i].m.mois, vt[i].m.an);
    }

    printf("+----------------+--------------+--------+------------+------+\n");

    return 0;
}
