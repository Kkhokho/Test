#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int n, x[100];
void solution(){
    for (int i = 1; i <= n; i++){
        printf("%d", x[i]);
    }
    printf("\n"); // In ra tat ca xau nhi phan thoa man
}
void try(int i){
    for (int k = 0; k <= 1; k++){
        if ((x[i - 1] + k) < 2) {
            x[i] = k;
        }
        if (i == n) {
            solution();
        }  
        else {
            try(i + 1);
        }
    }
}// Thuat toan quay lui
int main (){ 
    printf("Nhap n= "); 
    scanf("%d", &n);
    try(1);
    return 0;
}