#include <stdio.h>

int main(){

    char *A = "Petit chode";
    char *B = "Bonjour";
    B=A;
    printf("%s %d %s",A,*B,B); //LE mot "petit chode" est perdue, et le *B pointe vers le contenu premier 'P'

    return 0;
}