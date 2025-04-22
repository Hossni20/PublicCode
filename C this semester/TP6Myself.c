#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void SupprimerNegatives(float *T1,float T2, int N){
int M=0;
for(int i=0;i<N;i++){
    if(*(T1+i)<0){
        M++;
    }
}
float *T2 = (float*)realloc(T2,M*sizeof(float));
if(T2==NULL){
    exit(1);
}
else
{
    int count = 0;
    for(int i=0;i<N;i++){
        if(*(T1+i)<0){
            (T2+count)=(T1+i);
            count++;
        }
    }
}
float T1 = (float)realloc(T1,(N-M)*sizeof(float));
for(int i=0;i<(N-M);i++){
    printf("%.2f\t",*(T1+i));
}
for(int i=0;i<M;i++){
    printf("%.2f\t",*(T2+i));
}
}
int main(){
int N;
printf("Saisir la taille du tableau:\n");
scanf("%d",&N);
float *TableauT2 = NULL;   
float TableauT1 = (float)malloc(N*sizeof(float));
if(TableauT1==NULL){
    exit(1);
}
else
{
        for(int i=0;i<N;i++){
            printf("saisir les nombre:\n");
            scanf("%f",(TableauT1+i));
        }
}
for(int i=0;i<N;i++){
    printf("%.2f\t",*(TableauT1+i)); //à vérifier le code
}
SupprimerNegatives(TableauT1,TableauT2);
free(TableauT1);
free(TableauT2);
    return 0;
}