#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int grade[2][5]; // Tableau pour stocker les notes
    float sum_math = 0, sum_phys = 0; // Variables pour la somme des notes
    
    // Saisie des notes
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 5; j++) {
            printf("Maths est identifié par 0 et Physique par 1.\n");
            printf("Donnez-moi la note %d pour le module %d : ", j + 1, i);
            scanf("%d", &grade[i][j]);

            // Vérification de la validité des notes
            while (grade[i][j] < 0 || grade[i][j] > 20) {
                printf("Erreur : la note doit être entre 0 et 20. Recommencez : ");
                scanf("%d", &grade[i][j]);
            }
        }
    }

    // Calcul de la moyenne
    for (int i = 0; i < 5; i++) {
        sum_math += grade[0][i]; // Somme des notes de maths
        sum_phys += grade[1][i]; // Somme des notes de physique
    }

    float avg_math = sum_math / 5.0;
    float avg_phys = sum_phys / 5.0;

    // Affichage des moyennes
    printf("Votre moyenne en Maths est : %.2f\n", avg_math);
    printf("Votre moyenne en Physique est : %.2f\n", avg_phys);

    return 0;
}
