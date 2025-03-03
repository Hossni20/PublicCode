#include <stdio.h>
#include <string.h>

// Structure definition for Projet
struct Projet {
    char color[10];
    int windows;
};

// Function to validate color input based on allowed colors
int is_valid_color(const char *color, const char *valid_colors[], int num_colors) {
    for (int i = 0; i < num_colors; i++) {
        if (strcmp(color, valid_colors[i]) == 0) {
            return 1; // Valid color found
        }
    }
    return 0; // No match found
}

// Function to create a project with re-entry for invalid color
void create_project(struct Projet *project, int windows, const char *project_type, const char *valid_colors[], int num_colors) {
    char tempcolor[10];
    int valid = 0;

    project->windows = windows;

    // Keep asking until the user provides a valid color
    while (!valid) {
        printf("What color do you want your %s to be? (Options: ", project_type);
        for (int i = 0; i < num_colors; i++) {
            printf("%s%s", valid_colors[i], (i < num_colors - 1) ? ", " : "");
        }
        printf(")\n");
        scanf("%s", tempcolor);

        if (is_valid_color(tempcolor, valid_colors, num_colors)) {
            strcpy(project->color, tempcolor);
            valid = 1; // Exit the loop
        } else {
            printf("That color isn't available for a %s. Please try again.\n", project_type);
        }
    }

    printf("Great choice! Now you have a %s with %d windows and the color %s.\n", project_type, project->windows, project->color);
}

int main() {
    int tempwin = 0;
    struct Projet Villa, House, Apartment;

    // Keep asking until the user provides a valid number of windows
    while (1) {
        printf("How many windows does your heart desire?\n");
        scanf("%d", &tempwin);

        if (tempwin > 50) {
            printf("Whoa, buddy! In this economy, the best we can do is 50. Try again.\n");
        } 
        else if (tempwin <= 50 && tempwin >= 25) {
            printf("So you chose a Villa. Great taste!\n");
            const char *villa_colors[] = {"Bleu", "Red", "Green"};
            create_project(&Villa, tempwin, "Villa", villa_colors, 3);
            break; // Exit the loop when valid input is processed
        } 
        else if (tempwin <= 10 && tempwin >= 5) {
            printf("So you chose a House.\n");
            const char *house_colors[] = {"Bleu", "White"};
            create_project(&House, tempwin, "House", house_colors, 2);
            break; // Exit the loop when valid input is processed
        } 
        else if (tempwin < 5 && tempwin >= 3) {
            printf("So you chose an Apartment.\n");
            const char *apartment_colors[] = {"White"};
            create_project(&Apartment, tempwin, "Apartment", apartment_colors, 1);
            break; // Exit the loop when valid input is processed
        } 
        else {
            printf("Please choose a realistic number of windows (minimum 3, maximum 50).\n");
        }
    }

    return 0;
}
