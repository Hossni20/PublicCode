#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char **allouerTableau(int nl, int nc) {
    char **Tableau = (char **)malloc(nl * sizeof(char *)); // LES ADRESSES kamlin fihom les adresses wajdin
    if (Tableau == NULL) {
        return NULL;
    }
    for (int i = 0; i < nl; i++) {
        Tableau[i] = (char *)malloc(nc * sizeof(char)); // LES ENTIERS kan allocatiw o kan3mrou manuellement
        if (Tableau[i] == NULL) {
            return NULL;
        }
    }
    return Tableau;
}

int contient_mot(char *ligne,char *mot){
    if (mot == NULL || *mot == '\0'){ 
        return 1;
    }
    return strstr(ligne, mot) != NULL; 
}


int compter_occurences_mot(char *ligne,char *mot){
    if (mot == NULL || *mot == '\0') {
        return 0; 
    }
    int M = 0;
    char *pos = strstr(ligne, mot);
    while (pos != NULL) {
        M++;
        pos = strstr(pos+strlen(mot), mot); //Saute les tailles du mot au suivant sans sauter caractere par caractere
    }
    return M;
}


void trier_lignes(char *texte[], int n) {
        for (int i = 0; i < n - 1; i++) {
            for (int j = i+1 ; j < n ; j++) {
                if (strlen(texte[i]) > strlen(texte[j])) {
                    char *temp = texte[i];
                    texte[i] = texte[j];
                    texte[j] = temp;
                }
            }
        }
}


int main(){
    char **Text;
    int nl_max = 100;
    int nc_max = 500;
    Text = allouerTableau(nl_max,nc_max);
    
    
    return 0;
}



