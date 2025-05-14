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
        *(matrice+i)=malloc(nc*sizeof(int));        // matrice[i]
        if( *(matrice+i)==NULL ){                 // you should check every table so you should write "matrice[i]" not "matrice"
            for(int j=0;j<i;j++){               // " j < nc " checks the same colonne again and again, you should check matrice[0] to matrice[i-1]
                free(*(matrice+i));             // Iterate through previously allocated rows
            }                                   // These j indices represent the rows that were successfully allocated before the current failure.
            free(matrice);
            exit(1);
        }
    }
    return matrice;                      // Hadchi kaml gha bach t3tih espace dans mémoire
}                                       // 7/10: still needs to improve

void remplirmatrice(int** matrice,int nl,int nc){
    for(int i=0;i<nl;i++){
        for(int j=0;j<nc;j++){
            printf("Donner moi la valeur vers tableau du coordonnées [%d][%d]:\n",i,j);
            scanf("%d",*(matrice+i)+j);         // scanf requires only the adresse *(*(matrice+i)+j):c'est la valeur
        }
    }
}

void affichermatrice(int** matrice,int nl,int nc){
    for(int i=0;i<nl;i++){
        for(int j=0;j<nc;j++){
            printf("%d\t",*(*(matrice+i)+j));       // now we do the value *(*(matrice+i)+j)
        }
        printf("\n");
    }
}

void libérermatrice(int** matrice,int nl){
    for(int i=0;i<nl;i++){
        free(*(matrice+i)); // les entiers
    }
    free(matrice); // les adresses
}

int main(){
int nl, nc;
    printf("\nEntrez le nombre de lignes : ");
    scanf("%d", &nl);
    printf("Entrez le nombre de colonnes : ");
    scanf("%d", &nc);
    int** matrice = allouermatrice(nl, nc);         // passer car à de same type
    remplirmatrice(matrice, nl, nc);                // matrice est dèja de type (int**)
    affichermatrice(matrice, nl, nc);
    libérermatrice(matrice, nl);
    return 0;
}








