#include <stdio.h>
#include <string.h>
#include <time.h>
#define MAX_LEN 80
void CharReadWrite(FILE *fin1, FILE *fout1){
    clock_t start,end;
    start = clock();
    double time_use;
    int c;
    while ((c=fgetc(fin1)) != EOF){
    fputc(c, fout1); }
    end = clock();
    time_use = (double)(end-start) / CLOCKS_PER_SEC;
    printf("Thoi gian: %.lf\n",time_use);}
void LineReadWrite(FILE *fin, FILE *fout){
    char buff[MAX_LEN]; 
    double time_use;
    clock_t start,end;
    start = clock();
    while (fgets(buff, MAX_LEN, fin) != NULL) {
        fputs(buff, fout);}
    end = clock();
    time_use = (double)(end-start) / CLOCKS_PER_SEC;
    printf("Thoi gian: %lf\n",time_use);}
void BlockReadWrite(FILE *fin2, FILE *fout2) {
    clock_t start,end;
    start = clock();
    int num;
    double time_use;
    char buff[MAX_LEN + 1];
    while (!feof(fin2)){
    num = fread(buff, sizeof(char), MAX_LEN, fin2);
    buff[num * sizeof(char)] = '\0'; 
    //printf("%s", buff);
    fwrite(buff, sizeof(char), num, fout2);}
    end = clock();
    time_use = (double)(end-start) / CLOCKS_PER_SEC;
    printf("Thoi gian: %lf\n",time_use);}
int main(){
    FILE *ptr1,*ptr2;
    int n;
    int t = 1;
    while(t==1){
    ptr1 = fopen("lab.txt","r");
    ptr2 = fopen("out.txt","w");
    printf("1.  Copy by character\n");
    printf("2.  Copy by line\n");
    printf("3.  Copy by block - optional size\n");
    printf("4.  Quit\n");
    printf("Nhap chuc nang: ");
    scanf("%d",&n);
    switch (n)
    {
    case 1: CharReadWrite(ptr1,ptr2);
        break;
    case 2: LineReadWrite(ptr1,ptr2);
        break;
    case 3: BlockReadWrite(ptr1,ptr2);
        break;
    case 4: t = 0;
        break;
    default:t = 0;
        break;
    }
    }   
    return 0;
}
