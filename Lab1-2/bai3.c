#include <stdio.h>
int check(int a[100],int b[100],int n)
{ int d=0;
for (int i=0;i<n;i++){
    if (a[i] == b[n-i-1]) d++;
}
if (d==n) return -1;
for (int i=0;i<n;i++){
    if (a[i] != b[i]) return 0;
    else return 1;
}
}
int main()
{
int n,a[100],b[100];
printf("Nhap so luong phan tu: ");
scanf("%d",&n);
for (int i=0;i<n;i++)
{
    scanf("%d",&a[i]);
}
for (int i=0;i<n;i++)
{
    scanf("%d",&b[i]);
}
printf("%d",check(a,b,n));
return 0;
}