#include <stdio.h>
#include <string.h>
enum {SUCCESS,FAIL,MAX_LEN = 81};
void Read(FILE *fin){
    char buff[MAX_LEN];
    while ( fgets(buff,MAX_LEN,fin) != NULL){
        printf("%s",buff);
    }
}
int main(int argc, char **argv) {
    FILE *fptr1;
    if ((fptr1 = fopen(argv[1], "r")) == NULL){
        printf("Cannot open %s.\n", argv[1]);
    } else {
        Read(fptr1);
        fclose(fptr1);
    }
    return 0;
}