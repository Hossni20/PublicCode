#include <stdio.h>
// le type dans printf matters
int main(){

    char a[3] = "Cat";
    char *p;
    p = a;
    printf(" %s\n",&p[0]); // le p pointe sur a qui a le contenu de type char
    printf("%d",&p); // le p printe son adresse qui a une type int
    return 0;
}