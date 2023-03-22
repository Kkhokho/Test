#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct 
{
    char cpu[4];
    int ram;
    int id;
    struct Profile *next;
}Profile;
Profile *first,*last;
int n;
//Tao ra 1 Node moi
Profile* makeProfile(char *cpu, int ram){
    Profile* profile = (Profile*)malloc(sizeof(Profile));
    strcpy(profile->cpu,cpu);
    profile->ram = ram;
    profile->next = NULL;
    return profile; 
}
//Reset danh sach lien ket
void initList(){
    first  =  NULL;
    last  = NULL;
}
//Kiem tra danh sach co rong khong
int ListEmpty(){
    return  last == NULL && first == NULL;
}
void printList(){
        printf("_____________\n");
    for (Profile *p=first;p!=NULL;p=p->next){
        printf("   %s %d   \n",p->cpu,p->ram);
    }
        printf("_____________\n");
}
void insertfirst(char *cpu,int ram){
    Profile *p = makeProfile(cpu,ram);
    if (ListEmpty()){
        last = p;
        first = p;
    }else{
        last->next = p;
        last = p;
    }
}
void Load(char *filename){
    FILE *f = fopen(filename,"r");
    int s;
    int b=0;
    if (f==NULL){
        printf("File khong ton tai\n");
    }else{
        fscanf(f,"%d",&s);
        while (!feof(f))
        {
            char cpu[4];
            int ram;
            if (n<20){
                fscanf(f,"%s",cpu);
                fscanf(f,"%d",&ram);
                insertfirst(cpu,ram);
                n++;
                b++;
            }else{
                printf("Danh sach da day, khong them duoc\n");
                break;
            }
            
        }
        printf("So may da them la: %d\n",b);
    }
    fclose(f);
}
void processLoad(){
    char filename[256];
    printf("Nhap ten file de doc du lieu: ");
    scanf("%s",filename);
    Load(filename);
}
void cn2(){
    int id;
    do{
        printf("Nhap ID cua may muon nhap: \n");
        scanf("%d",&id);
        if (id >n || id <1){
            printf("Hay nhap lai ID\n");
        }else{
            break;
        }
    }while(1);
    int i=1;
    Profile *p1;
    for (Profile *p=first;p!=NULL;p=p->next){
        p->id = i;
        i++;
        if (p->id == id){
            p1 = p;
        }
    }
    printf("Nhap ten muon sua cho may co ID %d: ",p1->id);
    char cpu[4];
    scanf("%s",cpu);
    strcpy(p1->cpu,cpu);
    for (Profile *p=p1->next;p!=NULL;p=p->next){
        printf("Nhap ten muon sua cho may tiep theo: ");
        char cpu1[4];
        scanf("%s",cpu1);
        if (strcmp(cpu1,"STOP")==0){
            break;
        }else{
            strcpy(p->cpu,cpu1);
        }
    }
}
void cn3(){
    int id;
    do{
        printf("Nhap ID cua may muon nhap: \n");
        scanf("%d",&id);
        if (id >n || id <1){
            printf("Hay nhap lai ID\n");
        }else{
            break;
        }
    }while(1);
    int i=1;
    Profile *p1;
    for (Profile *p=first;p!=NULL;p=p->next){
        p->id = i;
        i++;
        if (p->id == id){
            p1 = p;
        }
    }
    int RAM;
    do{
        printf("Nhap RAM muon sua cho may co ID %d: ",p1->id);
        scanf("%d",&RAM);
        if (RAM != 1 && RAM != 2 && RAM != 4 && RAM != 8 && RAM != 16 && RAM != 32){
            printf("Hay nhap lai RAM\n");
        }else{
            break;
        }
    }while(1);
    p1->ram = RAM;
    for (Profile *p=p1->next;p!=NULL;p=p->next){
        printf("Nhap RAM muon sua cho may tiep theo: ");
        char RAM1[4];
        scanf("%s",&RAM1);
        if (strcmp(RAM1,"STOP")==0){
            break;
        }else{
            p->ram = atoi(RAM1);
        }
    }
}
void find_print_cpu(char *t){
    for (Profile *p=first;p!= NULL;p=p->next){
        if (strcmp(t,p->cpu)==0){
            printf("%s %d\n", p->cpu,p->ram);
        }
    }
}
void find_print_ram(int r){
    for (Profile *p=first;p!= NULL;p=p->next){
        if (p->ram==r){
            printf("%s %d\n", p->cpu,p->ram);
        }
    }
}
void cn4(){
    char t[4];
    printf("Hay nhap: ");
    scanf("%s",t);
    if (strcmp(t,"I3")==0) find_print_cpu(t);
    else{
        if (strcmp(t,"I5")==0) find_print_cpu(t);
        else {
            if (strcmp(t,"I7")==0) find_print_cpu(t);
            else {
                int t1;
                t1 = atoi(t);
                if (t1==1) find_print_ram(1);
                else {
                    if (t1==2) find_print_ram(2);
                    else {
                        if (t1==4) find_print_ram(4);
                        else {
                            if (t1==8) find_print_ram(8);
                            else {
                                if (t1==16) find_print_ram(16);
                                else {
                                    if (t1==32) find_print_ram(32);
                                    else printf("Gia tri tim kiem khong hop le\n");
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
int main(){
    int t=1;
    while (t){
        printf("\n====Program for management computers====\n");
        printf("1)  Load Data Files:\n");
        printf("2)  Update CPU info:\n");
        printf("3)  Update RAM info:\n");
        printf("4)  Search:\n");
        printf("5)  Quit\n");
        int cn;
        printf("Nhap chuc nang: ");
        scanf("%d",&cn);
        switch (cn)
        {
        case 1:
            processLoad();
            break;
        case 2:
            cn2();
            printList();
            break;
        case 3:
            cn3();
            printList();
            break;
        case 4:
            cn4();
            break;
        case 5:
            t=0;
            break;
        default:
            printf("Hay nhap lai\n");
            break;
        }
    }
    return 0;
}