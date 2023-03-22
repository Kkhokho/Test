#include <stdio.h>
#include <stdlib.h>
#include <string.h>
enum {SUCCESS, FAIL, MAX_ELEMENT = 20};
// the phone book structure
typedef struct phoneaddress {
    char name[20];
    char tel[11];
    char email[25];
}phoneaddress;
int main(void){
FILE *fp;
    phoneaddress *phonearr;
    int i,n, irc; // return code
    int reval = SUCCESS;
    printf("Read from 2sd data to 3rd data \n");
    if ((fp = fopen("phonebook.dat","r+b")) == NULL){
    printf("Can not open %s.\n", "phonebook.dat");
    reval = FAIL;}
// Memory allocation
    phonearr = (phoneaddress *)malloc(2 * sizeof(phoneaddress));
    if (phonearr == NULL){
    printf("Memory allocation failed!\n");
    return FAIL;}
    if (fseek(fp,1*sizeof(phoneaddress),SEEK_SET) != 0){
    printf("Fseek failed!\n");
    return FAIL;}
    irc = fread(phonearr, sizeof(phoneaddress), 2, fp);
    for (i=0; i<2; i++){
        printf("%s-",phonearr[i].name);
        printf("%s-",phonearr[i].tel);
        printf("%s\n",phonearr[i].email);}
// Modifying some data
    strcpy(phonearr[2].name,"Lan Hoa");
    strcpy(phonearr[2].tel,"0923456");
    strcpy(phonearr[2].email,"lovelybuffalo@hut.edu.vn");
    fseek(fp,1*sizeof(phoneaddress),SEEK_SET);
    irc = fwrite(phonearr, sizeof(phoneaddress), 2, fp);
    printf(" fwrite return code = %d\n", irc);
    fclose(fp); 
    free(phonearr);
    return reval;}