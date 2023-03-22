#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_L 256
typedef struct 
{
    int a;
    struct Profile *next;
}Profile;
typedef struct 
{
    int a;
}rs;
rs arr_m[10],arr_n[10];
int m,n;
Profile* first_n, *last_n, *first_m, *last_m;
void initList_n(){
    first_n  =  NULL;
    last_n  = NULL;
}
void initList_m(){
    first_m  =  NULL;
    last_m = NULL;
}
int ListEmpty_n(){
    return  last_n == NULL && first_n == NULL;
}
int ListEmpty_m(){
    return  last_m == NULL && first_m == NULL;
}
Profile* makeProfile(int a){
    Profile* profile = (Profile*)malloc(sizeof(Profile));
    profile->a = a;
    profile->next=NULL;
    return profile; 
}
void insertLast_n(){
    printf("Enter n: ");
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        scanf("%d",&arr_n[i].a);
        Profile* profile = makeProfile(arr_n[i].a);
    if (ListEmpty_n()){
        last_n = profile;
        first_n = profile;
    }else{
        last_n->next = profile;
        last_n = profile;
    }
    }
}
void insertLast_m(){
    printf("Enter m: ");
    scanf("%d",&m);
    for (int i=0;i<m;i++){
        scanf("%d",&arr_m[i].a);
        Profile* profile = makeProfile(arr_m[i].a);
    if (ListEmpty_m()){
        last_m = profile;
        first_m = profile;
    }else{
        last_m->next = profile;
        last_m = profile;
    }
    }
}
void connect(){
    last_m->next = first_n;
}
int main(){
    insertLast_m();
    insertLast_n();
    connect();
    for (Profile *p=first_m;p!=NULL;p=p->next){
        printf("%d ",p->a);
    }
    return 0;
}