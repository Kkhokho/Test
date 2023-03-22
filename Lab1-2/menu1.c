#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 81
typedef struct{
int id;
char *name;
char *phone;
int mark;
}infor;
infor *arr;
int LineReadWrite(FILE *fin){
    char buff[MAX_LEN]; 
    int count =0; 
    while (fgets(buff, MAX_LEN, fin) != NULL) {
    count++;}
    return count;}
int main(){
    int n,t=1;
    FILE *f1,*f2;
    f1 = fopen("bangdiem.txt","w+");
    f2 = fopen("grade.dat","w+b");
    int c = LineReadWrite(f1);
    while (t)
    {
    printf("1.  TextToDat\n");
    printf("2.  Display Dat file\n");
    printf("3.  Search and Update\n");
    printf("4.  Quit\n");
    printf("Nhap chuc nang: ");
    scanf("%d",&n);
    switch (n)
    {
    case 1: arr = (infor *)malloc(c*sizeof(infor));
        for (int i=0;i<c;i++){
            fscanf(f1,"%d",&arr[i].id);
            fscanf(f1,"%s",&arr[i].name);
            fscanf(f1,"%s",&arr[i].phone);
            fscanf(f1,"%d",&arr[i].mark);
        }
        fwrite(arr,sizeof(infor),c,f2);
        fclose(f1);
        fclose(f2);
        break;
    case 2: arr = (infor *)malloc(c*sizeof(infor));
            fread(arr,sizeof(infor),c,f2);
            for (int i=0;i<c;i++){
                printf("%d %s %s %d\n",arr[i].id,arr[i].name,arr[i].phone,arr[i].mark);
            }
            fclose(f2);
        break;
    case 3: arr = (infor *)malloc(c*sizeof(infor));
            fread(arr,sizeof(infor),c,f2);
            printf("Nhap MSSV muon tim: ");
            int num,loc;
            scanf("%d",&num);
            for (int i=0;i<c;i++){
                if (arr[i].id == num) {
                    printf("%d %s %s %d\n",arr[i].id,arr[i].name,arr[i].phone,arr[i].mark);
                    loc=i;
                }
            printf("Hay cap nhat diem cho sinh vien nay: ");
            scanf("%d",&arr[i].mark);
            fprintf(f2,"%d",arr[i].mark);
            fclose(f2);
            }
        break;
    case 4: t=0;
        break;
    default: t=0;
        break;
    }
    }
   return 0; 
}