#include <stdio.h>

int main() {
    char operation;
    float num1, num2, result;

    printf("Enter calculations in the format: operation float float\n");
    printf("Supported operations: +, -, *, /\n");
    printf("Enter 'e' to exit.\n");

    while (1) {
        printf("> ");
        
        // Read the operation and numbers from the user
        int input = scanf(" %c", &operation);

        if (operation == 'e') {
            printf("Exiting calculator.\n");
            break;
        }

        // For operations, read two floats
        if (input == 1 && (operation == '+' || operation == '-' || operation == '*' || operation == '/')) {
            scanf("%f %f", &num1, &num2);
            
            switch (operation) {
                case '+':
                    result = num1 + num2;
                    printf("%.2f\n", result);
                    break;
                case '-':
                    result = num1 - num2;
                    printf("%.2f\n", result);
                    break;
                case '*':
                    result = num1 * num2;
                    printf("%.2f\n", result);
                    break;
                case '/':
                    if (num2 != 0) {
                        result = num1 / num2;
                        printf("%.2f\n", result);
                    } else {
                        printf("Error: Division by zero\n");
                    }
                    break;
                default:
                    printf("Invalid operation.\n");
            }
        } else {
            printf("Invalid input format. Use: operation float float\n");
            while(getchar() != '\n'); // Clear input buffer for invalid input
        }
    }

    return 0;
}

