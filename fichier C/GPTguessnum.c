#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0)); // Seed the random number generator
    int num = (rand() % 100) + 1;  // Random number between 1 and 100
    int Bet = 0, valid0, money, valid1, mine = 0;
    char decision;

    // Ask if the user is ready to play
    printf("Ready to play? [Y for Yes, N for No]\n");
    int input = scanf(" %c", &decision);

    // Check if input is valid
    if (decision != 'y' && decision != 'n') {
        return 0;  // Exit if input is not 'y' or 'n'
    }

    if (decision == 'n') {
        printf("Pussy\n");
        return 0;  // Exit if user chooses no
    }

    if (decision == 'y') {
        // Ask for the bet
        printf("Please select your Bet (multiple of 5): ");
        valid0 = scanf(" %d", &Bet);

        // Input validation for bet (multiple of 5)
        while (Bet % 5 != 0 || Bet <= 0 || valid0 != 1) {
            printf("Please select a positive multiple of 5.\n");
            while (getchar() != '\n');  // Clear the input buffer
            valid0 = scanf(" %d", &Bet); // Re-ask for the bet
        }

        printf("Now we will play a game\nI have a number.\nYou will guess if it's high or low.\n");
        printf("Every time you get it wrong, I'll subtract %d from the bet you made.\n", Bet / 5);
        printf("Starting now...\n");

        // Ask for the initial money (guess)
        printf("Please enter a number between 0 and 100: ");
        valid1 = scanf(" %d", &money);

        // Validate money input (should be between 0 and 100)
        while (money < 0 || money > 100 || valid1 != 1) {
            printf("Please enter a valid number between 0 and 100.\n");
            while (getchar() != '\n');  // Clear the input buffer
            valid1 = scanf(" %d", &money); // Re-ask for the money
        }

        // Game loop (guessing high or low)
        while (money != num) {
            if (money > num) {
                printf("High\n");
                mine = mine + Bet / 5;  // Deduct from bet if guess is high
            } else {
                printf("Low\n");
                mine = mine + Bet / 5;  // Deduct from bet if guess is low
            }

            // Ask again for the next guess
            printf("Try again: ");
            scanf(" %d", &money);
        }

        // If the guess is correct
        if (mine > 0) {
            printf("You lost! Not as much, but you lost.\n");
        } else {
            printf("That's some luck you got there!\n");
        }
    }
    return 0;
}
