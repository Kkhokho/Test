// Online C compiler to run C program online
#include <stdio.h>

int main() {
    int c=0;
    int n;
    int a[100];
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    a[n+1]=0;
    for (int i=1;i<=n-1;i++){
        if (a[i+1]-a[i]==1){
            c++;
        }else {
            if (c>0){ printf("%d - %d,"a[i-c],a[i]);
            }else{
                if (c==0) printf("%d, ",a[i])
            }
        //printf("%d ",i);
    }}
    //printf("Hello world");

    return 0;
}