#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//author: Cao Tuan Dung
//for HEDSPI project
enum{SUCCESS, FAIL};
int main(void){
    FILE *fp;
    int*p;
    int i,n, value, sum;
    int reval= SUCCESS;
    printf("Enter a listof numberswiththe first isthe size of list: \n");
    scanf("%d", &n);p = (int*)malloc(n*sizeof(int)); 
    i=0; 
    sum=0;
    while(i<n){
        scanf("%d", &value);
        p[i++]=value;
        sum+=value;}
    if ((fp= fopen("out.txt","w")) == NULL){
        printf("Can not open %s.\n", "out.txt");
        reval= FAIL;}
    for (i=n-1; i>=0;i--){
        fprintf(fp,"%d ",p[i]);}
        fprintf(fp,"%d ",sum);
        fclose(fp);
        free(p);
        return reval;
}