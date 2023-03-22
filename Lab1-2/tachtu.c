#include <stdio.h>
#include <string.h>
void hienthi(char s[100][20],int size)
{
    for (int i=0;i<size;i++){
        printf("%s\n",s[i]);
    }
}
void tachtu(char s[])
{
    char res[100][20];
    int i=0;
    char *p;
    const char *delim = " \t.,\n";
    for (p=strtok(s,delim) ;p!=NULL ;p=strtok(NULL,delim)){
        strcpy(res[i++],p);
    }
    hienthi(res,i);
}
int main()
{
    char s[1000];
    fflush(stdin);
    fgets(s,999,stdin);
    s[strlen(s)]='\0';
    tachtu(s);
    return 0;
}