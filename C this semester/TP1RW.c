#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
int password(char input[20]){
    if(strcmp(input[20],"1456")==0){
        return 1;
    }
    else
    {
        return 0;
    }
}
struct Date
{
    int an;
    char mois[10];
};
struct Book
{
    char title[20];
    char author[20];
    struct Date dt;
    int availability;
    int favorite;
};

int main(){
int count=0;
char pass[20];
struct Book Bk[5];
for(int i=0;i<5;i++){
    printf("titre du livre:\n");
    scanf(" %s",Bk[i].title);
    printf("Author du livre:\n");
    scanf(" %s",Bk[i].author);
    printf("Mois et année du publication:\n");
    scanf(" %s %d",Bk[i].dt.mois,&Bk[i].dt.an);
    Bk[i].availability = 10;
    Bk[i].favorite = 0;
}
//looking for the book
char Temp[20];
printf("What book are you looking for?\n");
scanf(" %s",Temp);
for(int i=0;i<5;i++){
    if(strcmp(Temp,Bk[i].title)==0){
        printf("What can i do for you today? Lending? Returning? or if you're the boss check stock and availability via a password:\n");
        //Security mesures for managment
        printf("if you're the boss type 1 and for regular customers type 0\n");
        scanf("%d",&count); //filtering customers from employers
        if (count==1)
        {
            printf("Hello Boss, Plz enter the password:\n");
            scanf(" %s",pass[20]);
            if(password(pass[20])==1){
                printf("Welcome Boss\n");//Starting to manage with all funtionalities
                while(1)
                {
                    printf("> ");
                    // Read the operation and numbers from the user
                    int input = scanf(" %c", Temp);
                    if (Temp == 'e') {
                    printf("Exiting register.\n");
                    break;
                    }
                    printf("You're Log in so how much you want to add for this title ?\n");
                    scanf("%d",&count);

                }
                
            }
            else{
                printf("Get out of here\n");
                return 0;
            }
        }
        else if(count==0) //functionalities for customers
        {
            printf("> ");
            // Read the operation and numbers from the user
            int input = scanf(" %c", Temp);
            if (Temp == 'e') {
                printf("Exiting register.\n");
                break;
            }

        }
        else
        {
            printf("Get out of here, return when you can read");
            return 0;
        }
        
        
    }
    else{
        printf("Book not found\n");
        break;
    }
}
    return 0;
}