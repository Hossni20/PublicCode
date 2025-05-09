#include <stdio.h>
#include <stdlib.h>
#include <string.h>  
typedef struct {
    char nom[20];
    char prenom[20];
    int age;
    float resultat;
} Etudiant;
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
        scanf(" %s %s %d %f",Liste_Etudiant[nb_etd]->nom,Liste_Etudiant[nb_etd]->prenom,&Liste_Etudiant[nb_etd]->age,&Liste_Etudiant[nb_etd]->resultat);
        nb_etd++;
    }
        }
}



void supprimerEtudiant() {
    char nom[30];
    char prenom[30];
    int i,j,found=0;
    printf("Donner nom d'étudiant à supprimer:\n");
    scanf(" %s", nom);
    printf("Donner prenom d'étudiant à supprimer:\n");
    scanf(" %s", prenom);
    for(i = 0; i < nb_etd; i++) {
        if(strcmpi(nom, Liste_Etudiant[i]->nom) == 0 &&
           strcmpi(prenom, Liste_Etudiant[i]->prenom) == 0) {
            free(Liste_Etudiant[i]); 
            for(j = i; j < nb_etd - 1; j++) {
                Liste_Etudiant[j] = Liste_Etudiant[j + 1];
            }
            nb_etd--;
            found=1;
            printf("Étudiant supprimé avec succès.\n");
            break;
        }
    }
        if (!found) {
        printf("Étudiant non trouvé.\n");
    }
}



void modifierEtudiant() {
    char nom[20];
    char prenom[20];
    int i, found=0;
    float Note;
    printf("Donner la nouvelle note :\n");
    scanf(" %f", &Note);
    printf("Donner nom de l'étudiant à modifier la note :\n");
    scanf(" %s", nom);
    printf("Donner prenom de l'étudiant à modifier la note :\n");
    scanf(" %s", prenom);
    for(i = 0; i < nb_etd; i++) {
        if(strcmpi(nom, Liste_Etudiant[i]->nom) == 0 &&
           strcmpi(prenom, Liste_Etudiant[i]->prenom) == 0) {
            Liste_Etudiant[i]->resultat = Note;
            printf("Note mise à jour : %.2f\n", Liste_Etudiant[i]->resultat);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Étudiant non trouvé.\n");
    }
}




void afficherTous() {
    if (nb_etd == 0) {
        printf("Aucun étudiant enregistré.\n");
        return;
    }
    printf("Liste des étudiants :\n");
    for (int i = 0; i < nb_etd; i++) {
        printf("Étudiant %d:\n", i + 1);
        printf("Nom: %s\n", Liste_Etudiant[i]->nom);
        printf("Prénom: %s\n", Liste_Etudiant[i]->prenom);
        printf("Âge: %d\n", Liste_Etudiant[i]->age);
        printf("Résultat: %.2f\n", Liste_Etudiant[i]->resultat);
        printf("-------------------------\n");
    }
}




int main() {
    int input;
    while(1){
        printf("----Gestion des étudiants----\n");
        printf("0.Exit\n");
        printf("1.Ajouter un étudiant\n");
        printf("2.Supprimer un étudiant\n");
        printf("3.Modifier La Note\n");
        printf("4.AfficherTous\n");
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

for (int i = 0; i < nb_etd; i++) {
    free(Liste_Etudiant[i]);
}
    return 0;
}
