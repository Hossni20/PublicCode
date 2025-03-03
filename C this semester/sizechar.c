#include <stdio.h>

// Function to print each string in the array on a new line
void printArray(char *arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%s\n", arr[i]);
    }
}

int main() {
    // Declare and initialize the array
    char *languages[] = {"Go", "Java", "React"};

    // Calculate size
    int size = sizeof(languages) / sizeof(languages[0]);

    // Call the function
    printArray(languages, size);

    return 0;
}
