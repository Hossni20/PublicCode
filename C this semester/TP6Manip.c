#include <stdio.h>
#include <stdlib.h>

void SupprimerNegatives(float **T1, float **T2, int *N, int *M) {
    *M = 0;

    // Compter les éléments négatifs
    for (int i = 0; i < *N; i++) {
        if ((*T1)[i] < 0) {
            (*M)++;
        }
    }

    // Allouer T2 et remplir avec les négatifs
    *T2 = malloc(*M * sizeof(float));
    int pos = 0;
    for (int i = 0; i < *N; i++) {
        if ((*T1)[i] < 0) {
            (*T2)[pos++] = (*T1)[i];
        }
    }

    // Réduire T1 pour ne garder que les non-négatifs
    float *T1_temp = malloc((*N - *M) * sizeof(float));
    pos = 0;
    for (int i = 0; i < *N; i++) {
        if ((*T1)[i] >= 0) {
            T1_temp[pos++] = (*T1)[i];
        }
    }

    free(*T1);
    *T1 = T1_temp;
    *N = *N - *M;
}

int main() {
    int N, M;
    float *T1 = NULL, *T2 = NULL;

    printf("Taille du tableau : ");
    scanf("%d", &N);

    T1 = malloc(N * sizeof(float));
    if (!T1) return 1;

    for (int i = 0; i < N; i++) {
        printf("Valeur %d : ", i + 1);
        scanf("%f", &T1[i]);
    }

    SupprimerNegatives(&T1, &T2, &N, &M);

    printf("\nValeurs positives ou nulles :\n");
    for (int i = 0; i < N; i++) {
        printf("%.2f\t", T1[i]);
    }

    printf("\nValeurs négatives :\n");
    for (int i = 0; i < M; i++) {
        printf("%.2f\t", T2[i]);
    }

    free(T1);
    free(T2);
    return 0;
}
