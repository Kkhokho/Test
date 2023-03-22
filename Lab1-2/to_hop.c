#include <stdio.h>
#define MAX 25
int m[MAX][MAX];
int C(int n,int k){
    if (k==0 || k==n){
        m[n][k] = 1;}
    else{
    if (m[n][k] < 0){
        m[n][k] = C(n-1,k-1) + C(n-1,k);}}
    return m[n][k];
}
int main(){
for (int i=0;i<MAX;i++){
    for (int j=0;j<MAX;j++){
        m[i][j] = -1;}}
   int n,k;
   scanf("%d %d",&n,&k);
   printf("%d",C(k,n));
   return 0; 
}