#include <stdio.h>
#include <stdlib.h>

int main(){
    int target=0,i,j,n=0,counter;
    printf("Whats the length of your table?\n");
    scanf(" %d" ,&n);
    int nums[n];
    for(i=0;i<n;i++){
        printf("Give the number %d of the table\n",i+1);
        scanf(" %d" ,&nums[i]);
    }
    printf("What's your target?\n");
    scanf(" %d" ,&target);
    /*The first number is capable of doing n-1 operation to the arrar, if isn't met the target, it goes to the next number wich do n-2 operation, and do on, if its not met at all numbers of arrarys, it ends*/
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            counter=0;
            counter=nums[i]+nums[j];
        }
    }
    if(counter==target){
        printf("There is a match\n");
    }
    else{
        printf("There is no match\n");
    }
    return 0;
}