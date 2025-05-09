#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <strings.h> 

struct Model {
    char mois[15];
    float an;
};

struct voiture {
    char marque[15];
    char carburant[15];
    float prix;
    struct Model m;
};

void AfficherTous(struct voiture vt[10]) {
    for (int i = 0; i < 10; i++) {
        printf("%s\t%s\t%s %.1f\t%.1f\n", vt[i].marque, vt[i].carburant, vt[i].m.mois, vt[i].m.an, vt[i].prix);
    }
}

void ExpenVoiture(struct voiture vt[10]) {
    int maxIndex = 0;
    for (int i = 1; i < 10; i++) {
        if (vt[i].prix > vt[maxIndex].prix) {
            maxIndex = i;
        }
    }
    printf("Voiture la plus chère:\n");
    printf("%s\t%s\t%s %.1f\t%.1f\n", vt[maxIndex].marque, vt[maxIndex].carburant, vt[maxIndex].m.mois, vt[maxIndex].m.an, vt[maxIndex].prix);
}

void ChercherVoit(struct voiture vt[10]) {
    int found = 0;
    char Temp1[20], Temp2[20];
    printf("Donner le nom du marque:\n");
    scanf(" %s", Temp1);
    printf("Donner le type de carburant:\n");
    scanf(" %s", Temp2);
    
    for (int i = 0; i < 10; i++) {
        if (strcmpi(Temp1, vt[i].marque) == 0 && strcmpi(Temp2, vt[i].carburant) == 0) {
            printf("Voiture trouvée:\n");
            printf("%s\t%s\t%s %.1f\t%.1f\n", vt[i].marque, vt[i].carburant, vt[i].m.mois, vt[i].m.an, vt[i].prix);
            found++;
        }
    }

    if (!found) {
        printf("Voiture non trouvée!\n");
    }
}

void UniquementDiesel(struct voiture vt[10]) {
    int found = 0;
    for (int i = 0; i < 10; i++) {
        if (strcmpi("diesel", vt[i].carburant) == 0) {
            printf("Voiture diesel trouvée!\n");
            printf("%s\t%s\t%s %.1f\t%.1f\n", vt[i].marque, vt[i].carburant, vt[i].m.mois, vt[i].m.an, vt[i].prix);
            found++;
        }
    }
    if (!found) {
        printf("Aucune voiture diesel trouvée!\n");
    }
}

int main() {
    struct voiture vt[10] = {
        {"Toyota", "diesel", 15000, {"Janvier", 2018}},
        {"BMW", "essence", 30000, {"Fevrier", 2019}},
        {"Renault", "diesel", 18000, {"Mars", 2020}},
        {"Audi", "essence", 35000, {"Avril", 2021}},
        {"Ford", "diesel", 25000, {"Mai", 2022}},
        {"Honda", "essence", 22000, {"Juin", 2017}},
        {"Peugeot", "diesel", 24000, {"Juillet", 2016}},
        {"Hyundai", "essence", 19000, {"Aout", 2015}},
        {"Kia", "diesel", 16000, {"Septembre", 2014}},
        {"Mazda", "essence", 21000, {"Octobre", 2013}},
    };

    int input;
    while (1) {
        printf("\nChoisir votre service:\n");
        printf("0. Quitter\n");
        printf("1. AfficherTous\n");
        printf("2. ExpenVoiture\n");
        printf("3. UniquementDiesel\n");
        printf("4. ChercherVoit\n");
        printf("-> ");
        scanf(" %d", &input);

        if (input < 0 || input > 4) {
            printf("Entrée invalide!\n");
            return 0;
        }

        switch (input) {
            case 0:
                return 0;
            case 1:
                AfficherTous(vt);
                break;
            case 2:
                ExpenVoiture(vt);
                break;
            case 3:
                UniquementDiesel(vt);
                break;
            case 4:
                ChercherVoit(vt);
                break;
        }
    }

    return 0;
}
