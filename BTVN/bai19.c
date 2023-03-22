#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_L 256
typedef struct 
{   char mssv[11];
    char name[31];
    double mark;
    struct Profile *next;
}Profile;
Profile* first, *last;
Profile* makeProfile(char* mssv,char *name,double mark){
    Profile* profile = (Profile*)malloc(sizeof(Profile));
    strcpy(profile->mssv,mssv);
    strcpy(profile->name,name);
    profile->mark = mark;
    profile->next=NULL;
    return profile; 
}
void insertFirst(char *mssv, char *name,double mark){
    Profile* p = makeProfile(mssv,name,mark);
    if (ListEmpty()){
        last = p;
        first = p;
    }else{
        p->next = first;
        first = p;
    }
}
void processInsertFirst(){
    char mssv[11];
    char name[31];
    double mark;
    printf("Enter Mssv,Name,Mark to insert: ");
    scanf("%s",mssv);
    scanf("%s",name);
    scanf("%lf",&mark);
    insertFirst(mssv,name,mark);
}
void initList(){
    first  =  NULL;
    last  = NULL;
}
int ListEmpty(){
    return  last == NULL && first == NULL;
}
Profile* removeProfile(Profile* f, char* mssv){
if(ListEmpty()) return NULL;
if(strcmp(f->mssv,mssv) == 0){
Profile* tmp = f->next;
free(f);
if(tmp == NULL) last = NULL;
return tmp;
}else{
f->next = removeProfile(f->next,mssv);
return f;
}
}
void processRemove(){
char mssv[11];
printf("Enter mssv to remove: ");
scanf("%s",mssv);
first = removeProfile(first,mssv);
}
void processFind(){
    printf("Enter mssv to search: ");
    char mssv[11];
    scanf("%s",mssv);
    Profile* profile = NULL;
    for (Profile* p=first;p != NULL; p = p->next){
        if (strcmp(p->mssv,mssv)==0) {profile = p;break;}
    }
    if (profile==NULL) printf("NOT FOUND profile %s\n",mssv);
    else printf("FOUND profile %s, %s\n",profile->mssv,profile->name,profile->mark);
}
void printList(){
    for (Profile* p=first;p != NULL; p=p->next){
        printf("Profile: %s, %s, %.2lf\n",p->mssv,p->name,p->mark);
    }
}
int main(){
    int n,t=1;
    while (t){
        printf("1. Nhap thong tin va chen vao dau\n");
        printf("2. Tim kiem theo Mssv\n");
        printf("3. Xoa theo Mvvs\n");
        printf("4. Hien thi thong tin\n");
        printf("5. Thoat\n");
        int cn;
        printf("Ban chon chuc nang nao: ");
        scanf("%d",&cn);
        switch (cn)
        {
        case 1:
            processInsertFirst();
            break;
        case 2:
            processFind();
            break;
        case 3:
            processRemove();
            break;
        case 4:
            printList();
            break;
        case 5:
            t=0;
            break;
        default: printf("Hay nhap lai\n");
            break;
        }
    }
    return 0;
}
