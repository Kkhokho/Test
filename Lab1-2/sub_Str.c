#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char* subStr(char* s1, int offset, int number){
    char *result;
    int j=0;
    result = (char *)malloc((number)*sizeof(char));
    int len =strlen(s1);
    if ((offset+number) > len){
        for(int i=offset;i<len;i++){
            result[j]=s1[i];
            j++;
        }
    }else{
        for (int i=offset;i<=offset+number;i++){
            result[j]=s1[i];
            j++;
        }
    }
    result[j]='\0';
    return result;
}
int main(){
    char s1[20];
    printf("Enter a string:");
    scanf("%s",s1);
    int a,b;
    scanf("%d%d",&a,&b);
    puts(subStr(s1,a,b));
    return 0;
}
