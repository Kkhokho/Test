#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// Khi lam viec voi con tro, muon thay doi gia tri cua con tro ma minh truyen vao thi phai cap phat vung o nho quan ly cho bien con tro
// -> toan tu tham chieu cho con tro : **

typedef struct node{
    int data;
    struct node *next;
}Node;

//Ham cap phat bo nho cho mot node moi
Node *makeNode(int x){
    Node *node = (Node*)malloc(sizeof(Node));
    node->data = x;
    node->next = NULL;
    return node;
}


//Ham them mot phan tu vao dau stack
void pushFirst(Node **top, int x){
    Node *tmp = makeNode(x);
    if(*top == NULL){
        *top = tmp;
        return;
    }else{
        tmp->next = *top;
        *top = tmp;
    }
}

//Ham xoa 1 phan tu o dau danh sach cua stack
void popFirst(Node **top){
    if(*top != NULL){
        Node *tmp = *top;
        *top = tmp->next;
        free(tmp);
    }
}

//Ham tra ve gia tri dau cua danh sach trong stack
int topS(Node *top){
    if(top != NULL){
        return top->data;
    }
}

//Ham tra ve kich thuoc cua danh sach trong stack
int size(Node *top){
    int cnt = 0;
    while(top != NULL){
        cnt++;
        top = top->next;
    }
    return cnt;
}

//Ham in ra danh sach cua stack
void print(Node *top){
    while(top != NULL){
        printf("%d ", top->data);
        top = top->next;
    }
}

int main (){ 
    int exit = 0, choice;
    Node *head = NULL;
    do{
        printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
        printf("\n1. Them 1 phan tu vao stack\n");
        printf("2. Xoa 1 phan tu o dinh stack\n");
        printf("3. Kiem tra phan tu o dinh stack\n");
        printf("4. Kich thuoc danh sach cua stack\n");
        printf("5. In ra danh sach cua stack\n");
        printf("6. Thoat\n");
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("Vui long chon chuc nang: "); scanf("%d", &choice);
        switch(choice){
            case 1:
                int x; scanf("%d", &x);
                pushFirst(&head, x);
                break;
            case 2:
                popFirst(&head);
                break;
            case 3:
                if(head != NULL) printf("Phan tu dinh stack la: %d", topS(head));
                else printf("Stack rong!!!");
                break;
            case 4:
                printf("Kich thuoc cua stack la: %d", size(head));
                break;
            case 5:
                printf("Danh sach trong stack la: ");
                print(head);
                break;
            case 6:
                exit = 1;
                break;
        }
    }while(exit == 0);
    return 0;
}