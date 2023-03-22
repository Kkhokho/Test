#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define MAX_L 256
enum number {a=3,b,c};
enum number n = 20210492;
enum number foo(){
    return n;

}
int main(){
    printf("%d\n",n);
if (foo() == b){
    printf("YES\n");
    
}else printf("NO\n");
//printf("%d %d",b,c);
}