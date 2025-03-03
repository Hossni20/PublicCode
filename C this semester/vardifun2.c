#include <stdarg.h>
#include <stdio.h>

int count_candies(int number, ...) {  
    va_list bag;
    va_start(bag, number);
    
    int total = 0;
    for (int i = 0; i < number; i++) {
        total += va_arg(bag, int);
    }
    
    va_end(bag);
    return total;
}

int main() {
    printf("I have %d candies\n", count_candies(3, 1, 2, 3)); // 1 + 2 + 3 = 6
    return 0;
}
