#include <stdio.h>
#include <stdlib.h>

// Fonction pour calculer la moyenne
float Moyenne(float *tab, int taille) {
    if (taille == 0) 
	return 0.0f;
	else
    {
       float somme = 0.0f;
       for (int i = 0; i < taille; i++) 
      somme += tab[i];
      return somme / taille;
    }
}

// Fonction pour supprimer les valeurs négatives 
void supprimerNegatives(float *T1, int *tailleT1, float *T2, int *tailleT2) {
    // Compter les éléments positives
    int nouvelle_tailleT1 = 0;
    for (int i = 0; i < *tailleT1; i++) {
        if (T1[i] >= 0) nouvelle_tailleT1++;
    }
    *tailleT2 = *tailleT1 - nouvelle_tailleT1;

    // Créer des tableaux temporaires
    float *tempT1 = (float*)malloc(nouvelle_tailleT1 * sizeof(float));
    float *tempT2 = (float*)malloc(*tailleT2 * sizeof(float));

    // Remplir les tableaux temporaires
    int indexT1 = 0, indexT2 = 0;
    for (int i = 0; i < *tailleT1; i++) {
        if (T1[i] >= 0) 
		{ tempT1[indexT1] = T1[i];
	  	  indexT1++;
		}
	        else 
		{ tempT2[indexT2] = T1[i];
		   indexT2++;
		}	
    }
    // Recopier les résultats dans T1 et T2
    for (int i = 0; i < nouvelle_tailleT1; i++)
	  T1[i] = tempT1[i];
    for (int i = 0; i < *tailleT2; i++)
	 T2[i] = tempT2[i];

    *tailleT1 = nouvelle_tailleT1;
    free(tempT1);
    free(tempT2);
}

int main() {
    int tailleT1;
    printf("Entrez la taille du tableau T1 : ");
    scanf("%d", &tailleT1);

    // Allocation des tableaux
    float *T1 = (float*)malloc(tailleT1 * sizeof(float));
    float *T2 = (float*)malloc(tailleT1 * sizeof(float)); // Taille max = tailleT1
    int tailleT2 = 0;

    // Saisie des valeurs
    printf("Saisie des elements de T1 :\n");
    for (int i = 0; i < tailleT1; i++) {
        printf("T1[%d] = ", i);
        scanf("%f", &T1[i]);
    }

    // Suppression des valeurs négatives
    supprimerNegatives (T1, &tailleT1, T2, &tailleT2);

    // Calcul des moyennes
    float moyT1 = Moyenne(T1, tailleT1);
    float moyT2 = Moyenne(T2, tailleT2);

    // Ajout des moyennes (redimensionnement)
    T1 = (float*)realloc(T1, (tailleT1 + 1) * sizeof(float));
    T1[tailleT1] = moyT1;
    tailleT1++;

    T2 = (float*)realloc(T2, (tailleT2 + 1) * sizeof(float));
    T2[tailleT2] = moyT2;
    tailleT2++;

    // Affichage des résultats
    printf("\nT1 (positifs + moyenne) :\n");
    for (int i = 0; i < tailleT1; i++) printf("%.2f ", T1[i]);

    printf("\n\nT2 (negatifs + moyenne) :\n");
    for (int i = 0; i < tailleT2; i++) printf("%.2f ", T2[i]);

    // Libération mémoire
    free(T1);
    free(T2);
    return 0;
}
