#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX 800
typedef struct Profile
{
    char place[41];
    int gio;
    int phut;
    struct Profile *next;
} Profile;

Profile *first, *last;

Profile *makenode(char *place, int gio, int phut)
{
    Profile *node = (Profile *)malloc(sizeof(Profile));
    strcpy(node->place, place);
    node->gio = gio;
    node->phut = phut;
    node->next = NULL;
    return node;
}

void initList()
{
    first = NULL;
    last = NULL;
}

int listEmpty()
{
    return (first == NULL && last == NULL);
}

void insertLast(char *place, int gio, int phut)
{
    Profile *profile = makenode(place, gio, phut);
    if (listEmpty())
    {
        first = profile;
        last = profile;
    }
    else
    {
        last->next = profile;
        last = profile;
    }
}

void load(char *filename)
{
    FILE *f = fopen(filename, "r");
    if (f == NULL)
        printf("Load data -> file not found!\n");

    while (!feof(f))
    {
        char Place[41];
        int Gio;
        int Phut;
        fscanf(f, "%s", Place);
        fscanf(f, "%d%d", &Gio, &Phut);
        insertLast(Place, Gio, Phut);
    }
    fclose(f);
    for (Profile *p=first;p!=NULL;p=p->next){
        if (p->next==NULL){
            last = p;
        }
    }
}

void printList()
{
    printf("%-50s%-10s%-10s\n", "Dia diem", "Gio", "Phut");
    for (Profile *p = first; p != NULL; p = p->next)
    {
        printf("%-50s%-10d%-10d\n", p->place, p->gio, p->phut);
    }
}

void cn3()
{
    char name[256];
    printf("Nhap dia diem muon tra cuu: ");
    scanf("%s", name);
    int x = 0;
    int c = 0;
    for (Profile *p = first; p != NULL; p = p->next)
    {
        if (strcmp(p->place, name) == 0)
        {
            c++;
        }
    }

    int j = 0;
    for (Profile *p = first; p != NULL; p = p->next)
    {
        if (strcmp(p->place, name) == 0)
        {
            x = 1;
            j++;
            if (j != c)
                printf("%d : %d, ", p->gio, p->phut);
            else
                printf("%d : %d", p->gio, p->phut);
        }
    }
    if (x == 0)
        printf("Ban chua toi dia diem do !\n");
}

void cn4()
{
    int g, ph;
    do
    {   
        printf("Nhap vao thoi gian: ");
        scanf("%d%d", &g, &ph);
    } while (g < 0 || g > 24 || ph < 0 || ph > 60);
    int x = 0;

    Profile *gancuoi = NULL;
    for (Profile *p = first; p != NULL; p = p->next)
    {
        if (p->next == last)
            gancuoi = p;
    }

    if (last->gio == g && ph < last->phut)
        {x = 1; 
        printf("%s", gancuoi->place);}
    else if (last->gio == g && ph > last->phut)
        {x = 1; 
        printf("%s", last->place);}
    else if (last->gio < g)
        {x = 1; 
        printf("%s", last->place);}
    else
    {
        for (Profile *p = first; p != NULL; p = p->next)
        {
            if (p->gio == g && p->phut == ph)
            {
                x = 1;
                printf("%s", p->place);
            }
            if (p->gio == g && p->next->gio == g && p->phut < ph && p->next->phut > ph)
            {
                x = 1;
                printf("%s", p->place);
            }
            if (p->gio == g && p->next->gio > g && p->phut < ph)
            {
                x = 1;
                printf("%s", p->place);
            }
            if (p->gio < g && p->next->gio > g)
            {
                x = 1;
                printf("%s", p->place);
            }
            if (p->gio < g && p->next->gio == g && p->next->phut > ph)
            {
                x = 1;
                printf("%s", p->place);
            }
        }
    }
    if (x == 0)
        printf("KHONG tim thay lich su di chuyen !\n");
}

void cn5()
{
    char diadiem[41];
    int g, ph;
    scanf("%s%d%d", diadiem, &g, &ph);

    int x = 0;
    Profile *gancuoi = NULL;
    for (Profile *p = first; p != NULL; p = p->next)
    {
        if (p->next == last)
            gancuoi = p;
    }

    if (strcmp(diadiem, last->place) == 0 && last->gio == g && ph < last->phut)
        {x = 1;
        printf("Ban co kha nang bi lay Covid, can phai khai bao ngay lap tuc !\n");}
    else if (strcmp(diadiem, last->place) == 0 && last->gio == g && ph > last->phut)
        {x = 1;
        printf("Ban co kha nang bi lay Covid, can phai khai bao ngay lap tuc !\n");}
    else if (strcmp(diadiem, last->place) == 0 && last->gio < g)
        {x = 1;
        printf("Ban co kha nang bi lay Covid, can phai khai bao ngay lap tuc !\n");}
    else
    {
        for (Profile *p = first; p != NULL; p = p->next)
        {
            if (strcmp(diadiem, p->place) == 0 && p->gio == g && p->phut == ph)
            {
                x = 1;
                printf("Ban co kha nang bi lay Covid, can phai khai bao ngay lap tuc !\n");
            }
            if (strcmp(diadiem, p->place) == 0 && p->gio == g && p->next->gio == g && p->phut < ph && p->next->phut > ph)
            {
                x = 1;
                printf("Ban co kha nang bi lay Covid, can phai khai bao ngay lap tuc !\n");
            }
            if (strcmp(diadiem, p->place) == 0 && p->gio == g && p->next->gio > g && p->phut < ph)
            {
                x = 1;
                printf("Ban co kha nang bi lay Covid, can phai khai bao ngay lap tuc !\n");
            }
            if (strcmp(diadiem, p->place) == 0 && p->gio < g && p->next->gio > g)
            {
                x = 1;
                printf("Ban co kha nang bi lay Covid, can phai khai bao ngay lap tuc !\n");
            }
            if (strcmp(diadiem, p->place) == 0 && p->gio < g && p->next->gio == g && p->next->phut > ph)
            {
                x = 1;
                printf("Ban co kha nang bi lay Covid, can phai khai bao ngay lap tuc !\n");
            }
        }
    }
    if (x == 0)
        printf("Lich su di chuyen cua ban OK!\n");
}

void freelist()
{
    Profile *p = first, *temp;

    while (p != NULL)
    {
        temp = p->next;
        free(p);
        p = temp;
    }
}

int main()
{
    initList();
    load("log.txt");
    int m;

    while (1)
    {

        printf("   ===============================");
        printf("\n   CHUONG TRINH TRUY VET COVID19");
        printf("\n   1. Nap du lieu log lich su di chuyen                   ");
        printf("\n   2. In ra lich su di chuyen                             ");
        printf("\n   3. Tim kiem lich su di chuyen theo dia diem            ");
        printf("\n   4. Tim kiem thong tin di chuyen theo thoi gian         ");
        printf("\n   5. Kiem tra truy vet moi nhat                          ");
        printf("\n   6. Thoat                                               ");
        printf("\n   ===============================");
        printf("\n\nBan muon chon so: ");
        scanf("%d", &m);
        getchar();
        switch (m)
        {
        case 1:
            printf("Doc thanh cong du lieu!");
            printf("\n");
            break;
        case 2:
            printList();
            printf("\n");
            break;
        case 3:
            cn3();
            printf("\n");
            break;
        case 4:
            cn4();
            printf("\n");
            break;
        case 5:
            cn5();
            printf("\n");
            break;
        case 6:
            freelist();
            printf("Chuong trinh ket thuc!");
            printf("\n");
            break;
        default:
            printf("Hay nhap lai!!!\n");
            break;
        }
    }
    return 0;
}
