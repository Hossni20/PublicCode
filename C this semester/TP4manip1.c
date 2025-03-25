#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int **allouerMatrice(int nl, int nc) {
    int **matrice = (int **)malloc(nl * sizeof(int *)); // LES ADRESSES
    if (matrice == NULL) {
        return 1;
    }
    for (int i = 0; i < nl; i++) {
        matrice[i] = (int *)malloc(nc * sizeof(int)); // LES ENTIERS
        if (matrice[i] == NULL) {
            return 1;
        }
    }
    return matrice;
}


void remplirMatrice(int **matrice, int nl, int nc) {
    for (int i = 0; i < nl; i++) {
        for (int j = 0; j < nc; j++) {
            printf("Entrez la valeur de matrice[%d][%d] :\n", i, j);
            scanf("%d", *(matrice+i)+j); 
        }
    }
}


void afficherMatrice(int **matrice, int nl, int nc) {
    printf("\nMatrice :\n");
    for (int i = 0; i < nl; i++) {
        for (int j = 0; j < nc; j++) {
            printf("%d ", *(*(matrice+i)+j));
        }
        printf("\n");
    }
}


void free_matrix(int **matrice, int nl) {
    for (int i = 0; i < nl; i++) {
        free(matrice[i]); //les entiers
    }
    free(matrice); //les adresses
}


int main() {
    int nl, nc;
    printf("\nEntrez le nombre de lignes : ");
    scanf("%d", &nl);
    printf("Entrez le nombre de colonnes : ");
    scanf("%d", &nc);
    int **matrice = allouerMatrice(nl, nc);
    remplirMatrice(matrice, nl, nc);
    afficherMatrice(matrice, nl, nc);
    free_matrix(matrice, nl);
    return 0;
}