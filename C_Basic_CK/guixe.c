#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct TNode{
    char liP[20];
    char date[20];
    char time[20];
    int stt;
    struct Tnode *left;
    struct Tnode *right;
}Tnode;
typedef struct carPark{
    char liP[20];
    char date[20];
    char time[20];
    int stt;
    struct carPark *next;
}node;

void printMenu(){
    printf("Chuong trinh quan ly bai xe\nVui long chon mot trong cac chuc nang sau\n");
    printf("[1] Doc du lieu tu file log\n[2] Tra cuu so luong xe gui/lay theo ngay trong qua khu\n[3] Thong tin cac xe trong bai hien tai\n[4] Gui them xe moi\n[5] Tra xe\n[6] Cap nhat log du lieu\n[7] Luu danh sach xe dang co trong bai ra file\n");
    printf("Lua chon cua ban la: ");
}


node *head;

node*makeNode(char *liP, char *date, char*time, int stt){
    node* p = (node*)malloc(sizeof(node));
    strcpy(p->liP, liP);
    strcpy(p->date, date);
    strcpy(p->time, time);
    p->stt = stt;
    p->next = NULL;
    return p;
}

node* insertLast(node* h, char *liP, char *date, char*time, int stt){
    if(h == NULL){
        return makeNode(liP, date, time, stt);
    }
    h -> next = insertLast(h -> next, liP, date, time, stt);
    return h;
}


Tnode *root;

Tnode* makeTnode(char* liP, char* date, char *time){
    Tnode* p = (Tnode*)malloc(sizeof(Tnode));
    strcpy(p->liP, liP); 
    strcpy(p->date, date);
    strcpy(p->time, time);
    p->left = NULL; 
    p->right = NULL;
    return p;
}

Tnode* insert(Tnode* r, char* liP, char* date, char *time){
    if(r == NULL) return makeTnode(liP, date, time);
    int c = strcmp(r->liP,liP);
    if(c == 0){
    printf("Da co xe nay trong bai \n"); return r;
    }else if(c < 0){
        r->right = insert(r->right, liP, date, time); 
        return r;
    }else{
        r->left = insert(r->left, liP, date, time); 
        return r;
    }
}
Tnode* findMin(Tnode* r){
    if(r == NULL) return NULL;
    Tnode* lmin = findMin(r->left);
    if(lmin != NULL) return lmin;
    return r;
}
Tnode* removeUser(Tnode* r, char* liP){
    if(r == NULL) return NULL;
    int c = strcmp(r->liP,liP);
    if(c > 0) r->left = removeUser(r->left,liP);
    else if(c < 0) r->right = removeUser(r->right,liP);
    else{
        if(r->left != NULL && r->right != NULL){
            Tnode* tmp = findMin(r->right);
            strcpy(r->liP,tmp->liP); 
            strcpy(r->date,tmp->date);
            strcpy(r->time,tmp->time);
            r->right = removeUser(r->right,tmp->liP);
        }
        else{
            Tnode* tmp = r;
            if (r->left == NULL) r = r->right;
            else r = r->left;
            free(tmp);
        }
    }
    return r;
}

void Load(){
    FILE *f = fopen("guixe.txt", "r");
    while (!feof(f)){
        char licensePlate[20];
        char date[20];
        char time[20];
        int stt;
        fscanf(f,"%s\t%s\t%s\t%d", licensePlate, date, time, &stt);
        head = insertLast(head, licensePlate, date, time, stt);
        if(stt==1) root = insert(root, licensePlate, date, time);
        else root = removeUser(root, licensePlate);
    }
    fclose(f);
}

int count(Tnode *r){
    if(r==NULL) return 0;
    return 1 + count(r->left) + count(r->right);
}

void printList(Tnode *r){
    if(r == NULL) return;
    printList(r->left);
    printf("%-20s%s %s\n",r->liP, r->date, r->time);
    printList(r->right);
}

int main () { 
    int exit = 0;
    int choice;
    root = NULL;
    while(exit==0){
        printMenu();
        scanf("%d", &choice);
        switch(choice){
            case 1:
                Load();
                break;
            case 2:
                break;
            case 3:
                printf("So luong xe co trong bai : %d\n", count(root));
                if(count(root)!=0) {
                    printf("%-20s%-20s\n", "Bien so" "Thoi gian gui");
                    printList(root);
                }
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            case 8:
                exit = 1;
                break;
        }
    }
return 0;
}