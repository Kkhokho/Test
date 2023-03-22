#include <stdio.h>
#include <string.h>
typedef struct
{
    char name[30];
}rs;
void nhapten(rs s[],int* n){
    for (int i=0;i<*n;i++){
        fflush(stdin);
        fgets(s[i].name,29,stdin);
      //  s[i].name[strlen(s[i].name)-1] = NULL;
    }
}
void swap(rs *a,rs *b){
    rs tmp = *a;
        *a = *b;
        *b = tmp;
}
void sort(rs s[],int n){
    for (int i=0;i<n-1;i++){
        for (int j=i;j<n;j++){
            if (strcmp(s[i].name,s[j].name) < 0) swap(&s[i],&s[j]);
        }
    }
}
void display(rs s[],int n){
    sort(s,n);
    for (int i=0;i<n;i++){
        printf("%s",s[i].name);
    }
}
int main()
{
    rs s[20];
    int n;
    scanf("%d",&n);
    nhapten(s,&n);
    printf("\n");
    display(s,n);
    return 0;
}