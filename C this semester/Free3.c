#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <strings.h>

int* SommeTableaux(int* T1,int* T2,int taille){         // taille doesn't need a pointer because it doesn't need to change
    int* res = malloc(taille*sizeof(int));              // it returns a table so it needs a pointer to return res by its values
    if (res == NULL)                                    // whithout the tidious task to pass by value
    {
        exit(1);
    }
    for(int i=0;i<taille;i++){
        res[i] = T1[i] + T2[i];
    }
    return res;
}
int main(){

int taille;
printf("Donner La Taille du tableau:\n");
scanf("%d",&taille);

int* T1=malloc(taille*sizeof(int));
int* T2=malloc(taille*sizeof(int));

if(T1 == NULL || T2 == NULL){
    free(T1);
    free(T2);
    exit(1);
}

for(int i=0;i<taille;i++){
    printf("Donner la %d-éme nombre du T1:\n",i+1);
    scanf("%d",T1+i);
}
for(int i=0;i<taille;i++){
    printf("Donner la %d-éme nombre du T2:\n",i+1);
    scanf("%d",T2+i);
}

int* res = SommeTableaux(T1,T2,taille);                 // it returns a pointer for res and the type of an "int"

for(int i=0;i<taille;i++){
    printf("%d\t",*(res+i));
}

free(T1);
free(T2);
free(res);

    return 0;
}