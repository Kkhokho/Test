#include <stdio.h>
#include <stdlib.h>
void LineReadWrite(FILE *fin,FILE *fout){
    int c;
    while ( (c=fgetc(fin)) != EOF){
        fputc(c,fout);
        putchar(c);
    }
}
int main(int argc,char **argv){
    if (argc != 3){
        printf("ERROR\n");
    }
    FILE *f1,*f2;
    f1 = fopen(argv[1],"r");
    f2 = fopen(argv[2],"a");
    LineReadWrite(f1,f2);
    fclose(f1);
    fclose(f2);
    return 0;
}