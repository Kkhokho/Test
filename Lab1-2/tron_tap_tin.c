#include <stdio.h>
#include <string.h>
enum {MAX_LEN = 81};
void LineReadWrite(FILE *fin,FILE *fout){
    char buff[MAX_LEN];
    while ( fgets(buff,MAX_LEN,fin) != NULL){
        fputs(buff,fout);
        printf("%s",buff);
    }
}
int main(int argc, char **argv) {
    FILE *fptr1, *fptr2,*fptr3;
    if (argc != 4) printf("ERROR\n");
    if ((fptr1 = fopen(argv[1], "a+")) == NULL){
        printf("Cannot open %s.\n", argv[1]);
    } else if ((fptr2 = fopen(argv[2], "a+")) == NULL){
        printf("Cannot open %s.\n", argv[2]);
    } else if ((fptr3 = fopen(argv[3], "a+")) == NULL){
        printf("Cannot open %s.\n", argv[3]);
    } else {
        LineReadWrite(fptr2, fptr1);
        LineReadWrite(fptr3, fptr1);
        fclose(fptr1);
        fclose(fptr2);
        fclose(fptr3);
    }
    return 0;
}