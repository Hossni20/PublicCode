#include <stdio.h>
#include <stdlib.h>

int main() {
    int capacity = 4; // capacité initiale
    int size = 0;     // nombre réel d'éléments
    int input;
    int *table = malloc(capacity * sizeof(int)); // allocation initiale

    if (table == NULL) {
        printf("Erreur d'allocation mémoire.\n");
        return 1;
    }

    printf("Entrez des nombres (0 pour terminer) :\n");
    while (1) {
        scanf("%d", &input);
        if (input == 0)
            break;

        if (size == capacity) {
            // doubler la capacité
            capacity *= 2;
            int *temp = realloc(table, capacity * sizeof(int));
            if (temp == NULL) {
                printf("Erreur de reallocation mémoire.\n");
                free(table);
                return 1;
            }
            table = temp;
        }

        *(table + size) = input;
        size++;
    }

    printf("Vous avez entré %d élément(s) : ", size);
    for (int i = 0; i < size; i++) {
        printf("%d ", table[i]);
    }
    printf("\n");

    free(table);
    return 0;
}
