#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ETUDIANTS 100

typedef struct {
    char nom[50];
    char prenom[50];
    int age;
    float note;
} Etudiant;

Etudiant* listeEtudiants[MAX_ETUDIANTS]; // Tableau de pointeurs
int nbEtudiants = 0;

/* Prototypes */
void ajouterEtudiant();
void supprimerEtudiant();
void modifierNote();
void afficherEtudiants();


int main() {
    int choix;
    do {
    printf("\n--- Gestion des Étudiants ---\n");
    printf("1. Ajouter un étudiant\n");
    printf("2. Supprimer un étudiant\n");
    printf("3. Modifier la note\n");
    printf("4. Afficher tous\n");
    printf("5. Quitter\n");
    printf("Choix : ");
	scanf("%d", &choix);      
        switch(choix) {
            case 1: ajouterEtudiant(); break;
            case 2: supprimerEtudiant(); break;
            case 3: modifierNote(); break;
            case 4: afficherEtudiants(); break;
            case 5: printf("Au revoir!\n");
                // Libération mémoire
                for(int i = 0; i < nbEtudiants; i++) {
                    free(listeEtudiants[i]);
                }
                break;
            default: printf("Choix invalide!\n");
        }
    } while(choix != 5);
    return 0;
}

void ajouterEtudiant() {
    if(nbEtudiants >= MAX_ETUDIANTS) {
        printf("Capacité maximale atteinte!\n");
        return;
    }
    Etudiant *nouveau = (Etudiant*)malloc(sizeof(Etudiant));
    
    printf("\nNouvel étudiant:\n");
    printf("Nom: "); 
    scanf("%s", nouveau->nom);
    printf("Prénom: "); 
    scanf("%s", nouveau->prenom);
    printf("Âge: "); 
    scanf("%d", &nouveau->age); // 
    printf("Note: "); 
    scanf("%f", &nouveau->note);

    listeEtudiants[nbEtudiants] = nouveau;
    nbEtudiants++;
    printf("Étudiant ajouté!\n");
}

void supprimerEtudiant() {
    if(nbEtudiants == 0) {
        printf("Liste vide!\n");
        return;
    }

    char nom[50], prenom[50];
    printf("\nSupprimer un étudiant:\n");
    printf("Nom: "); 
    scanf("%s", nom);
    printf("Prénom: "); 
    scanf("%s", prenom);

    for(int i = 0; i < nbEtudiants; i++) {
        if(strcmp(listeEtudiants[i]->nom, nom) == 0 && 
           strcmp(listeEtudiants[i]->prenom, prenom) == 0) {
             free(listeEtudiants[i]); // Libération mémoire
             // Décalage des pointeurs
            for(int j = i; j < nbEtudiants-1; j++) {
                listeEtudiants[j] = listeEtudiants[j+1];
            }
             nbEtudiants--;
            printf("Étudiant supprimé!\n");
            return;
        }
    }
    printf("Étudiant non trouvé!\n");
}
void modifierNote() {
    if(nbEtudiants == 0) {
        printf("Liste vide!\n");
        return;
    }
    char nom[50], prenom[50];
    printf("\nModifier note:\n");
    printf("Nom: "); 
    scanf("%s", nom);
    printf("Prénom: "); 
    scanf("%s", prenom);

    for(int i = 0; i < nbEtudiants; i++) {
        if(strcmpi(listeEtudiants[i]->nom, nom) == 0 &&
           strcmpi(listeEtudiants[i]->prenom, prenom) == 0) {
            
            printf("Ancienne note: %.2f\n", listeEtudiants[i]->note);
            printf("Nouvelle note: ");
            scanf("%f", &listeEtudiants[i]->note);
            printf("Note modifiée!\n");
            return;
        }
    }
    printf("Étudiant non trouvé!\n");
}

void afficherEtudiants() {
    if(nbEtudiants == 0) {
        printf("Aucun étudiant!\n");
        return;
    }
    printf("\nListe des étudiants (%d):\n", nbEtudiants);
    printf("----------------------------------------\n");
    for(int i = 0; i < nbEtudiants; i++) {
        printf("%s %s, %d ans, Note: %.2f\n",
               listeEtudiants[i]->nom,listeEtudiants[i]->prenom,
               listeEtudiants[i]->age,listeEtudiants[i]->note);
    }
    printf("----------------------------------------\n");
}
