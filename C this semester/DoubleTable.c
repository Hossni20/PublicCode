#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <strings.h> 

int** allouermatrice(int nl,int nc){
    int** matrice=malloc(nl*sizeof(int*));         // don't forget (int*) for tableau d'adresses
    if( matrice==NULL ) {
        free(matrice);
        exit(1);
    }
    for(int i=0;i<nl;i++){
        matrice[i]=malloc(nc*sizeof(int));
        if( matrice[i]==NULL ){                 // you should check every table so you should write "matrice[i]" not "matrice"
            for(int j=0;j<i;j++){               // " j < nc " checks the same colonne again and again, you should check matrice[0] to matrice[i-1]
                free(matrice[i]);
            }
            free(matrice);
            exit(1);
        }
    }
    return matrice;
}                                       // 7/10: still needs to improve

int main(){









    return 0;
}








