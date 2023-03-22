#include <stdio.h>
int n,m[100],x[100];
void solution(){
    for (int i=1;i<=n;i++){
        printf("%d",x[i]);
    }
    printf("\n");}
void try(int i){
    for (int v=1;v<=n;v++){
        if(m[v]==0){
            x[i]=v;
            m[v]=1;
            if (i==n) solution();
            else try(i+1);
            m[v]=0;}
    }
}
int main(){
    scanf("%d",&n);
    x[0]=0;
    try(1);
    return 0;
}
