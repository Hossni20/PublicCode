#include <stdio.h>
#include <stdlib.h>

void SupprimerNegatives(float **T1, float **T2, int *N, int *M) {
    int n = *N;
    float *tempPos = malloc(n * sizeof(float));
    float *tempNeg = malloc(n * sizeof(float));
    int posCount = 0, negCount = 0;

    for (int i = 0; i < n; i++) {
        if ((*T1)[i] < 0) {
            tempNeg[negCount++] = (*T1)[i];
        } else {
            tempPos[posCount++] = (*T1)[i];
        }
    }

    *T1 = realloc(tempPos, posCount * sizeof(float));
    *T2 = realloc(tempNeg, negCount * sizeof(float));

    *N = posCount;
    *M = negCount;
}

int main() {
    int N;
    printf("Saisir la taille du tableau:\n");
    scanf("%d", &N);

    float *TableauT1 = malloc(N * sizeof(float));
    float *TableauT2 = NULL;

    if (TableauT1 == NULL) {
        fprintf(stderr, "Erreur d'allocation\n");
        exit(1);
    }

    for (int i = 0; i < N; i++) {
        printf("Saisir le nombre #%d: ", i + 1);
        scanf("%f", &TableauT1[i]);
    }

    printf("\nTableau original:\n");
    for (int i = 0; i < N; i++) {
        printf("%.2f\t", TableauT1[i]);
    }
    printf("\n");

    int M;
    SupprimerNegatives(&TableauT1, &TableauT2, &N, &M);

    printf("\nValeurs positives ou nulles:\n");
    for (int i = 0; i < N; i++) {
        printf("%.2f\t", TableauT1[i]);
    }

    printf("\nValeurs negatives:\n");
    for (int i = 0; i < M; i++) {
        printf("%.2f\t", TableauT2[i]);
    }

    free(TableauT1);
    free(TableauT2);
    return 0;
}
