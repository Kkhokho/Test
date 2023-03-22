#include <stdio.h>
enum {SUCCESS, FAIL, MAX_ELEMENT = 10};
typedef struct {
int no;
char name[20];
double price;
}product ;
int main(void){
FILE *fp,*fp1;
product arr[MAX_ELEMENT];
int i=0,n; 
int reval = SUCCESS;
printf("Loading file...\n");
fp1 = fopen("out.txt","w");
if ((fp = fopen("product.txt","r")) == NULL){
printf("Can not open %s.\n", "product.txt");
reval = FAIL;
}
else {
    printf("%-6s%-24s%-9s\n","NO","Product","Price");
    while (fscanf(fp,"%d%s%lf", &arr[i].no, arr[i].name, &arr[i].price) != EOF){
    printf("%-6d%-24s%-6.2f\n",arr[i].no,arr[i].name,arr[i].price);
    fprintf(fp1,"%-6d ",arr[i].no);
    fprintf(fp1,"%-24s ",arr[i].name);
    fprintf(fp1,"%-9.2lf ",arr[i].price);
    fprintf(fp1,"%s","\n");
    i++;} }
fclose(fp);
return reval;
}
