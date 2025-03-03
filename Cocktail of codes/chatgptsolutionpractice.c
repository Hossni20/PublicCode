#include <stdio.h>
#include <string.h>

struct Projet {
    char color[10];
    int windows;
};

int main() {
    int tempwin = 0;
    char tempcolor[10];
    struct Projet Villa;
    struct Projet House;
    struct Projet Apartment;

    printf("How many windows does your heart desire?\n");
    scanf("%d", &tempwin);

    if (tempwin > 50) {
        printf("Whoa, buddy! In this economy, the best we can do is 50. Try again.\n");
    } 
    else if (tempwin <= 50 && tempwin >= 25) {
        printf("So you chose a villa. Great taste! Now, what color do you want your house to be?\n");
        scanf("%s", tempcolor);

        if (strcmp(tempcolor, "Bleu") == 0 || strcmp(tempcolor, "Red") == 0 || strcmp(tempcolor, "Green") == 0) {
            Villa.windows = tempwin;
            strcpy(Villa.color, tempcolor);
            printf("Great choice! Now you have a villa with %d windows and the color %s.\n", Villa.windows, Villa.color);
        } else {
            printf("That color is not available. Try again.\n");
        }
    } 
    else if (tempwin <= 10 && tempwin >= 5) {
        printf("So you chose a house. What color do you want it to be?\n");
        scanf("%s", tempcolor);

        if (strcmp(tempcolor, "Bleu") == 0 || strcmp(tempcolor, "White") == 0) {
            House.windows = tempwin;
            strcpy(House.color, tempcolor);
            printf("Good choice! Now you own a house with %d windows and the color %s.\n", House.windows, House.color);
        } else {
            printf("That color isn't available. Try again.\n");
        }
    } 
    else if (tempwin < 5 && tempwin >= 3) {
        printf("So you have chosen an apartment. What color do you want it to be?\n");
        scanf("%s", tempcolor);

        if (strcmp(tempcolor, "White") == 0) {
            Apartment.windows = tempwin;
            strcpy(Apartment.color, tempcolor);
            printf("Good choice! Now you own an apartment with %d windows and the color %s.\n", Apartment.windows, Apartment.color);
        } else {
            printf("That color isn't available. Try again.\n");
        }
    } 
    else {
        printf("Please choose a realistic number of windows.\n");
    }

    return 0;
}
