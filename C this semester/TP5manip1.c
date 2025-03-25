#include <stdio.h>
#include <string.h>

int main(){
    char ligne[] = "C'est un test de programme.";
    char mot[] = "test";
    char *pos = strstr(ligne,mot);
    while (pos!=0)
    {
        printf("\nMot trouvé à la position %ld.\n",pos - ligne); //la position pos (adresse) moins la position ligne (adresse) 0x100 et 0x109
        pos = strstr(pos+1,mot); // il trouve t puis e puis s puis t jusqu'à il trouve \0  
    }
    return 0;
}