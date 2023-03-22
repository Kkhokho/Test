#include <stdio.h>
int n;
int x[10];
void solution(){
    for (int i=1;i<=n;i++){
        printf("%d",x[i]);
    }
    printf("\n");
}
void try(int k){
    for (int v=0;v<=1;v++){
        if ((x[k-1] + v) < 2 ){
        x[k] = v;
        if (k==n) solution();
        else try(k+1);
    }}
}
int main(){
    scanf("%d",&n);
    try(1);
    return 0;
}