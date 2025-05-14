#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TEXTE 1000

// Prototypes
void creerFichier();
void lireFichier();
void ajouterTexte();
void modifierLigne();
void supprimerLigne();

int main() {
    int choix;
    
    do {
        printf("\n--- Gestion de Fichier Texte ---\n");
        printf("1. Créer un nouveau fichier\n");
        printf("2. Lire le fichier\n");
        printf("3. Ajouter du texte\n");
        printf("4. Modifier une ligne\n");
        printf("5. Supprimer une ligne\n");
        printf("6. Quitter\n");
        printf("Choix : ");
        scanf("%d", &choix);
        
           switch(choix) {
            case 1: creerFichier(); break;
            case 2: lireFichier(); break;
            case 3: ajouterTexte(); break;
            case 4: modifierLigne(); break;
            case 5: supprimerLigne(); break;
            case 6: printf("Au revoir!\n"); break;
            default: printf("Choix invalide!\n");
        }
    } while(choix != 6);
    
    return 0;
}

// 1. Création d'un nouveau fichier (écrase si existe)
void creerFichier() {
    FILE *f = fopen("fichier.txt", "w");
    if (!f) {
        printf("Erreur création fichier");
        return;
    }
    
    char texte[MAX_TEXTE];
    printf("Entrez le texte initial (max %d caractères):\n", MAX_TEXTE);
    fgets(texte, MAX_TEXTE, stdin);
    
    fprintf(f, "%s", texte);
    fclose(f);
    printf("Fichier créé avec succès!\n");
}

// 2. Lecture du fichier
void lireFichier() {
    FILE *f = fopen("fichier.txt", "r");
    if (!f) {
        printf("\n Erreur ouverture fichier\n");
        return;
    }
    
    printf("\n Contenu du fichier:\n");
    printf("------------------\n");
    
    char ligne[256];
    int num = 1;
    while(fgets(ligne, sizeof(ligne), f)) {
        printf("%d: %s", num++, ligne);
    }
    printf("------------------\n");
    
    fclose(f);
}

// 3. Ajout de texte à la fin
void ajouterTexte() {
    FILE *f = fopen("fichier.txt", "a");
    if (!f) {
        printf("\n Erreur ouverture fichier \n");
        return;
    }
    
    char texte[MAX_TEXTE];
    printf("Entrez le texte à ajouter:\n");
    fgets(texte, MAX_TEXTE, stdin);
    
    fprintf(f, "%s", texte);
    fclose(f);
    printf("Texte ajouté avec succès!\n");
}

// 4. Modification d'une ligne spécifique
void modifierLigne() {
    FILE *f = fopen("fichier.txt", "r");
    if (!f) {
        printf("Erreur ouverture fichier");
        return;
    }
    
    // Stockage temporaire des lignes
    char lignes[100][256];
    int count = 0;
    
    while(fgets(lignes[count], 256, f) && count < 100) {
        count++;
    }
    fclose(f);
    
    if (count == 0) {
        printf("Fichier vide!\n");
        return;
    }
    
    // Affichage des lignes
    lireFichier();
    
    int num;
    printf("Numéro de ligne à modifier : ");
    scanf("%d", &num);
    while(getchar() != '\n'); // Vider buffer
    
    if (num < 1 || num > count) {
        printf("Numéro invalide!\n");
        return;
    }
    
    printf("Nouveau contenu pour la ligne %d:\n", num);
    //fgets(lignes[num-1], 256, stdin);
      gets(lignes[num-1]);
    
    // Réécriture du fichier
    f = fopen("fichier.txt", "w");
    if (!f) {
        printf("Erreur ouverture fichier");
        return;
    }
    
    for (int i = 0; i < count; i++) {
        fprintf(f, "%s", lignes[i]);
    }
    fclose(f);
    printf("Ligne modifiée avec succès!\n");
}

// 5. Suppression d'une ligne
void supprimerLigne() {
    FILE *f = fopen("fichier.txt", "r");
    if (!f) {
        printf("Erreur ouverture fichier");
        return;
    }
    
    char lignes[100][256];
    int count = 0;
    
    while(fgets(lignes[count], 256, f) && count < 100) {
        count++;
    }
    fclose(f);
    
    if (count == 0) {
        printf("Fichier vide!\n");
        return;
    }
    
    lireFichier();
    
    int num;
    printf("Numéro de ligne à supprimer : ");
    scanf("%d", &num);
    
    
    if (num < 1 || num > count) {
        printf("Numéro invalide!\n");
        return;
    }
    
    // Réécriture en sautant la ligne à supprimer
    f = fopen("fichier.txt", "w");
    if (!f) {
        printf("Erreur ouverture fichier");
        return;
    }
    
    for (int i = 0; i < count; i++) {
        if (i != num-1) {
            fprintf(f, "%s", lignes[i]);
        }
    }
    fclose(f);
    printf("Ligne supprimée avec succès!\n");
}
