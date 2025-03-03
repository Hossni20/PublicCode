#include <stdio.h>
#include <stdarg.h>

// Function to calculate the average 
float average(int count, ...) {
    va_list args;
    va_start(args, count);

    int total = 0;
    for (int i = 0; i < count; i++) {
        total += va_arg(args, int);
    }

    va_end(args);
    return (float) total / count; // Corrected division
}

int main() {
    // Call the variadic function | Don't Change this
    printf("%.2f", average(4, 85, 90, 78, 92)); // Output: 86.25

    return 0;
}
