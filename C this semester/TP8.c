// "r": lecture seul ( le fichier doit existe)
// "w": écriture seul (le fichier est créer mais s'il existe il ecrase le premier ligne du fichier)
// "a": ajout à la fin du fichier (le fichier doit existe)
// "a+": fichier doit existe (lecture au premier ligne et ecriture au dernier ligne)
// "r+" et "w+": meme conditions juste il ajoute les fonctionnaltés d'autre
#include <stdio.h>
#include <stdlib.h>

void CréerFichier() {
    FILE *f;
    char text[100];
  
    f = fopen("Fichier1.txt", "w"); // Tayhl Lfichier o tay3ti ID L f (écrase s'il existe)
    if (f == NULL) {
        printf("Erreur d'ouverture du fichier");
        exit(1);
    }

    printf("Saisir ton premier texte:");
    getchar(); // clear the '\n'
    fgets(text,sizeof(text),stdin); // on lit le text à partir de clavier(stdin)


    fprintf(f,"%s", text); // Kayht Lktaba Flwl ta3 fichier
    fclose(f); // Bonne pratique
}
















int main(){
    int input;
        printf("----Gestion des fichiers----\n");
        printf("1.Créer un nouveau fichier\n");
        printf("2.Lire le fichier\n");
        printf("3.Ajouter du texte\n");
        printf("4.Modifier une ligne\n");
        printf("5.Supprimer une ligne\n");
        printf("6.Quitter\n");
        scanf("%d", &input);
        switch(input) {
        case 1:
            CréerFichier();
            break;
        case 2:

            break;
        case 3:

            break;
        case 4:

            break;
        case 5:

            break;
        default:
            printf("Invalid Input.\n");
                    }
    return 0;
}