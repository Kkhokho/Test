#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_L 256
typedef struct{
    char toy[MAX_L];
    int count;
}Product;
typedef struct{
    int id;
    char toy[MAX_L];
}Profile;
Profile B[100];
int n=0;
typedef struct Node{
    int id;
    char toy[MAX_L];
    struct Node *leftChild;
    struct Node *rightChild;
}Node;
Node *root;
Product products[100];
int count = 0, countProduct = 0;
Node* makeNode(int id, char* toy){
    Node* p = (Node*)malloc(sizeof(Node));
    p->id = id; 
    strcpy(p->toy,toy);
    p->leftChild = NULL; 
    p->rightChild = NULL;
    return p;
}
Node* insert(Node* r, int id, char* toy){
    if(r == NULL) return makeNode(id,toy);
    int c = r->id - id;
    if(c == 0){
    printf("Id %s exists, do not insert\n",id); return r;
    }else if(c < 0){
            r->rightChild = insert(r->rightChild,id,toy); return r;
          }else{
        r->leftChild = insert(r->leftChild,id,toy); return r;
    }
}
void getStr(char ch[]){
    fflush(stdin);
    scanf("%[^\n]s",ch);
}
void inOrder(Node* r){
    if(r == NULL) return;
    inOrder(r->leftChild);
    printf("%d, %s\n",r->id,r->toy);
    inOrder(r->rightChild);
}
void addProduct(Node *root)
{
    if (countProduct == 0)
    {
        countProduct++;
        products[0].count = 1;
        strcpy(products[0].toy, root->toy);
    }
    else
    {
        int i;
        for (i = 0; i < countProduct; i++)
        {
            if (!strcmp(products[i].toy, root->toy))
            {
                products[i].count++;
                break;
            }
        }
        if (i == countProduct)
        {
            countProduct++;
            products[countProduct - 1].count = 1;
            strcpy(products[countProduct - 1].toy, root->toy);
        }
    }
}
void prevOrderBst(Node *root)
{
    if (root != NULL)
    {
        addProduct(root);
        prevOrderBst(root->leftChild);
        prevOrderBst(root->rightChild);
    }
}
void Order(Node *r){
    if (r==NULL) return;
    Order(r->rightChild);
    printf("%d, %s\n",r->id,r->toy);
    Order(r->leftChild);
}
void printList(){
    inOrder(root);
    printf("\n");
}
void printList_B(){
    for (int i=0;i<n;i++){
        printf("%d, %s\n",B[i].id,B[i].toy);
    }
}
Node* find(Node* r, int id){
    if(r == NULL) return NULL;
    int c = r->id - id;
    if(c == 0) return r;
    if(c < 0) return find(r->rightChild,id);
    return find(r->leftChild,id);
}
Node* findMin(Node* r){
    if(r == NULL) return NULL;
    Node* lmin = findMin(r->leftChild);
    if(lmin != NULL) return lmin;
    return r;
}
Node* removeStudent(Node* r, int id){
    if(r == NULL) return NULL;
    int c = r->id - id;
    if(c > 0) r->leftChild = removeStudent(r->leftChild,id);
    else if(c < 0) r->rightChild = removeStudent(r->rightChild,id);
        else{
            if(r->leftChild != NULL && r->rightChild != NULL){
            Node* tmp = findMin(r->rightChild);
            r->id = tmp->id; 
            strcpy(r->toy,tmp->toy);
            r->rightChild = removeStudent(r->rightChild,tmp->id);
            }else{
            Node* tmp = r;
            if(r->leftChild == NULL) r = r->rightChild; else r = r->leftChild;
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
void timkiem(){
    for (int i=0;i<n;i++){
        Node *p = find(root,B[i].id);
        if (p != NULL){
            printf("thong tin bi xoa: %d, %s\n",p->id,p->toy);
            root = removeStudent(root,p->id);
        }
    }
    printList();
}
void tonghop(){
    for (int i=0;i<n;i++){
        root = insert(root,B[i].id,B[i].toy);
    }
    Order(root);
}
void Load_A(char *filename){
    FILE *f = fopen(filename,"r");
    int key;
    char *p;
    char str[MAX_L];
    char toy[MAX_L];
    while (!feof(f)){
        fgets(str,MAX_L,f);
        p = strtok(str," ");
        if (atoi(p)==0){
            p[strlen(p)-1] = '\0';
            printf("Thieu Id cho do choi %s vui long nhap them: ", p);
            scanf("%d", &key);
            strcpy(p,toy);
        }else{
            key = atoi(p);
            p = strtok(NULL," ");
            if (p==NULL){
                printf("Thieu ten do choi co ID %d vui long nhap them: ", key);
                getStr(toy);
            }else {
                p[strlen(p) - 1] = p[strlen(p) - 1] == '\n' ? '\0' : p[strlen(p) - 1];
                strcpy(toy, p);
            }
        }
        if (root == NULL)
        {
            root = insert(root, key, toy);
        }
        else
            insert(root, key, toy);
    }
    fclose(f);
    printList();
}
void Load_B(char *filename){
    FILE *f = fopen(filename,"r");
    int key;
    char *p;
    char str[MAX_L];
    char toy[MAX_L];
    while (!feof(f)){
        fgets(str,MAX_L,f);
        p = strtok(str," ");
        if (atoi(p)==0){
            p[strlen(p)-1] = '\0';
            printf("Thieu Id cho do choi %s vui long nhap them: ", p);
            scanf("%d", &key);
            strcpy(p,toy);
        }else{
            key = atoi(p);
            p = strtok(NULL," ");
            if (p==NULL){
                printf("Thieu ten do choi co ID %d vui long nhap them: ", key);
                getStr(toy);
            }else {
                p[strlen(p) - 1] = p[strlen(p) - 1] == '\n' ? '\0' : p[strlen(p) - 1];
                strcpy(toy, p);
            }
        }
    B[n].id = key;
    strcpy(B[n].toy,toy);
    n++;    
    }
    printList_B();
    fclose(f);
}
void thongKe()
{
    prevOrderBst(root);
    for (int i=0;i<countProduct;i++)
    {
        printf("%s %d\n", products[i].toy, products[i].count);
    }
}
int main(){
    int t=1;
    while(t){
        printf("===================\n");
        printf("1.  Doc file A\n");
        printf("2.  Doc file B\n");
        printf("3.  Tim kiem\n");
        printf("4.  Tong hop\n");
        printf("5.  Thong ke\n");
        printf("====================\n");
        printf("Chon chuc nang: ");
        int cn;
        scanf("%d",&cn);
        switch (cn)
        {
        case 1:
            Load_A("A.txt");
            break;
        case 2:
            Load_B("B.txt");
            break;
        case 3:
            timkiem();
            break;
        case 4:
            tonghop();
            break;
        case 5:
            thongKe();
            break;
        case 6: 
            t=0;
            break;
        default:
            printf("HAY NHAP LAI!!!\n");
            break;
        }
    }
    
    return 0;
}