#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define MAX_L 256
typedef struct 
{
    int nam;
    int thang;
    int ngay;
    int gio;
    int phut;
    int giay;
    char bienso[MAX_L];
    int a;
    struct Profile *next;
}Profile;
Profile* first, *last;
int d;
typedef struct Node{
    char bienso[MAX_L];
    int nam;
    int thang;
    int ngay;
    int gio;
    int phut;
    int giay;
    struct Node *leftChild;
    struct Node *rightChild;
}Node;
Node *root;
Node* makeNode(char* bienso, int nam,int thang,int ngay,int gio,int phut,int giay){
    Node* p = (Node*)malloc(sizeof(Node));
    strcpy(p->bienso,bienso); 
    p->nam = nam;
    p->thang = thang;
    p->ngay = ngay;
    p->gio = gio;
    p->phut = phut;
    p->giay = giay;
    p->leftChild = NULL; 
    p->rightChild = NULL;
    return p;
}
Node* find(Node* r, char* bienso){
    if(r == NULL) return NULL;
    int c = strcmp(r->bienso,bienso);
    if(c == 0) return r;
    if(c < 0) return find(r->rightChild,bienso);
    return find(r->leftChild,bienso);
}
Node* findMin(Node* r){
    if(r == NULL) return NULL;
    Node* lmin = findMin(r->leftChild);
    if(lmin != NULL) return lmin;
    return r;
}
Node* removeStudent(Node* r, char *bienso){
    if(r == NULL) return NULL;
    int c = strcmp(r->bienso,bienso);
    if(c > 0) r->leftChild = removeStudent(r->leftChild,bienso);
    else if(c < 0) r->rightChild = removeStudent(r->rightChild,bienso);
    else{
        if(r->leftChild != NULL && r->rightChild != NULL){
            Node* tmp = findMin(r->rightChild);
            strcpy(r->bienso,tmp->bienso); 
            r->nam = tmp->nam;
            r->thang = tmp->thang;
            r->ngay = tmp->ngay;
            r->gio = tmp->gio;
            r->phut = tmp->phut;
            r->giay = tmp->giay;
            r->rightChild = removeStudent(r->rightChild,tmp->bienso);
        }else{
            Node* tmp = r;
            if(r->leftChild == NULL) r = r->rightChild; 
            else r = r->leftChild;
            free(tmp);
        }
    }
    return r;}
Node* insert(Node* r, char* bienso,int nam,int thang,int ngay,int gio,int phut,int giay){
    if(r == NULL) return makeNode(bienso,nam,thang,ngay,gio,phut,giay);
    int c = strcmp(r->bienso,bienso);
    if(c == 0){
    r = removeStudent(r,bienso);
    return r;
    }else if(c < 0){
            r->rightChild = insert(r->rightChild,bienso,nam,thang,ngay,gio,phut,giay); return r;
          }else{
        r->leftChild = insert(r->leftChild,bienso,nam,thang,ngay,gio,phut,giay); return r;
    }
}
Profile* makeProfile(int nam,int thang,int ngay,int gio,int phut,int giay,char *bienso,int a){
    Profile* profile = (Profile*)malloc(sizeof(Profile));
    profile->nam = nam;
    profile->thang = thang;
    profile->ngay = ngay;
    profile->gio = gio;
    profile->phut = phut;
    profile->giay = giay;
    strcpy(profile->bienso,bienso);
    profile->a = a;
    profile->next=NULL;
    return profile; 
}
void initList(){
    first  =  NULL;
    last  = NULL;
}
int ListEmpty(){
    return  last == NULL && first == NULL;
}
void insertLast(int nam,int thang,int ngay,int gio,int phut,int giay,char *bienso,int a){
    Profile* profile = makeProfile(nam,thang,ngay,gio,phut,giay,bienso,a);
    if (ListEmpty()){
        last = profile;
        first = profile;
    }else{
        last->next = profile;
        last = profile;
    }
}
void load(){
    FILE *f = fopen("guixe.txt","r");
    while (!feof(f)){
        int nam;
        int thang;
        int ngay;
        int gio;
        int phut;
        int giay;
        char bienso[MAX_L];
        int a;
        fscanf(f,"%d-%d-%d%d:%d:%d%s%d",&nam,&thang,&ngay,&gio,&phut,&giay,bienso,&a);
        insertLast(nam,thang,ngay,gio,phut,giay,bienso,a);
        root = insert(root,bienso,nam,thang,ngay,gio,phut,giay);
    }
    fclose(f);
}
void cn2(){
    printf("Nhap ngay: ");
    int nam,thang,ngay;
    scanf("%d%d%d",&nam,&thang,&ngay);
    int d1=0,d2=0;
    for (Profile *p=first;p!=NULL;p=p->next){
        if (nam == p->nam && thang == p->thang && ngay == p->ngay){
            if (p->a == 1){
                d1++;
            }else {
                d2++;
            }
        }
    }
    printf("So luong xe gui la: %d\n",d1);
    printf("So luong xe lay ra la: %d\n",d2);
}
void freeTree(Node* r){
    if(r == NULL) return;
    freeTree(r->leftChild);
    freeTree(r->rightChild);
    free(r);
}
void sola(Node *r){
    if (r==NULL) return;
    d++;
    sola(r->leftChild);
    sola(r->rightChild);
}
void inOrder(Node* r){
    if(r == NULL) return;
    //d++;
    inOrder(r->leftChild);
    printf("%s  %d-%02d-%02d %02d:%02d:%02d\n",r->bienso,r->nam,r->thang,r->ngay,r->gio,r->phut,r->giay);
    inOrder(r->rightChild);
}
void cn3(){
    sola(root);
    printf("Tong so xe hien co: %d\n",d);
    printf("Bien so     Thoi gian gui\n");
    inOrder(root);
}
void cn4(){
    printf("Nhap bien so xe: ");
    char bienso[MAX_L];
    scanf("%s",bienso);
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    printf("Hien tai la: %d-%02d-%02d %02d:%02d:%02d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
    Node *p =find(root,bienso);
    if (p != NULL){
        printf("Xe da co trong bai\n");
    }else {
        root = insert(root,bienso,tm.tm_year+1900,tm.tm_mon+1,tm.tm_mday,tm.tm_hour,tm.tm_min,tm.tm_sec);
        printf("Gui xe thanh cong\n");
        insertLast(tm.tm_year+1900,tm.tm_mon+1,tm.tm_mday,tm.tm_hour,tm.tm_min,tm.tm_sec,bienso,1);
    }
}
void cn5(){
    printf("Nhap bien so xe: ");
    char bienso[MAX_L];
    scanf("%s",bienso);
    Node *p=find(root,bienso);
    if (p==NULL){
        printf("Xe khong o trong bai\n");
    }else {
        insertLast(p->nam,p->thang,p->ngay,p->gio,p->phut,p->giay,p->bienso,0);
        root = removeStudent(root,bienso);
    }
}
void cn6(){
    FILE *f = fopen("change_log.txt","w");
    for (Profile *p=first; p!= NULL;p=p->next){
        fprintf(f,"%d-%02d-%02d %02d:%02d:%02d %s %d\n",p->nam,p->thang,p->ngay,p->gio,p->phut,p->giay,p->bienso,p->a);
    }
    fclose(f);
}
void cn7(){
    inOrder(root);
}
void freelistt(){
    while (first != NULL)
    {
        Profile *tmp = first;
        first = first->next;
        free(tmp;)
    }
}
int main() {
    while(1){
        printf("1.  Doc du lieu tu file log\n");
        printf("2.  Tra cuu so luong xe gui/lay theo ngay trong qua khu\n");
        printf("3.  Thong tin cac xe trong bai hien tai\n");
        printf("4.  Gui them xe moi\n");
        printf("5.  Tra xe\n");
        printf("6.  Cap nhat log du lieu\n");
        printf("7.  Luu danh sach xe dang co trong bai ra file\n");
        int cn;
        printf("chon chuc nang: ");
        scanf("%d",&cn);
        if (cn==1){
            load();
        }else if (cn==2){
            cn2();
        }else if (cn==3){
            cn3();
        }else if (cn==4){
            cn4();
        }else if (cn==5){
            cn5();
        }else if (cn==6){
            cn6();
        }else if (cn==7){
            cn7();
        }
    }
    freelistt();
    freeTree(root);
    return 0;
}