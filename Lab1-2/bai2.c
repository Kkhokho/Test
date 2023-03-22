#include <stdio.h>
#include <string.h>
#define length_alphabet 26
int main()
{
    char s[20];
    printf("Nhap xau ky tu: ");
    fflush(stdin);
    fgets(s,20,stdin);
    s[strlen(s)-1]='\0';
    char c='\0';
    int count[length_alphabet];
    for (int i=0;i<length_alphabet;i++)
    {
        count[i] = 0;
    }
    for (int i=0;i < strlen(s); i++)
    {
       c = s[i];
       if (c > 'a' && c < 'z') count[c-'a']++;
       if (c > 'A' && c < 'Z') count[c-'A']++;
    }
    for (int i=0;i<length_alphabet;i++)
    {   if (count[i]>0)
    {
        printf("The letter '%c' appears %d times\n",'a'+i,count[i]);
    }
    }
    return 0;
}