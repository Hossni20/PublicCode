#include <stdio.h>
int main () {
int var;
int *p;
int  **pp;
var = 5000;
/* prendl'adressede var*/
p = &var;
/* prendl'adressede p enutilisantl'opérateur& */
pp = &p;
/* prendla valeurenutilisantpp*/
printf("Valeur de var = %d \n", var);
printf("Valeur disponible à *p = %d \n", *p );
printf("Valeur disponible à **pp = %d \n", **pp );
return 0;
}