#include <stdio.h>
#include <stdlib.h>

int main(){
    int A,B,*P; /* supposons que ces variables occupent
                la mémoire à partir de l'adresse 1000 */
    A=10;
    B=50;
    P=&A;       //se lit: mettre dans P l'adresse de A
    B=*P;       /*se lit: mettre dans B le contenu de variable pointée par P*/
    *P=20;      /*mettre la valeur 20 dans la variable pointé par P*/
    P=&B;       /*P pointé sur B*/
    return 0;
}