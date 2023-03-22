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

Profile *first, *last,*last1;

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
    return (first == NULL);
}
int listEmpty1()
{
    return (last == NULL);
}

void insertLast(char *place, int gio, int phut)
{
    Profile *profile = makenode(place, gio, phut);
    if (listEmpty())
    {
        first = profile;
    }
    else
    {
        profile->next=first;
        first = profile;
    }
}
void insertLast1(char *place, int gio, int phut)
{
    Profile *profile = makenode(place, gio, phut);
    if (listEmpty1())
    {
        last = profile;
    }
    else
    {
        profile->next=last;
        last = profile;
    }
}
void chuyendoi(){
    for (Profile *p=first;p!=NULL;p=p->next){
        insertLast1(p->place,p->gio,p->phut);
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
}

void printList()
{  
    printf("%-50s%-10s%-10s\n", "Dia diem", "Gio", "Phut");
    for (Profile *p = last; p != NULL; p = p->next)
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
        printf("Ban chua toi dia diem do \n");
}

void cn4()
{
    int g, ph;
    do
    {   
        printf("Nhap vao thoi gian: ");
        scanf("%d%d", &g, &ph);
    } while (g < 0 || g >= 24 || ph < 0 || ph >= 60);
    int x = 0;
    for (Profile *p = last; p != NULL; p = p->next)
    {
        if (p->next == NULL)
            last1 = p;
    }
    Profile *gancuoi = NULL;
    for (Profile *p = first; p != NULL; p = p->next)
    {
        if (p->next == last1)
            gancuoi = p;
    }

    if (last1->gio == g && ph < last1->phut)
        {x = 1; 
        printf("%s", gancuoi->place);}
    else if (last1->gio == g && ph > last1->phut)
        {x = 1; 
        printf("%s", last1->place);}
    else if (last1->gio < g)
        {x = 1; 
        printf("%s", last1->place);}
    else
    {
        for (Profile *p = last; p != NULL; p = p->next)
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
   
    int m;
    int t=1;
    while (t)
    {
        char filename[MAX];
        printf("   ===============================");
        printf("\n   CHUONG TRINH TRUY VET COVID19");
        printf("\n   1. Nap du lieu log lich su di chuyen                   ");
        printf("\n   2. In ra lich su di chuyen                             ");
        printf("\n   3. Tim kiem lich su di chuyen theo dia diem            ");
        printf("\n   4. Tim kiem thong tin di chuyen theo thoi gian         ");
        printf("\n   5. Thoat                                               ");
        printf("\n   ===============================");
        printf("\n\nBan muon chon so: ");
        scanf("%d", &m);
        getchar();
        switch (m)
        {
        case 1:
            printf("Nhap file du lieu de doc: ");
            scanf("%s",filename);
            load(filename);
            printf("Doc file du lieu thanh cong!!!");
            printf("\n");
            chuyendoi();
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
            freelist();
            printf("Chuong trinh ket thuc!");
            printf("\n");
            t=0;
            break;
        default:
            printf("Hay nhap lai!!!\n");
            break;
        }
    }
    return 0;
}
