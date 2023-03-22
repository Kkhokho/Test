#include <stdio.h>
#include <string.h>
enum {SUCCESS,FAIL,MAX_LEN = 81};
void LineReadWrite(FILE *fin,FILE *fout){
    char buff[MAX_LEN];
    while (fgets(buff,MAX_LEN,fin) != NULL){
        fputs(buff,fout);
        printf("%s",buff);
    }
}
void LineRead(FILE *f1,FILE *f2){
    char buff[MAX_LEN];
    if ((fgets(buff,MAX_LEN,f1)) == NULL){
        fputs(buff,f2);
        return ;
    }
}
int main(int argc, char **argv) {
    FILE *fptr1,*fptr;
    char filename[] = "temp.txt";
    fptr  = fopen(filename,"a");
    fptr1 = fopen(argv[1],"a");
    //fptr2 = fopen(argv[2],"a");
    LineRead(fptr1,fptr);
    LineReadWrite(fptr,fptr1);
    return 0;
}