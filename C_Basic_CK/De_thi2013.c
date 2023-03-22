#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_L 256
typedef struct Node{
    char name[MAX_L];
    int diem;
    struct Node *leftChild;
    struct Node *rightChild;
}Node;
int dem = 0;
Node *root;
typedef struct 
{
    char s[MAX_L];
}rs;
rs arr[100];
int i = 0;
Node* makeNode(char* name){
    Node* p = (Node*)malloc(sizeof(Node));
    strcpy(p->name,name); 
    p->diem = 0;
    p->leftChild = NULL; 
    p->rightChild = NULL;
    return p;
}
Node* insert(Node* r, char* name){
    if(r == NULL) return makeNode(name);
    int c = strcmp(r->name,name);
    if(c == 0){
    printf("Student %s exists, do not insert\n",name); return r;
    }else if(c < 0){
            r->rightChild = insert(r->rightChild,name); return r;
          }else{
        r->leftChild = insert(r->leftChild,name); return r;
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
        r->diem = tmp->diem;
        r->rightChild = removeStudent(r->rightChild,tmp->name);
        }else{
        Node* tmp = r;
        if(r->leftChild == NULL) r = r->rightChild; else r = r->leftChild;
        free(tmp);
        }
    }
    return r;}
void load(){
    FILE *f = fopen("bongda.txt","r");
    while (!feof(f))
    {
        char id1[MAX_L];
        char id2[MAX_L];
        int diem1,diem2;
        fscanf(f,"%s%s%d%d",id1,id2,&diem1,&diem2);
        Node *p1 = find(root,id1);
        Node *p2 = find(root,id2);
        if (p1 == NULL) {root = insert(root,id1);dem++;printf("Cay co %d\n",dem);}
        if (p2 == NULL) {root = insert(root,id2);dem++;printf("Cay co %d\n",dem);}
        p1 = find(root,id1);
        p2 = find(root,id2);
        if (diem1 > diem2){
            p1->diem += 3;
        }else if (diem1 < diem2){
            p2->diem += 3;
        }else {
            p1->diem += 1;
            p2->diem += 1;
        }
    }
    fclose(f);
}
void inOrder(Node* r){
    if(r == NULL) return;
    inOrder(r->leftChild);
    printf("%s\t%d\n",r->name,r->diem);
    inOrder(r->rightChild);
}
void inOrderF(Node* r,FILE *f){
    if(r == NULL) return;
    inOrderF(r->leftChild,f);
    fprintf(f,"%s\t%d\n",r->name,r->diem);
    inOrderF(r->rightChild,f);
}
void cn3(){
    printf("Nhap ma doi bong can tim kiem\n");
    char id[MAX_L];
    scanf("%s",id);
    Node *p = find(root,id);
    if (p != NULL){
        printf("Diem so cua doi bong la: %d\n", p->diem);
    }else {
        printf("Khong co doi bong nay!\n");
    }
}
void inOrder_1(Node* r,int x){
    if(r == NULL) return;
    if (r->diem < x) {
        printf("Doi bong bi xuong hang la %s voi so diem %d\n",r->name,r->diem);
        strcpy(arr[i].s,r->name);
        i++;
    }
    inOrder_1(r->leftChild,x);
    inOrder_1(r->rightChild,x);
}
void cn4(){
    int x;
    printf("Nhap vao diem so mong muon\n");
    scanf("%d",&x);
    inOrder_1(root,x);
    for (int j=0;j<i;j++){
        root = removeStudent(root,arr[j].s);
    }
    printf("Cay moi la\n");
    inOrder(root);
}
int main(){
    while(1){
        int cn;
        printf("1.  Tao cay\n");
        printf("2.  Ket qua\n");
        printf("3.  Tim kiem\n");
        printf("4.  Xuong hang\n");
        printf("5.  Xuat file\n");
        printf("Hay chon chuc nang\n");
        scanf("%d",&cn);
        if (cn==1){
            load();
        }else if (cn == 2){
            inOrder(root);
        }else if (cn == 3){
            cn3();
        }else if (cn == 4){
            cn4();
        }else if (cn == 5){
            FILE *f = fopen("ketqua.txt","w");
            inOrderF(root,f);
            fclose(f);
        }
    }

}
