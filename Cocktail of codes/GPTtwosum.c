#include <stdio.h>
#include <stdlib.h>

int main() {
    int target = 0, i, j, n = 0, found = 0;

    printf("Quelle est la longueur de votre tableau ?\n");
    scanf("%d", &n);

    if (n <= 1) {
        printf("La longueur du tableau doit être au moins 2.\n");
        return 1;
    }

    int nums[n];

    // Remplissage du tableau
    for (i = 0; i < n; i++) {
        printf("Donnez le nombre %d du tableau : ", i + 1);
        scanf("%d", &nums[i]);
    }

    printf("Quel est votre objectif (target) ?\n");
    scanf("%d", &target);

    // Vérification des paires
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (nums[i] + nums[j] == target) {
                printf("Match trouvé : %d + %d = %d\n", nums[i], nums[j], target);
                found = 1;
            }
        }
    }

    if (!found) {
        printf("Aucune paire ne correspond à l'objectif.\n");
    }

    return 0;
}
