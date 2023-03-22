#include <stdio.h>
enum {SUCCESS,FAIL};
void CharReadWrite(FILE *fin,FILE *fout){
    int c;
    while ( (c=fgetc(fin)) != EOF ){
        fputc(c,fout);
        putchar(c);
    }
}
main(void) {
    FILE *fptr1, *fptr2;
    char filename1[]= "lab1a.txt";
    char filename2[]= "lab1.txt";
    int reval = SUCCESS;
    if ((fptr1 = fopen(filename1, "w")) == NULL){
        printf("Cannot open %s.\n", filename1);
        reval = FAIL;
    } else if ((fptr2 = fopen(filename2, "r")) == NULL){
        printf("Cannot open %s.\n", filename2);
        reval = FAIL;
    } else {
        CharReadWrite(fptr2, fptr1);
        fclose(fptr1);
        fclose(fptr2);
    }
    return reval;
}
