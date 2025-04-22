#include <stdio.h>
#include <stdlib.h>
#include <string.h>  
// Définition du type Etudiant
typedef struct {
    char nom[20];
    char prenom[20];
    int age;
    float resultat;
} Etudiant;
// Constante max sans point-virgule
#define MAX 100
Etudiant *Liste_Etudiant[MAX];  
int nb_etd = 0; 

void ajouterEtudiant(){
    if(nb_etd>=100) exit(1);
    else{ 
    Liste_Etudiant[nb_etd]=(Etudiant*)malloc(sizeof(Etudiant));
    if(Liste_Etudiant[nb_etd]==NULL) exit(1);
    else{
        printf("1er est le Nom, la 2éme est le prénom, La 3éme est L'age, La 4éme est la résultat\n");
        scanf("%s %s %d %f",Liste_Etudiant[nb_etd]->nom,Liste_Etudiant[nb_etd]->prenom,&Liste_Etudiant[nb_etd]->age,&Liste_Etudiant[nb_etd]->resultat);
        nb_etd++;
    }
        }
}

void supprimerEtudiant(){

}

void modifierEtudiant(){

}

void afficherTous(){
    
}




int main() {
    int input;
    while(1){
        printf("----Gestion des étudiants----\n");
        printf("0.Exit");
        printf("1.Ajouter un étudiant\n");
        printf("2.Supprimer un étudiant\n");
        printf("3.Modifier La Note\n");
        printf("4.Quitter\n");
        scanf("%d", &input);
if (input == 0) break;
else {
    switch(input) {
        case 1:
            ajouterEtudiant();
            break;
        case 2:
            supprimerEtudiant();
            break;
        case 3:
            modifierEtudiant();
            break;
        case 4:
            afficherTous();
            break;
        default:
            printf("Invalid Input.\n");
                    }
    }

                }      
    return 0;
}
