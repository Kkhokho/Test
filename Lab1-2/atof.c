#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
   float val;
   char str[20];
   
   strcpy(str, "98993489");
   val = atof(str);
   printf("Gia tri duoi dang chuoi = %s, \nGia tri duoi dang so thuc = %f\n", str, val);

   strcpy(str, "QTM.com");
   val = atof(str);
   printf("\nGia tri duoi dang chuoi = %s, \nGia tri duoi dang so thuc = %f\n", str, val);

   return(0);
}