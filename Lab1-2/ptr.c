#include <stdio.h>
int x[100],a[100],n,m,sum=0;
void solution(){
    for (int i=1;i<=n;i++){
        printf("x[%d]=%d\n",i,x[i]);
    }
}
int check(int v,int k){
    if ((v+k)>m) return 0;
    return 1;
}
void try(int k){
    for (int i=1;i<m;i++){
        if (check(sum,a[k]*i)){
            x[k] = i;
            sum = sum + a[k]*x[k];
            if (k==n) solution();
            else try(k+1);
        }
    }
}
int main(){
    scanf("%d",&n);
    scanf("%d",&m);
    for (int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    try(1);
    return 0;
}