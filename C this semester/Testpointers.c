#include <stdio.h>

int main(){

    char c1,c2;
    long a,b;
    int *ptr;
    int i=5;
    int tab[8]={1,2,3,4,5,6,7,8};
    ptr=tab;
    printf("%d %d %d",*(ptr+1),ptr+1,&tab[0]);

    return 0;
}