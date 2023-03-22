#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_L 256
typedef struct Node{
    char name[MAX_L];
    char word[MAX_L];
    float d;
    struct Node *leftChild;
    struct Node *rightChild;
}Node;
Node *root;
int t=1;
Node* makeNode(char* name, char* word, float d){
    Node* p = (Node*)malloc(sizeof(Node));
    strcpy(p->name,name); strcpy(p->word,word);
    p->d = d;
    p->leftChild = NULL; p->rightChild = NULL;
    return p;
}
Node* insert(Node* r, char* name, char* word,float d){
    if(r == NULL) return makeNode(name,word,d);
    int c = strcmp(r->name,name);
    if(c < 0){
        r->rightChild = insert(r->rightChild,name,word,d); return r;
    }else{
        r->leftChild = insert(r->leftChild,name,word,d); return r;
    }
}
Node* find(Node* r, char* name){
    if(r == NULL) return NULL;
    int c = strcmp(r->name,name);
    if(c == 0) return r;
    if(c < 0) return find(r->rightChild,name);
    return find(r->leftChild,name);
}
void inOrder(Node* r){
    if(r == NULL) return;
    inOrder(r->leftChild);
    printf("%s\t%s\t%.1f\n",r->name,r->word,r->d);
    inOrder(r->rightChild);
}
void inOrder_1(Node* r){
    if(r == NULL) return;
    inOrder(r->leftChild);
    if (strcmp(r->name,"Admin") != 0){
        printf("%s\t%s\t%.1f\n",r->name,r->word,r->d);
    }
    inOrder(r->rightChild);
}
void inOrderF(Node* r, FILE* f){
    if(r == NULL) return;
    inOrderF(r->leftChild,f);
    if (r->leftChild == NULL && r->rightChild == NULL) {
        fprintf(f,"%s\t%s\t%.1f",r->name,r->word,r->d);
    }
    else {fprintf(f,"%s\t%s\t%.1f\n",r->name,r->word,r->d);}
    inOrderF(r->rightChild,f);
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
strcpy(r->word,tmp->word);
r->d = tmp->d;
r->rightChild = removeStudent(r->rightChild,tmp->name);
}else{
Node* tmp = r;
if(r->leftChild == NULL) r = r->rightChild; else r = r->leftChild;
free(tmp);
}
}
return r;}
void load(){
    FILE *f = fopen("sinhvien.txt","r");
    while (!feof(f)){
        char name[MAX_L];
        char word[MAX_L];
        float d;
        fscanf(f,"%s\t%s\t%f",name,word,&d);
        root = insert(root,name,word,d);
    }
    fclose(f);
}
int check(char *s){
    for (int i=0;i<strlen(s);i++){
        if (s[i]==' ') return 0;
    }
    return 1;
}
void cn1(){
    int x=1;
    int k=0;
    while (x)
    {
        char name[MAX_L];
        char word[MAX_L];
        printf("Nhap user va pass: ");
        scanf("%s",name);
        scanf("%s",word);
        Node *p = find(root,name);
        if (p != NULL && strcmp(p->word,word)==0){
            k=0;
            printf("Dang nhap thanh cong\n");
            while (1)
            {
                if (strcmp(p->name,"Admin") != 0){
                int cn1;
                printf("Nhap chuc nang duoi dang sinh vien: ");
                scanf("%d",&cn1);
                if (cn1==1){
                    printf("Diem cua sinh vien %s: %.1f\n",p->name,p->d);
                }else if (cn1==2){
                    int a=0;
                    do {
                        printf("Nhap mat khau de thay doi\n");
                        char mk1[MAX_L];
                        char mk2[MAX_L];
                        printf("Nhap mat khau moi lan 1\n");
                        fflush(stdin);
                        gets(mk1);
                        if (check(mk1)==1){
                            printf("Nhap mat khau moi lan 2\n");
                            fflush(stdin);
                            gets(mk2);
                            a=1;
                            if (strcmp(mk1,mk2)==0){
                                printf("Thay doi mat khau thanh cong\n");
                                strcpy(p->word,mk1);
                            }
                            else {
                                printf("Doi mat khau khong thanh cong\n");
                            }
                        }else {
                            printf("Sai\n");
                        }
                    }while(a==0);
                }else if (cn1 == 3){
                    FILE* f = fopen("sinhvien.txt","w");
                    inOrderF(root,f);
                    fclose(f);
                    break;
                }
                }else{
                    printf("Nhap chuc nang duoi dang Admin: \n");
                    int cn2;
                    scanf("%d",&cn2);
                    if (cn2 == 1){
                        int b=0;
                        do {
                            char name1[MAX_L];
                            printf("Nhap thong tin cua sinh vien muon them: \n");
                            fflush(stdin);
                            gets(name1);
                            if (check(name1)){
                                b=1;
                                char word1[MAX_L];
                                fflush(stdin);
                                gets(word1);
                                float d1;
                                scanf("%f",&d1);
                                printf("Nhap thanh cong\n");
                                root = insert(root,name1,word1,d1);
                                break;
                            }else {
                                printf("Sai\n");
                            }
                        }while(b==0);
                    }else if (cn2 == 2){
                        inOrder_1(root);
                    }else if (cn2==3){
                        char name2[MAX_L];
                        printf("Nhap ten sinh vien muon xoa\n");
                        fflush(stdin);
                        gets(name2);
                        Node *p1 = find(root,name2);
                        if (strcmp(p1->name,"Admin") ==0 || p1 == NULL){
                            printf("Khong co sinh vien nay\n");
                        }else {
                            printf("%s\t%s\t%.1f\n",p1->name,p1->word,p1->d);
                            root = removeStudent(root,name2);
                            printf("Xoa thanh cong\n");
                        }
                    }else if (cn2 == 4){
                        FILE* f = fopen("sinhvien.txt","w");
                        inOrderF(root,f);
                        fclose(f);
                        break;
                    }
                }
            }
            
        }else {
            if (k>=3) {
                printf("Ban da nhap sai 3 lan\n");
                t=0;x=0;
            }
            else{
                k++;
                printf("Nhap sai lan %d\n",k);
                printf("Nhap lai thong tin\n");
            }
        }
    }
    
}
int main(){
    load();
    inOrder(root);
    while (t){
        printf("Nhap chuc nang Menu chinh\n");
        int cn;
        printf("----------------\n");
        printf("1.  Dang nhap\n");
        printf("2.  Thoat\n");
        scanf("%d",&cn);
        switch (cn)
        {
        case 1:
            cn1();
            break;
        case 2:
            t = 0;
            break;
        default:
            break;
        }

    }
}