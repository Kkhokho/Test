#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(int argc, char *argv[])
{
    double a, b, c;
    if (argc != 4)
    {
        printf("Wrong number of arguments!\n");
        return 1;
    }
    a = atof(argv[1]);
    b = atof(argv[2]);
    c = atof(argv[3]);
    double denta = b * b - 4 * a * c;
    if (a == 0)
    {
        if (b == 0 && c != 0)
        {
            printf("Pt vo nghiem!");
        }
        else if (b == 0 && c == 0)
        {
            printf("Pt vo so nghiem!");
        }
        else if (b != 0)
        {
            printf("phuong trinh co nghiem: %.2lf", -c / b);
        }
    }
    else
    {
        if (denta < 0)
        {
            printf("Pt co 2 nghiem phuc: %lf+%lfi,%lf-%lfi",-b/2*a,sqrt(-denta)/2*a,-b/2*a,sqrt(-denta)/2*a);
        }
        else if (denta == 0)
        {
            printf("Pt co nghiem duy nhat:%.2lf", -b / 2 * a);
        }
        else
        {
            printf("x1=%.2lf,x2=%.2lf", (-b + sqrt(denta)) / 2 * a, (-b - sqrt(denta)) / 2 * a);
        }
    }
    return 0;
}