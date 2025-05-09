#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int** allouerMatrice(int nl, int nc) {
    int** matrice = malloc(nl * sizeof(int *)); // Allocate rows (adresses)
    if (matrice == NULL) exit(1);

    for (int i = 0; i < nl; i++) {              // the tables have Nb.Col of bits but its limited to the numbers of adresses
        matrice[i] = malloc(nc * sizeof(int));  // Allocate columns for each row
        if (matrice[i] == NULL) {               // "NULL" means it doesn't point to nothing
            
            for (int j = 0; j < i; j++) {
                free(matrice[j]);       // frees the intergers table
            }
            free(matrice);          // frees the adresses table
            exit(1);
        }
    }
    return matrice;
}


void remplirMatrice(int** matrice, int nl, int nc) {
    for (int i = 0; i < nl; i++) {
        for (int j = 0; j < nc; j++) {
            printf("Entrez la valeur de matrice[%d][%d] :\n", i, j);
            scanf("%d", *(matrice+i)+j);        // i just navigates the tables of the integers but j acceses one of them and use it or show it
        }
    }
}


void afficherMatrice(int** matrice, int nl, int nc) {
    printf("\nMatrice :\n");
    for (int i = 0; i < nl; i++) {
        for (int j = 0; j < nc; j++) {
            printf("%d ", *(*(matrice+i)+j)); // les valeurs
        }
        printf("\n");
    }
}


void free_matrix(int** matrice, int nl) {
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
    int** matrice = allouerMatrice(nl, nc);
    remplirMatrice(matrice, nl, nc);
    afficherMatrice(matrice, nl, nc);
    free_matrix(matrice, nl);
    return 0;
}