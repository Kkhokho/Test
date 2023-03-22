#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_L 256
int main()
{
    FILE *f = fopen("C.txt", "r");

    for (int i = 0; i < 3; i++)
    {
        char s1[MAX_L];
        fgets(s1, MAX_L, f);
        s1[strlen(s1) - 1] = '\0';
        printf("%s\n", s1);
        char s2[MAX_L], s3[MAX_L];
        fgets(s2, MAX_L, f);
        s2[strlen(s2) - 1] = '\0';
        printf("%s\n", s2);
        fgets(s3, MAX_L, f);
        s3[strlen(s3) - 1] = s3[strlen(s3) - 1] == '\n' ? '\0' : s3[strlen(s3) - 1];
        printf("%s\n", s3);
    }
    fclose(f);
    return 0;
}