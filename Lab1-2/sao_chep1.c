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
int main(int argc, char **argv) {
    FILE *fptr1, *fptr2;
    if ((fptr1 = fopen(argv[1], "r")) == NULL){
        printf("Cannot open %s.\n", argv[1]);
    } else if ((fptr2 = fopen(argv[2], "a")) == NULL){
        printf("Cannot open %s.\n", argv[2]);
    } else {
        LineReadWrite(fptr1, fptr2);
        fclose(fptr1);
        fclose(fptr2);
    }
    return 0;
}