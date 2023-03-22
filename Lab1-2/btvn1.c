#include <stdio.h>
#define MAX_LEN 30
typedef struct{
    int id;
    char name[30];
    char phone[11];
}infor;
int LineReadWrite(FILE *fin){
    char buff[MAX_LEN]; 
    int count =0; 
    while (fgets(buff, MAX_LEN, fin) != NULL) {
    count++; printf("%s", buff);}
    return count;}
int main(){
    FILE *ptr1,*ptr2;
    infor *arr;
    double a[20];
    int i=0;
    ptr1 = fopen("ds.txt","r");
    int c = LineReadWrite(ptr1); 
    ptr2 = fopen("bangdiem.txt","w");
    arr = (infor*)malloc(c*sizeof(infor));
    while (fscanf(ptr1,"%d%s%s", &arr[i].id, arr[i].name, arr[i].phone) != EOF){
        fprintf(ptr2,"%d ",arr[i].id);
        fprintf(ptr2,"%s ",arr[i].name);
        fprintf(ptr2,"%s ",arr[i].phone);
        printf("Nhap diem cua sinh vien %d: ",i+1);
        scanf("%lf",&a[i]);
        fprintf(ptr2,"%.2lf ",a[i]);
        fprintf(ptr2,"%s","\n");
        i++;}
    printf("So luong sinh vien can nhap bo sung: ");
    int t;
    scanf("%d",&t);
    arr = (infor*)realloc(arr,t);    
    fclose(ptr1);
    fclose(ptr2);
return 0;
}