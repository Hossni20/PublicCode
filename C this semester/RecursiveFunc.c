#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

int Fubinacci(int x){
    if (x==0) return 0;
    if (x==1) return 1;
    return Fubinacci(x-1)+Fubinacci(x-2);  // Recursive Function
}
int main(){
    int input;
    printf("Insérez votre nombre :\n");
    scanf("%d", &input);
    printf("Fibonacci(%d) = %d\n", input, Fubinacci(input));
    return 0;
}