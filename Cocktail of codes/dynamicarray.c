#include <stdio.h>
#include <stdlib.h>

int main() {
    int rows, cols, i, j;
    int **table;

    printf("Enter the number of rows and columns: \n");
    scanf("%d %d", &rows, &cols);

    // Allocate memory for row pointers
    table = (int **)malloc(rows * sizeof(int *));
    if (table == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Allocate memory for each row
    for (i = 0; i < rows; i++) {
        table[i] = (int *)malloc(cols * sizeof(int));
        if (table[i] == NULL) {
            printf("Memory allocation failed!\n");
            return 1;
        }
    }

    // Input elements
    printf("Enter the elements of the table:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%d", &table[i][j]);
        }
    }

    // Print the table
    printf("The table is:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d ", table[i][j]);
        }
        printf("\n");
    }

    // Free memory
    for (i = 0; i < rows; i++) {
        free(table[i]); // Free each row
    }
    free(table); // Free row pointers

    return 0;
}
