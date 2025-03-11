#include <stdio.h>

int main(){

    int tab[] = {4,10,20,1,12,-1,-5,15};
    int *tab1;
    tab1=tab;
    tab=(tab1+1);
    printf("%d",tab);
    return 0;
}