#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node_lk{
    char req[8];
    char ma[4];
    int so_nguoi;
    int ma_phong;
    char date[11];
    int kids;
    struct Node_lk* next;
}Node_lk;

Node_lk* head,*last;

void initList(){
    head=NULL;last=NULL;
}

int listEmpty(){
    return head==NULL&&last==NULL;
}

Node_lk* makeNode_lk(char* req,int a,int b,char* s,char* s1,int kid){
    Node_lk* p = (Node_lk*) malloc(sizeof(Node_lk));
    strcpy(p->req,req);
    p->so_nguoi=a;
    p->ma_phong=b;
    strcpy(p->ma,s);
    strcpy(p->date,s1);
    p->kids=kid;
    p->next=NULL;
    return p;
}

void insertLast(char* req,int a,int b,char* s,char* s1,int kid){
    Node_lk* p= makeNode_lk(req,a,b,s,s1,kid);
    if(listEmpty()){
        head=p;
        last=p;
    }else{
        last->next=p;
        last=p;
    }
}

int n;

void load_file(){
    FILE* f= fopen("booking_orders.txt","r");
    if(f==NULL){
        printf("KHONG DOC DUOC FILE!\n");
    }else{
        char req[8];
        char ma[4];
        int so_nguoi;
        int ma_phong;
        char date[11];
        int kids;
        fscanf(f,"%d",&n);
        while(!feof(f)){
            fscanf(f,"%s%d%d%s%s%d",req,&so_nguoi,&ma_phong,ma,date,&kids);
            insertLast(req,so_nguoi,ma_phong,ma,date,kids);
        }
    }
}

typedef struct Node{
    Node_lk* data;
    struct Node* left;
    struct Node* right;
}Node;

Node* root = NULL;

Node* makeNode(Node_lk* lk){
    Node* p = (Node*) malloc(sizeof(Node));
    p->data=lk;
    p->left = NULL;
    p->right = NULL;
    return p;
}

Node* insert_Node(Node* r,Node_lk* lk){
    if(r == NULL) return makeNode(lk);
    int c = strcmp(r->data->req,lk->req);
    if(c<0){
        r->right = insert_Node(r->right,lk);
    }else if(c>0){
        r->left = insert_Node(r->left,lk);
    }
    return r;
}

Node* find_Node(Node* r,char* s){
    if(r==NULL) return NULL;
    int c =strcmp(r->data->req,s);
    if(c==0) return r;
    if(c<0) return find_Node(r->right,s);
    if(c>0) return find_Node(r->left,s);
}

void duyet(Node* p){
    if(p==NULL) return;
    duyet(p->left);
    printf("%-12s%-5d%-5d%-5s%-15s%-5d\n",p->data->req,p->data->so_nguoi,p->data->ma_phong,p->data->ma,p->data->date,p->data->kids);
    duyet(p->right);
}

Node* thay_doi(Node* r){
    char s[8];
    printf("Nhap ma yeu cau thay doi:");
    scanf("%s",s);
    Node* p = find_Node(r,s);
    if(p==NULL){
        printf("NOT FOUND\n");
        return r;
    }
    printf("Moi ban nhap thay doi:\n");
    char date[11];int nguoi;int kid;
    printf("Nhap thay doi date:");
    scanf("%s",date);
    printf("Nhap thay doi nguoi va tre em:");
    scanf("%d%d",&nguoi,&kid);
    if(nguoi-kid<1){
        printf("Invaild\n");
        return r;
    }
    strcpy(p->data->date,date);
    p->data->so_nguoi=nguoi;
    p->data->kids=kid;
    printf("Update\n");
    return r;
}

Node* find_MIN(Node* r,char* s){
    if(r==NULL) return NULL;
    Node* lmin = find_MIN(r->left,s);
    if(lmin!=NULL) return lmin;
    return r;
}

Node* delete_Node(Node* r,char* x){
    if(r==NULL) return NULL;
    int c=strcmp(r->data->req,x);
    if(c>0){
        r->left = delete_Node(r->left,x);
    }else if(c<0){
        r->right = delete_Node(r->right,x);
    }else{
        if(r->left!=NULL&&r->right!=NULL){
            Node* tmp = find_MIN(r->right,x);
            // copy du lieu tu nut tmp sang r;
            r->data=tmp->data;
            r->right = delete_Node(r->right,tmp->data->req);
        }else{
            Node* tmp = r;
            if(r->left!=NULL){
                r = r->left;
            }else{
                r = r->right;
            }
            free(tmp);
        }
    }
    return r;
}

void ghi_file(FILE* f,Node* r){
    if(r==NULL) return;
    ghi_file(f,r->left);
    fprintf(f,"%s\t%d\t%d\t%s\t%s\t%d\n",r->data->req,r->data->so_nguoi,r->data->ma_phong,r->data->ma,r->data->date,r->data->kids);
    ghi_file(f,r->right);
}

void freeBST(Node* r){
    if(r==NULL) return;
    freeBST(r->left);
    freeBST(r->right);
    free(r);
}

int main(){
    initList();
    while(1){
        printf("Chuong trinh quan ly dat phong\n");
        printf("Vui long chon mot trong cac chuc nang sau\n");
        printf("[1] Doc du lieu file log\n");
        printf("[2] Kiem tra so luong yeu cau khong hop le\n");
        printf("[3] Tra cuu theo ma yeu cau\n");
        printf("[4] Thay doi yeu cau\n");
        printf("[5] Huy yeu cau\n");
        printf("[6] Luu danh sach yeu cau ra file\n");
        int choose;
        scanf("%d",&choose);
        if(choose==1){
            load_file();
            printf("So luong yeu cau doc duoc la:%d\n",n);
        }else if(choose==2){
            int m=0;
            for(Node_lk* p = head;p!=NULL;p=p->next){
                if(p->so_nguoi-p->kids<1) m++;
            }
            printf("So luong cac yeu cau KHONG hop le la:%d\n",m);
        }else if(choose==3){
            for(Node_lk* p=head;p!=NULL;p=p->next){
                root = insert_Node(root,p);
            }
            printf("Nhap ma yeu cau:");
            char s[8];
            scanf("%s",s);
            Node* p =find_Node(root,s);
            if(p==NULL){
                printf("Not found\n");
            }else{
                printf("%-12s%-5d%-5d%-5s%-15s%-5d\n",p->data->req,p->data->so_nguoi,p->data->ma_phong,p->data->ma,p->data->date,p->data->kids);
            }
        }else if(choose==4){
            root = thay_doi(root);
        }else if(choose==5){
            char s1[8];
            printf("Nhap ma yeu cau can xoa:");
            scanf("%s",s1);
            Node* p=find_Node(root,s1);
            if(p==NULL){
                printf("Not found\n");
            }else{
                root = delete_Node(root,s1);
                printf("Delete!\n");
                n--;
                //duyet(root);
            }
        }else if(choose==6){
            FILE* f1 =fopen("booking_output.txt","w");
            fprintf(f1,"%d",n);
            ghi_file(f1,root);
            printf("So luong duoc ghi vao file la:%d\n",n);
            fclose(f1);
            
        }
    }
    freeBST(root);
}