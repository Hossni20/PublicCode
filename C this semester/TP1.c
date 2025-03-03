#include <stdio.h>
#include <stdlib.h>

struct Model{
    char mois[10];
    int an;
 };
 struct voiture{
    char marque[20];
    char Tcarburant[20];
    float prix;
    struct Model m;
 };


 int main(){
    struct voiture vt[5];
    char Table[6][5];
    //Le titre de tableau
    for(int j=0;j<5;j++){
        scanf(" %s",&Table[0][j]);
    }
    //le saisir 
    for (int i=0;i<6;i++){
        for(int j=0;j<5;j++){
            printf("Saisir La %d voiture Marque\n",i+1);
            scanf(" %s",&vt[j].marque);
            printf("Saisir la %d voiture Type de carburant\n",i+1);
            scanf(" %s",&vt[j].Tcarburant);
            printf("Saisir la %d voiture Prix\n",i+1);
            scanf("%f",&vt[j].prix);
            printf("Saisir Le mois de prod du %d voiture\n",i+1);
            scanf(" %s",&vt[j].m.mois);
            printf("Saisir l'année de prod du %d voiture\n",i+1);
            scanf("%d",&vt[j].m.an);
        }
    }
    //Incrémentation au tableau
    for(int i=1;i<6;i++){
        for(int j=0;j<1;j++){
            Table[i][j] = vt[j].marque;
            Table[i][j+1] = vt[j].Tcarburant;
            Table[i][j+2] = vt[j].m.mois;
            Table[i][j+3] = vt[j].m.an;
            Table[i][j+4] = vt[j].prix;
        }
    }
    //Affichage Du tableau
    for(int j=0;j<1;j++){
            printf("%s\t %s\t %s\t %s\t %s\n",Table[0][j],Table[0][j+1],Table[0][j+2],Table[0][j+3],Table[0][j+4],Table[0][j+5]);
    }
    for(int i=1;i<6;i++){
        for(int j=0;j<1;j++){
            printf("%s\t %s\t %s\t %d\t %f\n",Table[i][j],Table[i][j+1],Table[i][j+2],Table[i][j+3],Table[i][j+4],Table[i][j+5]);
        }
    }

    return 0;
 }