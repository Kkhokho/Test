#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_L 256
typedef struct{
    int id;
    char name[30];
    int mark;
    int win;
    int lose;
    struct Profile *next;
}Profile;
int v=1;
int n,m;
char filename[MAX_L];
Profile* first, *last;
typedef struct {
    int a[20][2];
}vong;
vong arr[100];
//Thêm hồ sơ
Profile* makeProfile(int id,char *name){
    Profile* profile = (Profile*)malloc(sizeof(Profile));
    profile->id = id;
    strcpy(profile->name,name);
    profile->mark = 0;
    profile->win=0;
    profile->lose=0;
    profile->next = NULL;
    return profile; 
}
void initList(){
    first  =  NULL;
    last  = NULL;
}
int ListEmpty(){
    return  last == NULL && first == NULL;
}
void printList(){
    printf("%-5s%-20s%-15s%-15s%-15s\n","ID","Ten doi bong","Diem","So ban thang","So ban thua");
    for (Profile *p=first;p != NULL; p=p->next){
        printf("%-5d%-20s%-15d%-15d%-15d\n",p->id,p->name,p->mark,p->win,p->lose);
    }
}
void insertLast(int id,char *name){
    Profile* profile = makeProfile(id,name);
    if (ListEmpty()){
        last = profile;
        first = profile;
    }else{
        last->next = profile;
        last = profile;
    }
}
void Load(){
    printf("Nhap file de doc: ");
    scanf("%s",filename);
    FILE *f = fopen(filename,"r");
    while (!feof(f)){
        fscanf(f,"%d",&n);
        m=n;
        for (int i=1;i<=n;i++){
            int id;
            char name[MAX_L];
            fscanf(f,"%d",&id);
            fgets(name,MAX_L,f);
            name[strlen(name)-1]='\0';
            insertLast(id,name);
        }
        break;
    }
    fclose(f);
    printList();
}
void cn2(){
    FILE *f = fopen(filename,"r");
    while (!feof(f)){
        fscanf(f,"%d",&n);
        for (int i=1;i<=n;i++){
            int id;
            char name[MAX_L];
            fscanf(f,"%d",&id);
            fgets(name,MAX_L,f);
            name[strlen(name)-1]='\0';
            //insertLast(id,name);
        }
        for (int i=1;i<=n-1;i++){
            char s[MAX_L];
            fgets(s,MAX_L,f);
            s[strlen(s)-1]='\0';
            printf("%s\n",s);
            for (int j=1;j<=n/2;j++){
                char s3[MAX_L];
                fgets(s3,MAX_L,f);
                if (j==n/2){
                    s3[strlen(s3) - 1] = s3[strlen(s3) - 1] == '\n' ? '\0' : s3[strlen(s3) - 1];
                }else {
                    s3[strlen(s3)-1]='\0';
                }
                char *p;
                p = strtok(s3," ");
                int id1,id2;
                id1 = atoi(p);
                p = strtok(NULL," ");
                id2 = atoi(p);
                arr[i].a[j][0] = id1;
                arr[i].a[j][1] = id2;
                for (Profile *p1=first;p1 != NULL;p1=p1->next){
                    if (p1->id ==id1) printf("%s -",p1->name);
                }
                for (Profile *p2=first;p2 != NULL;p2=p2->next){
                    if (p2->id ==id2) printf("%s\n",p2->name);
                }
            }
        }
    }
    fclose(f);
    //printList();
}
int printStruct(){
    for (int i=1;i<=n-1;i++){
        printf("Vong %d\n", i);
        for (int j=1;j<=n/2;j++){
            printf("%d - %d\n",arr[i].a[j][0],arr[i].a[j][1]);
        }
    }
}
void cn3(){
    if (v>3) return ;
    printf("Cap nhat ket qua vong %d: \n",v);
    printf("Vong %d\n",v);
    Profile *p1;
    Profile *p2;
    for (int i=1;i<=m/2;i++){
        for (Profile *p=first;p!= NULL;p=p->next){
        if (p->id == arr[v].a[i][0]) p1=p;
        if (p->id == arr[v].a[i][1]) p2=p;
        }
        int a,b;
        printf("%s - %s: ",p1->name,p2->name);
        scanf("%d-%d",&a,&b);
        p1->win +=a;
        p2->win +=b;
        p1->lose +=b;
        p2->lose +=a;
        if (a>b){ p1->mark+=3;
        }else{
            if (a<b){
                p2->mark +=3;
            }else{
                p1->mark +=1;
                p2->mark +=1;
            }
        }
    }
    v++;
    printList();
}
Profile* removeProfile(Profile *f, int id){
    if(ListEmpty()) return NULL;
    if(f->id == id){
    Profile* tmp = f->next;
    free(f);
    if(tmp == NULL) last = NULL;
    return tmp;
    }else{
    f->next = removeProfile(f->next,id);
    return f;
    }
}
void cn4(){
    int min = first->mark;
    printf("%-5s%-20s%-15s%-15s%-15s\n","ID","Ten doi bong","Diem","So ban thang","So ban thua");
    for (Profile *p=first;p!= NULL;p=p->next){
        if (min > p->mark){
            min = p->mark;
        }
    }
    printf("Cac doi co diem thap nhat la: \n");
    for (Profile *p=first;p!= NULL;p=p->next){
        if (p->mark == min){
            printf("%-5d%-20s%-15d%-15d%-15d\n",p->id,p->name,p->mark,p->win,p->lose);
            first = removeProfile(first,p->id);
        }
    }
    printf("Cac doi con lai la: \n");
    printList();
}
int main(){
    int t=1;
    while(t){
        int cn;
        printf("=========================\n");
        printf("1.  In thong tin cac doi bong\n");
        printf("2.  In thong tin lich thi dau\n");
        printf("3.  Cap nhat ket qua vong dau\n");
        printf("4.  Thong ke\n");
        printf("5.  Thoat\n");
        printf("=========================\n");
        printf("Nhap chuc nang: ");
        scanf("%d",&cn);
        switch (cn)
        {
        case 1:
            Load();
            break;
        case 2:
            cn2();
            //printStruct();
            break;
        case 3:
            cn3();
            break;
        case 4:
            cn4();
            break;
        case 5:
            t=0;
            break;
        default:
            printf("Hay nhap lai!!!\n");
            break;
        }
    }
}