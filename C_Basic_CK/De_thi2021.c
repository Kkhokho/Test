#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_L 256
typedef struct Node{
    char name[MAX_L];
    float open[11];
    float close[11];
    float tygia[11];
    int d;
    struct Node *leftChild;
    struct Node *rightChild;
}Node;
Node *root;
int i=0;
int max1 = 0;
Node* makeNode(char* name){
    Node* p = (Node*)malloc(sizeof(Node));
    strcpy(p->name,name);
    p->d = 0;
    p->leftChild = NULL; p->rightChild = NULL;
    return p;
}
Node* insert(Node* r, char* name){
    if(r == NULL) return makeNode(name);
    int c = strcmp(r->name,name);
    if(c == 0){
        return r;
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
void load(){
    FILE* f = fopen("chungkhoan.txt","r");
    int n;
    fscanf(f,"%d",&n);
    while (!feof(f))
    {
        for (int k=0;k<n;k++){
            char name[MAX_L];
            float a,b;
            fscanf(f,"%s\t%f\t%f",name,&a,&b);
            root = insert(root,name);
            Node *p = find(root,name);
            p->open[i] = a;
            p->close[i] = b;
            p->tygia[i] = b - a;
            if (p->tygia[i] > 0){
                p->d++;
            }
        }
        i++;
    }
    fclose(f);
}
void inOrder(Node* r){
    if(r == NULL) return;
    inOrder(r->leftChild);
    printf("%s\n",r->name);
    for (int j=0;j<i;j++){
        printf("Ngay %d: %.3f\n",j+1,r->close[j] - r->open[j]);
    }
    printf("So ngay ty gia tang la: %d\n",r->d);
    inOrder(r->rightChild);
}
void cn2(){
    char name[MAX_L];
    printf("Nhap ten tim kiem: ");
    scanf("%s",name);
    Node *p = find(root,name);
    if (p == NULL){
        printf("Khong ton tai!!!\n");
    }else {
        float min,max;
    min = p->close[0];
    max = p->close[i-1];
    for (int j=0;j<i;j++){
        if (p->close[j] > max){
            max = p->close[j];
        }
        if (p->close[j] < min){
            min = p->close[j];
        }
    }
    printf("Ty gia dong cua thap nhat: %.3f\n",min);
    printf("Ty gia dong cua cao nhat: %.3f\n",max);
    }
}
void cn3(Node *r){
    if(r == NULL) return;
    cn3(r->leftChild);
    if (r->tygia[0] > 0 && r->tygia[1] > 0 ){
        printf("%s\n",r->name);
    }
    cn3(r->rightChild);
}
void cn4(Node* r){
    if(r == NULL) return;
    cn4(r->leftChild);
    if (r->d > max1){
        max1 = r->d;
    } 
    cn4(r->rightChild);
}
void cn4_1(Node *r){
    if(r == NULL) return;
    cn4_1(r->leftChild);
    if (r->d == max1){
        printf("%s\n",r->name);
    } 
    cn4_1(r->rightChild);
}
int main(){
    while (1){
        int cn;
        printf("1.  Doc file\n");
        printf("2.  Tim kiem theo ma chung khoan\n");
        printf("3.  Tim kiem ma chung khoan co xu huong tang\n");
        printf("4.  Tim ma co so ngay tang lon nhat\n");
        printf("5.  Thoat chuong trinh\n");
        printf("Chon chuc nang: ");
        scanf("%d",&cn);
        if (cn==1){
            load();
            inOrder(root);
        }else if (cn==2){
            cn2();
        }else if (cn==3){
            cn3(root);
        }else if (cn==4){
            //printf("%d\n",max1);
            cn4(root);
            cn4_1(root);
        }else if (cn==5){
            printf("Mai Minh Khoi 20210492\n");
            break;
        }
    }
}