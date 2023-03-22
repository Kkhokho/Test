#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int GetRandom(int min,int max){
    return min + (int)(rand()*(max-min+1.0)/(1.0+RAND_MAX));
}
int main(){
    int i=1;
    char article[5][10] = {"The","A","One","Some","Any"};
    char noun[5][10] = {"boy","girl","dog","town","car"};
    char verb[5][10] = {"drove","jumpep","ran","walked","skipped"};
    char pre[5][10] = {"to","from","over","under","on"};
    while (i<=10)
    {
        printf("%s %s %s %s %s\n",article[GetRandom(1,5)],noun[GetRandom(1,5)],verb[GetRandom(1,5)],pre[GetRandom(1,5)],noun[GetRandom(1,5)]);
        i++;
    }
    return 0;
    
}