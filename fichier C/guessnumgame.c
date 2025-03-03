#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(0));
    int num=(rand() % 100) + 1 ,Bet=0 ,valid0 ,money ,valid1 ,valid2 ,mine=0;
    char decision;

    printf("ready to play? [Y for yes, N for No]\n");
    int input = scanf(" %c", &decision);

    if (decision != 'y' && decision != 'n')
    {
        return 0;
    }
    

    if(decision == 'n'){

        printf("Pussy\n");

    }
    if(decision == 'y'){

    printf("Please select your Bet Multiple to 5\n");
    valid0=scanf(" %d" ,&Bet);

    while (Bet%5 != 0 && valid0 != 1 && Bet > 0)
    {
        printf("Please motherfucker select a multiple of 5 or are you a retard?\n");
        while(getchar() != '\n');
    }
    printf("Now we will play a game\n i have a number\n you will be guessing it by telling if its high or low\n every time you get it wrong i'll substract %d from the bet you made yourself\n either doubling your money from first try\n or owning me money\nStarting Now\n",Bet/5);
    
    valid1=scanf(" %d" ,&money);

    while(money<0 && money>100 && valid1 != 1){
        printf("Retard bitch, i told you its between 0 and 100\ntry again\n");
        while(getchar() != '\n');
    }
    while (money != num)
    {
        if (money>num)
        {
            printf("High\n");
            mine=mine + Bet/5;
            while(getchar() != '\n');

        }
        else
        {
            printf("Low\n");
            mine=mine +Bet/5;
            while(getchar() != '\n');
        }
        
    }
    
    if(mine>0){
        printf("you lost bitch, not as much but you lost you addict\n");
    }
    else
    {
        printf("That's Some luck you got there\n");
    }
    
    }
    return 0;
}