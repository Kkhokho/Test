#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_L 256
typedef struct Node{
    char name[MAX_L];
    int a;
    int b;
    char s[MAX_L];
    int ngay;
    int thang;
    int nam;
    int d;
    struct Node *leftChild;
    struct Node *rightChild;
}Node;
Node *root;
int n;
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
void load(){
    FILE *f=fopen("log.txt","r");
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
        root = insert(root,name,a,b,s,ngay,thang,nam,d);
    }
    fclose(f);
}
void inOrder(Node* r){
    if(r == NULL) return;
    inOrder(r->leftChild);
    printf("%s %d %d %s %02d-%02d-%d %d\n",r->name,r->a,r->b,r->s,r->ngay,r->thang,r->nam,r->d);
    inOrder(r->rightChild);
}
int main(){
    load();
    inOrder(root);
    return 0;
}