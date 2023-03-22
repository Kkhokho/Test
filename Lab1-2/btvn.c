#include <stdio.h>
typedef struct{
int id;
char name[30];
char phone[11];
}infor;
int main(){
FILE *ptr1,*ptr2;
infor arr[20];
double a[20];
int i=0;
ptr1 = fopen("ds.txt","r");
ptr2 = fopen("bangdiem.txt","w");
 while (fscanf(ptr1,"%d%s%s", &arr[i].id, arr[i].name, arr[i].phone) != EOF){
    fprintf(ptr2,"%d ",arr[i].id);
    fprintf(ptr2,"%s ",arr[i].name);
    fprintf(ptr2,"%s ",arr[i].phone);
    printf("Nhap diem cua sinh vien %d: ",i+1);
    scanf("%lf",&a[i]);
    fprintf(ptr2,"%.2lf ",a[i]);
    fprintf(ptr2,"%s","\n");
    i++;}
    fclose(ptr1);
    fclose(ptr2);
return 0;
}