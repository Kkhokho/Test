#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_L 81
typedef struct{
    char id[10];
    char name[250];
    char source[100];
    char d[2];
    int sl;
}rs;
int i=0;
rs arr[100];
typedef struct{
    char id[10];
    char name[250];
    char source[100];
    int sl;
    struct Profile *next; 
}Profile;
Profile *first,*last;
//Tao ra 1 Node moi
Profile* makeProfile(char* id,char *name,char *source,int sl){
    Profile* profile = (Profile*)malloc(sizeof(Profile));
    strcpy(profile->id,id);
    strcpy(profile->name,name);
    strcpy(profile->source,source);
    profile->sl=sl;
    profile->next=NULL;
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
//Them 1 node vao dau danh sach
void insertFirst(char *id, char *name,char *source, int sl){
    Profile* p = makeProfile(id,name,source,sl);
    if (ListEmpty()){
        last = p;
        first = p;
    }else{
        p->next = first;
        first = p;
    }
}
void xoaxuongdong(char x[])
{
    x[strlen(x)-1]='\0';
}
//Doc du lieu tu file vao danh sach lien ket
void load(char* filename){
    FILE* f=fopen(filename,"r");
    if(f == NULL) printf("Load data -> file not found\n");
    while(!feof(f)){
        fgets(arr[i].id,MAX_L,f);
        xoaxuongdong(arr[i].id);
        fgets(arr[i].name,MAX_L,f);
        xoaxuongdong(arr[i].name);
        fgets(arr[i].source,MAX_L,f);
        xoaxuongdong(arr[i].source);
        fgets(arr[i].d,MAX_L,f);
        //xoaxuongdong(arr[i].d);
        arr[i].sl = atoi(arr[i].d);
        insertFirst(arr[i].id,arr[i].name,arr[i].source,arr[i].sl);
        i++;
    }
    fclose(f);
}
void processLoad(){
    printf("Enter filename to read: ");
    char filename[20];
    scanf("%s",filename);
    load(filename);
}
//In ra danh sach lien ket
void printList(){
    int k=0;
    printf("%-5s|%-10s|%-30s|%-20s|%-20s\n","STT","ID","Ten san pham","Hang san xuat","So luong trong kho");
    for (Profile* p=first;p != NULL; p=p->next){
        k++;
        printf("%-5d|%-10s|%-30s|%-20s|%-20d\n",k,p->id,p->name,p->source,p->sl);
    }
}
//Chuc nang 1
void ProcessInsert(){
    printf("Enter id, name, source, sl: ");
    char id[10];
    char name[250];
    char source[100];
    int  sl;
    fflush(stdin);
    fgets(id,10,stdin);
    xoaxuongdong(id);
    fflush(stdin);
    fgets(name,250,stdin);
    xoaxuongdong(name);
    fflush(stdin);
    fgets(source,100,stdin);
    xoaxuongdong(source);
    scanf("%d",&sl);
    for (Profile* p=first;p != NULL; p=p->next){
        if (strcmp(p->id,id)==0) {
            p->sl = p->sl + sl;
            return;
        }
    }
    insertFirst(id,name,source,sl);
}
//Xoa 1 node trong danh sach
Profile* removeProfile(Profile* f, char* id){
if(ListEmpty()) return NULL;
if(strcmp(f->id,id) == 0){
    Profile* tmp = f->next;
    free(f);
    if(tmp == NULL) last = NULL;
    return tmp;
    }else{
        f->next = removeProfile(f->next,id);
        return f;}
}
void processRemove(char *id){
    first = removeProfile(first,id);
}
//Chuc nang 2
void xuatkho(){
    printf("Nhap id cua mat hang xuat kho: ");
    char id[10];
    fflush(stdin);
    fgets(id,10,stdin);
    xoaxuongdong(id);
    printf("Nhap so luong can xuat: ");
    int sl;
    scanf("%d",&sl);
    int t=0;
    for (Profile *p=first;p!=NULL;p=p->next){
        if (strcmp(p->id,id)==0){
            t=1;
            if (sl < p->sl){
                p->sl = p->sl - sl;
            }else{
                if (sl>p->sl) printf("Khong du so luong de xuat kho\n");
                else processRemove(id);
            }
        }
    }
    if (t==0) printf("Khong tim thay sam pham\n");
}
//Chuc nang 3
void ktra(){
    printf("Nhap id de ktra: ");
    char id[10];
    fflush(stdin);
    fgets(id,10,stdin);
    xoaxuongdong(id);
    int t=0;
    for (Profile *p=first;p!=NULL;p=p->next){
        if (strcmp(p->id,id)==0){
            t=1;
            printf("So luong con trong kho: %d\n",p->sl);
        }
    }
    if (t==0) printf("Mat hang khong con trong kho\n");
}
//Chuc nang 4
void processStore(){
    char filename[256];
    printf("Enter filename to store: ");
    scanf("%s",filename);
    FILE* f = fopen(filename,"w");
    for(Profile* p = first; p != NULL; p = p->next){
    fprintf(f,"%s\n%s\n%s\n%d",p->id,p->name,p->source,p->sl);
    if(p->next != NULL) fprintf(f,"\n");
    }
    fclose(f);}
void sapxep(){
    for (Profile *p=first;p!=NULL;p=p->next){
        for (Profile *p1=p->next;p1!=NULL;p1=p1->next){
            if (strcmp(p->name,p1->name)>0){
                char id[256];
                char name[256];
                char source[256];
                int sl;
                strcpy(id,p->id);
                strcpy(p->id,p1->id);
                strcpy(p1->id,id);
                strcpy(name,p->name);
                strcpy(p->name,p1->name);
                strcpy(p1->name,name);
                strcpy(source,p->source);
                strcpy(p->source,p1->source);
                strcpy(p1->source,source);
                sl = p->sl;
                p->sl = p1->sl;
                p->sl = sl;
            }
        }
    }
}
int main(){
    initList();
    processLoad();
    sapxep();
    printList();
    int t=1;
    while (t)
    {
        printf("1.  Bo sung san pham\n");
        printf("2.  Xuat kho\n");
        printf("3.  Ktra\n");
        printf("4.  In\n");
        printf("5.  Ghi ra 1 file\n");
        printf("6.  Thoat\n");
        printf("Chon chuc nang: ");
        int cn;
        scanf("%d",&cn);
        switch (cn)
        {
        case 1:
            ProcessInsert();
            printList();
            break;
        case 2:
            xuatkho();
            printList();
            break;
        case 3:
            ktra();
            break;
        case 4:
            printList();
            break;
        case 5:
            processStore();
            break;
        case 6:
            t=0;
            break;
        default: printf("Hay nhap lai chuc nang!!!!");
            break;
        }
    }
    return 0;
}