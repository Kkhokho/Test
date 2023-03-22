#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_L 256
typedef struct 
{   char mssv[11];
    char name[31];
    double mark;
}sv;
sv arr[11];
typedef struct 
{   char mssv[11];
    char name[31];
    double mark;
    struct Profile *next;
}Profile;
Profile* first, *last;
int n;
void initList(){
    first  =  NULL;
    last  = NULL;
}
int ListEmpty(){
    return  last == NULL && first == NULL;
}
Profile* makeProfile(char* mssv,char *name,double mark){
    Profile* profile = (Profile*)malloc(sizeof(Profile));
    strcpy(profile->mssv,mssv);
    strcpy(profile->name,name);
    profile->mark = mark;
    profile->next=NULL;
    return profile; 
}
void insertLast(){
    printf("Enter n: ");
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        scanf("%s%s%lf",arr[i].mssv,arr[i].name,&arr[i].mark);
        Profile* profile = makeProfile(arr[i].mssv,arr[i].name,arr[i].mark);
    if (ListEmpty()){
        last = profile;
        first = profile;
    }else{
        last->next = profile;
        last = profile;
    }
    }
    for (Profile*p=first;p!=NULL;p=p->next){
        printf("%s, %s, %.2lf\n",p->mssv,p->name,p->mark);
    }
}
int main(){
    initList();
    insertLast();
    return 0;
}