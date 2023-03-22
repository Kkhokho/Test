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
void load(char* filename){
    FILE* f=fopen(filename,"r");
    if(f == NULL) printf("Load data -> file not found\n");
    while(!feof(f)){
        char mssv[11];
        char name[31];
        double mark;
        fscanf(f,"%s",mssv);
        fscanf(f,"%s",name);
        fscanf(f,"%lf",&mark);
        insertFirst(mssv,name,mark);
    }
    fclose(f);
}
void processLoad(){
    printf("Enter filename to read: ");
    char filename[15];
    scanf("%s",filename);
    load(filename);
}
void sort(){
    if (ListEmpty()) printf("List is not found\n");
    else{
        for (Profile *p=first;p!=NULL;p=p->next){
            for (Profile *q=p->next;q!=NULL;q=q->next){
                if (p->mark > q->mark){
                    double tmp = p->mark;
                    p->mark = q->mark;
                    q->mark = tmp;
                    char tmp1[11];
                    strcpy(tmp1,p->mssv);
                    strcpy(p->mssv,q->mssv);
                    strcpy(q->mssv,tmp1);
                    char tmp2[31];
                    strcpy(tmp2,p->name);
                    strcpy(p->name,q->name);
                    strcpy(q->name,tmp2);
                }
            }
        }
    }
}
void printList(){
    for (Profile* p=first;p != NULL; p=p->next){
        printf("Profile: %s, %s, %.2lf\n",p->mssv,p->name,p->mark);
    }
}
int main(){
    int n,t=1;
    processLoad();
    sort();
    while (t){
        printf("1. Nhap thong tin va theo thu tu tang dan\n");
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
            sort();
            printList();
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
        case 6:

        default: printf("Hay nhap lai\n");
            break;
        }
    }
    return 0;
}
