#include <stdio.h>
/*this is the function*/
void guessNumber(int guess) {
    if (guess == 555) {
        printf("Correct. You guessed it!\n");
    } else if (guess < 555) {
        printf("Your guess is too low.\n");
    } else {
        printf("Your guess is too high.\n");
    }
}

int main() {
    char input[10];  // Stocke l'entrée de l'utilisateur (peut contenir 'e' ou un nombre)
    int guess;

    while (1) {  // Boucle infinie jusqu'à la bonne réponse ou sortie
        printf("Enter your guess Between 0 and a 1000 (or 'e' to exit): ");
        scanf(" %s", input);  // Lire l'entrée sous forme de chaîne de caractères

        // Vérifier si l'utilisateur veut quitter
        if (input[0] == 'e' || input[0] == 'E') {
            printf("Exiting the game. Goodbye!\n");
            break;
        }

        // Convertir l'entrée en nombre entier
        if (sscanf(input,"%d",&guess) == 1) { //permet de vérifier si la chaine de caracteres input contient un nombre entier valide avant utiliser après on le stocke dans "guess"
            guessNumber(guess);

            // Sortir de la boucle si la bonne réponse est trouvée
            if (guess == 555) {
                break;
            }
        } else {
            printf("Invalid input. Please enter a number or 'e' to quit.\n");
        }
    }

    return 0;
}
