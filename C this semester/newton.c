#include <stdio.h>
#include <math.h>

// Function f(x) = x - cos(x)
double f(double x) {
    return x - cos(x);
}

// Derivative of f(x), f'(x) = 1 + sin(x)
double df(double x) {
    return 1 + sin(x);
}

// Newton's Method for finding the root of f(x) = 0
double newton_method(double initial_guess, double tolerance, int max_iterations) {
    double x = initial_guess;
    int iteration = 0;
    
    while (iteration < max_iterations) {
        double fx = f(x);
        double dfx = df(x);
        
        if (fabs(fx) < tolerance) {
            printf("\nConverged after %d iterations\n", iteration);
            return x;
        }
        
        x = x - fx / dfx;  // Newton's method formula
        iteration++;
    }
    
    printf("Maximum iterations reached\n");
    return x;  // Return best approximation after max iterations
}

int main() {
    double initial_guess = 0.5;  // Starting guess
    double tolerance = 1e-6;  // Tolerance for convergence
    int max_iterations = 100;  // Maximum iterations
    
    double root = newton_method(initial_guess, tolerance, max_iterations);
    
    printf("Approximate root: %.20f\n", root);
    
    return 0;
}
