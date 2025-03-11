#include <stdio.h>

int main(){

    int T[10]={-3,4,0,-7,3,8,0,-1,4,-9};
    int POS[10],i,j;
    for(j=0,i=0;i<10;i++)
    {
        if(*(T+i)>0)
        {
            *(POS+j) = *(T+i);
            j++;
        }
    }
    return 0;
}