#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argc, char* argv[]){
    if (argc != 3){
        printf("Wrong number of arguments!\n");
        return 0;
}
    double x = atof(argv[1]);
    double y = atof(argv[2]);    
    long long giaithua = 1;
    int k=0;
    double a = 1;
    double kq = 0;
    double tam = a / giaithua;
    while (tam >= y){
        kq = kq + tam;
        k++;
        a = a * x;
        giaithua = giaithua * k;
        tam = a / giaithua;
    }    
printf("e^%0.2lf = %0.2lf\n", x, kq);
return 0;
}