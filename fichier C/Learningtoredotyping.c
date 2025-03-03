#include <stdio.h>
#include <string.h>
#include <stdbool.h>

struct FightClub {
    int age, Height;
};

int main(){
    bool tempsex;
    int agetemp=0,tempheight=0;
    struct FightClub Heavy;
    struct FightClub Light;

    printf("Do you have a dick or a Pussy? 1 for dick and 0 for pussy\n");
    scanf("%d", &tempsex);

    if (tempsex){
        printf("How old are you ya Bouklwa?\n");
        scanf("%d" ,&agetemp);
        if (agetemp>=18)
        {   
            printf("How Tall are you bitch?\n");
            scanf(" %d", &tempheight);
            if(tempheight>180){
                Heavy.Height=tempheight;
                Heavy.age=agetemp;
                printf("Damn, i didn't know you were chill like. Now you are a member of fight club at the age of %d and the height of %d\n",Heavy.age ,Heavy.Height);
            }
            else{
                Light.Height=tempheight;
                Light.age=agetemp;
                printf("Damn Shorty, good luck out there. Now you are a member of fight club at the age of %d and the height of %d\n",Light.age ,Light.Height);
            }
        }
        else{
            printf("GET TF out of here no diddy\n");
        } 
    }
    else{
        printf("Get Back to Lkouzina Limak\n");
    }
    return 0;
}