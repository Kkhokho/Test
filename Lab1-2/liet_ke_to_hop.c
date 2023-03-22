#include <stdio.h>
int n,k,x[10];
void solution(){
    for (int i=1;i<k;i++){
        printf("%d ",x[i]);}
    printf("\n");
}
void TRY(int i){
    for(int v = x[i-1]+1; v <= n-k+i; v++){
        x[i] = v;
        if(i == k)   
            solution();
        else TRY(i+1);}}
int main(){
    scanf("%d%d",&n,&k);
    x[0] = 0;
    TRY(1);
    return 0;}