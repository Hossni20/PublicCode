#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <strings.h> 

int compterVoyelles(char *str){
    char voyelles[13] = "aeiouyAEIOUY";
    int count=0;
    for(int i=0;str[i] != '\0';i++){
        for(int j=0;voyelles[j] != '\0';j++){
            if(str[i]==voyelles[j]){
                count++;
                break; // ila lkiti i bla mayklb m3a lakhrin bhal o e u y
            }
        }
    }
    if(count == 0){
        printf("il n'existe aucun voyelle:\n");
        return 0;
    }
    else{
        return count;
    }
}

char* inverser(char *str){
    char* Tabinv=malloc((strlen(str)+1)*sizeof(char));
    if(Tabinv == NULL) exit(1);
    for(int i=0;i<strlen(str);i++){
        *(Tabinv+i) = *(str+strlen(str)-i-1);
    }
    Tabinv[strlen(str)] = '\0';
    
    return Tabinv;
}
int main(){
char* Mot=malloc(20*sizeof(char));
if(Mot == NULL){
    exit(1);
}
else{
    printf("Enter your word:\n");
    fgets(Mot, 20, stdin);              // Best and safer
    printf("This is your word: %s\n",Mot);
    printf("Voici votre mot inverser: %s\n",inverser(Mot));
    int i=0;
    while(Mot[i] != '\0'){
        printf("Ton %d-éme caractère est: %c\n",i+1,*(Mot+i));
        i++;
    }
    printf("Your word has %d voyelles.\n",compterVoyelles(Mot));
}
free(Mot);
    return 0;
}