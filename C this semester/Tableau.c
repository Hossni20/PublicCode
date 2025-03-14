#include <stdio.h>
#include <stdlib.h>

int *sommeTableaux(int taille, int *tab1, int *tab2) {
    int *res = (int*)malloc(taille * sizeof(int));
    if (res == NULL) {
        printf("Erreur d'allocation mémoire\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < taille; i++) {
        res[i] = tab1[i] + tab2[i];
    }
    return res;
}

int main() {
    int taille;
    scanf("%d", &taille); // Entrer la taille des tableaux

    int *tab1 = (int*)malloc(taille * sizeof(int));
    int *tab2 = (int*)malloc(taille * sizeof(int));

    if (tab1 == NULL || tab2 == NULL) {
        printf("Erreur d'allocation mémoire\n");
        free(tab1);
        free(tab2);
        return EXIT_FAILURE;
    }

    // Remplissage des tableaux
    for (int i = 0; i < taille; i++) {
        scanf("%d", &tab1[i]);
    }

    for (int i = 0; i < taille; i++) {
        scanf("%d", &tab2[i]);
    }

    int *res = sommeTableaux(taille, tab1, tab2); // Correction de l'appel de la fonction

    // Affichage du résultat
    for (int i = 0; i < taille; i++) {
        printf("%d", res[i]);
    }
    printf("\n");

    // Libération de la mémoire
    free(tab1);
    free(tab2);
    free(res);

    return 0;
}
