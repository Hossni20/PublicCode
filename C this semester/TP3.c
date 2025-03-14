#include <stdio.h>
void inverser(char *str) {
    char *fin = str;
    // Trouver la fin de la chaîne
    while (*fin) {
        fin++;
    }
    fin--;  // Reculer d'un caractère pour éviter '\0'

    // Échanger les caractères en utilisant deux pointeurs
    while (str < fin) {
        char temp = *str;
        *str = *fin;
        *fin = temp;
        str++;
        fin--;
    }
}
int comptervoyelles(char *str) {
    int compteur = 0;
    char *voyelles = "aeiouAEIOU";  

    while (*str) {  // Tant qu'on n'atteint pas '\0'
        char *v = voyelles;
        while (*v) {  // Vérifier si *str est une voyelle
            if (*str == *v) {
                compteur++;
                break;  // Sortir de la boucle dès qu'on trouve une correspondance
            }
            v++;  // Passer à la voyelle suivante
        }
        str++;  // Passer au caractère suivant
    }
    return compteur;
}
int main() {
    char chaine[] = "ENSAA";
    char *p = chaine;  // Correct : pointeur de type char*
    printf("Le code ASCII du premier caractère du mot est: %d\n", *p);  // Affiche 98 (ASCII de 'b')
    printf("%s\n", p);   // affiche le mot "bonjour"
    int i=0;
    while (*p != '\0')
    {
        printf("%c\n",*p);
        p++;
    }
    inverser(chaine);
    printf("%s\n", chaine);
    printf("Nombre de voyelles : %d\n", comptervoyelles(chaine));
    return 0;
}





