#include <stdio.h>
#include <stdlib.h>

int* sommeTableax(int taille, int* tab1, int* tab2){
    int* res = (int*)malloc(taille*sizeof(int));
    for(int i=0;i<taille;i++){
        res[i]=tab1[i]+tab2[i];
    }
    return res; //it returns a table of [taille]
}
int main(){
    int taille;
    scanf("%d",&taille); //enter the size of table

    int* tab1 = (int*)malloc(taille*sizeof(int));
    int* tab2 = (int*)malloc(taille*sizeof(int));

    //after filling the tables
    for(int i=0;i<taille;i++){
        scanf("%d",&tab1[i]);
    }

    for(int i=0;i<taille;i++){
        scanf("%d",&tab2[i]);
    }

    int* res = sommeTableax(tab1,tab2,taille);
    
    for(int i=0;i<taille;i++){
        printf("%d",res[i]); //printing out the results
    }
    printf("\n");

    free(tab1);
    free(tab2);
    free(taille);
    return 0;
}