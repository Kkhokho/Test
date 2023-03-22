#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define MAX_L 256
typedef struct Profile{
    char name[MAX_L];
    int a;
    int b;
    char s[MAX_L];
    int ngay;
    int thang;
    int nam;
    int d;
    struct Proflile *next;
}Profile;
int dem=0;
int max = 1;
Profile *first,*last;
typedef struct Node{
    char name[MAX_L];
    int a;
    int b;
    char s[MAX_L];
    int ngay;
    int thang;
    int nam;
    int d;
    int dem;
    struct Node *leftChild;
    struct Node *rightChild;
}Node;
Node *root;
Node* makeNode(char* name, int a,int b,char *s,int ngay,int thang,int nam,int d){
    Node* p = (Node*)malloc(sizeof(Node));
    strcpy(p->name,name); 
    p->a = a;
    p->b = b;
    strcpy(p->s,s);
    p->ngay = ngay;
    p->thang = thang;
    p->nam = nam;
    p->d = d;
    p->leftChild = NULL; 
    p->rightChild = NULL;
    return p;
}
Node* insert(Node* r, char* name, int a,int b,char *s,int ngay,int thang,int nam,int d){
    if(r == NULL) return makeNode(name,a,b,s,ngay,thang,nam,d);
    int c = strcmp(r->name,name);
    if(c == 0){
    printf("Student %s exists, do not insert\n",name); return r;
    }else if(c < 0){
            r->rightChild = insert(r->rightChild,name,a,b,s,ngay,thang,nam,d); return r;
          }else{
        r->leftChild = insert(r->leftChild,name,a,b,s,ngay,thang,nam,d); return r;
    }
}
Node* find(Node* r, char* name){
    if(r == NULL) return NULL;
    int c = strcmp(r->name,name);
    if(c == 0) return r;
    if(c < 0) return find(r->rightChild,name);
    return find(r->leftChild,name);
}

Node* findMin(Node* r){
    if(r == NULL) return NULL;
    Node* lmin = findMin(r->leftChild);
    if(lmin != NULL) return lmin;
    return r;
}
Node* removeStudent(Node* r, char* name){
    if(r == NULL) return NULL;
    int c = strcmp(r->name,name);
    if(c > 0) r->leftChild = removeStudent(r->leftChild,name);
    else if(c < 0) r->rightChild = removeStudent(r->rightChild,name);
    else{
        if(r->leftChild != NULL && r->rightChild != NULL){
            Node* tmp = findMin(r->rightChild);
            strcpy(r->name,tmp->name); 
            r->a = tmp->a;
            r->b = tmp->b;
            strcpy(r->s,tmp->s);
            r->ngay = tmp->ngay;
            r->thang = tmp->thang;
            r->nam = tmp->nam;
            r->d = tmp->d;
            r->rightChild = removeStudent(r->rightChild,tmp->name);
        }else{
            Node* tmp = r;
            if(r->leftChild == NULL) r = r->rightChild; 
            else r = r->leftChild;
            free(tmp);
        }
    }
    return r;}
void freeTree(Node* r){
    if(r == NULL) return;
    freeTree(r->leftChild);
    freeTree(r->rightChild);
    free(r);
}
int n;
Profile* makeProfile(char* name, int a,int b,char *s,int ngay,int thang,int nam,int d){
    Profile* p = (Profile*)malloc(sizeof(Profile));
    strcpy(p->name,name); 
    p->a = a;
    p->b = b;
    strcpy(p->s,s);
    p->ngay = ngay;
    p->thang = thang;
    p->nam = nam;
    p->d = d;
    p->next=NULL;
    return p; 
}
void initList(){
    first  =  NULL;
    last  = NULL;
}
int ListEmpty(){
    return  last == NULL && first == NULL;
}
void printList(){
    for (Profile* r=first;r != NULL; r=r->next){
        printf("%s %d %d %s %02d-%02d-%d %d\n",r->name,r->a,r->b,r->s,r->ngay,r->thang,r->nam,r->d);
    }
}
void insertLast(char* name, int a,int b,char *s,int ngay,int thang,int nam,int d){
    Profile* profile = makeProfile(name,a,b,s,ngay,thang,nam,d);
    if (ListEmpty()){
        last = profile;
        first = profile;
    }else{
        last->next = profile;
        last = profile;
    }
}
void insertFirst(char* name, int a,int b,char *s,int ngay,int thang,int nam,int d){
    Profile* p = makeProfile(name,a,b,s,ngay,thang,nam,d);
    if (ListEmpty()){
        last = p;
        first = p;
    }else{
        p->next = first;
        first = p;
    }
}
void freeList(Profile* p){
    while (( p!= NULL))
    {
        Profile *tmp = p;
        p = p->next;
        free(tmp);
    }
}
void load(){
    FILE *f=fopen("booking_orders.txt","r");
    fscanf(f,"%d",&n);
    while (!feof(f))
    {   
        char name[MAX_L];
        int a;
        int b;
        char s[MAX_L];
        int ngay;
        int thang;
        int nam;
        int d;
        fscanf(f,"%s%d%d%s%d-%d-%d%d",name,&a,&b,s,&ngay,&thang,&nam,&d);
        insertLast(name,a,b,s,ngay,thang,nam,d);
        root = insert(root,name,a,b,s,ngay,thang,nam,d);
    }
    fclose(f);
}
void cn2(){
    int d=0;
    for (Profile *p=first;p!=NULL;p=p->next){
        if (p->d != 0){
            if ((p->a - p->d) <=0){
                d++;
            }
        }
    }
    printf("So luong yeu cau khong hop le la: %d\n",d);
}
void cn3(){
    printf("Nhap ma tim kiem: ");
    char name[MAX_L];
    scanf("%s",name);
    Node *r = find(root,name);
    if (r==NULL){
        printf("not found\n");
    }else {
        printf("%s %d %d %s %02d-%02d-%d %d\n",r->name,r->a,r->b,r->s,r->ngay,r->thang,r->nam,r->d);
    }
}
void cn4(){
    printf("Nhap ma can cap nhat: ");
    char name[MAX_L];
    scanf("%s",name);
    Node *r = find(root,name);
    if (r==NULL){
        printf("Not found\n");
    }else{
        printf("Nhap ngay thang nam: ");
        int ngay;
        int thang;
        int nam;
        scanf("%d",&ngay);
        scanf("%d",&thang);
        scanf("%d",&nam);
        printf("Nhap so luong nguoi: ");
        int a;
        scanf("%d",&a);
        printf("Nhap so luong tre em: ");
        int d;
        scanf("%d",&d);
        if (d == 0){
            r->a = a;
            r->d = d;
            r->ngay = ngay;
            r->thang = thang;
            r->nam = nam;
            printf("Update\n");
        }else {
            if ((a-d)>0){
                r->a = a;
                r->d = d;
                r->ngay = ngay;
                r->thang = thang;
                r->nam = nam;
                printf("Update\n");
            }else {
                printf("Invalid\n");
            }
        }
    }
}
void cn5(){
    printf("Nhap ma huy yeu cau: ");
    char name[MAX_L];
    scanf("%s",name);
    Node *r = find(root,name);
    if (r== NULL){
        printf("Not found\n");
    }else {
        n--;
        root = removeStudent(root,name);
        printf("Delete\n");
    }
}
void inOrder(Node* r){
    if(r == NULL) return;
    inOrder(r->leftChild);
    printf("%s %d %d %s %02d-%02d-%d %d\n",r->name,r->a,r->b,r->s,r->ngay,r->thang,r->nam,r->d);
    inOrder(r->rightChild);
}
void inOrderF(Node* r, FILE* f){
    if(r == NULL) return;
    inOrderF(r->leftChild,f);
    dem++;
    fprintf(f,"%s %d %d %s %02d-%02d-%d %d\n",r->name,r->a,r->b,r->s,r->ngay,r->thang,r->nam,r->d);
    inOrderF(r->rightChild,f);
}
void cn6(Node *r){
    FILE *f = fopen("booking_output.txt","w");
    //fscanf(f,"%d\n",n);
    inOrderF(root,f);
    printf("So luong ma yeu cau da doc: %d\n",dem);
    fclose(f);
}

void op2(){
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    //printf("Hien tai la: %d-%02d-%02d %02d:%02d:%02d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
    printf("Cac ma khong hop le ve thoi gian la: \n");
    for (Profile *r=first;r!= NULL;r=r->next){
        if (r->nam < tm.tm_year){
            printf("")
        }else {
            //printf("%s\n",r->name);
        }
    }
}
int main(){
    while(1){
        printf("1.  Doc du lieu tu file log\n");
        printf("2.  Kiem tra so luong yeu cau khong hop le\n");
        printf("3.  Tra cuu theo ma yeu cau\n");
        printf("4.  Thay doi yeu cau\n");
        printf("5.  Huy yeu cau\n");
        printf("6.  Luu danh sach yeu cau ra file\n");
        printf("7.  Option 1\n");
        printf("8.  Option 2\n");
        printf("9.  Option 3\n");
        int cn;
        printf("chon chuc nang: ");
        scanf("%d",&cn);
        if (cn==1){
            load();
            printf("%d\n",n);
            //printList();
            //printf("So yeu cau duoc doc la: %d\n",n);
        }else if (cn==2){
            cn2();
        }else if (cn==3){
            cn3();
        }else if (cn==4){
            cn4();
        }else if (cn==5){
            cn5();
        }else if (cn==6){
            cn6(root);
        }
        else if (cn == 8){
            op2();
        }
    }
    freeList(first);
    freeTree(root);
    //freeTree1(goc);
    return 0;
}