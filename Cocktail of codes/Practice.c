#include <stdio.h>
#include <stdlib.h>
 struct Projet {
    char color[10];
    int windows;
 };
 int main(){
    int tempwin=0;
    char tempcolor[10];
    struct Projet Villa;
    struct Projet House;
    struct Projet Apartment;

    printf("How many Windows your heart desire?\n");
    scanf("%d",&tempwin);
    if (tempwin > 50){
        printf("Wooow buddy, in this economy the best we can do is 50, try again");    
    }
    else if(tempwin <= 50 && tempwin >= 25){
        printf("So you chose a villa, great taste sir. Now what color you want you house to be?");
        scanf(" %s",&tempcolor);
        Villa.windows = tempwin;
        if (strcmp(tempcolor,"Bleu" || "Red" || "Green")==1){
            strcpy(Villa.color,tempcolor);
            printf("great choice sir, now you have a villa with %d windows and the color %c",Villa.windows,Villa.color);
        }
        else {printf("That Color is not available, try again bitch");}  
    }
    else if(tempwin <= 10 && tempwin >=5){
        printf("So you chose a House, what color you want it to be?");
        scanf(" %s",&tempcolor);
        House.windows = tempwin;
        if (strcmp(tempcolor,"Bleu" || "White")==1){
            strcpy(House.color,tempcolor);
            printf("good choice sir, now you own a house with %d windows and the color %c",House.windows,House.color);
        }
        else {printf("That color ain't available, try again bitch");}
    }
    else if(tempwin < 5 && tempwin >= 3){
        printf("So you have chosen an apartement, what color you want it to be ?");
        scanf(" %s",&tempcolor);
        Apartment.windows = tempwin;
        if (strcmp(tempcolor,"White")==1){
            strcpy(Apartment.color,tempcolor);
            printf("good choice sir, now you own an apartment with %d windows and the color %c",Apartment.windows,Apartment.color);   
        }
        else {printf("That color ain't available, try again bitch");}
    }
    else {printf("Choose a relistic number bitch");}
 }