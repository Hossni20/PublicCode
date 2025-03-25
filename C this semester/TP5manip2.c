#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int contient_mot(char *ligne,char *mot){
    if (mot == NULL || *mot == '\0'){ 
        return 0;
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
        pos = strstr(pos+1, mot);
    }
    return M;
}


void trier_lignes(char *texte[], int n) {
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (strlen(texte[j]) > strlen(texte[j + 1])) {
                    char *temp = texte[j];
                    texte[j] = texte[j + 1];
                    texte[j + 1] = temp;
                }
            }
        }
}


int main(){


    return 0;
}



