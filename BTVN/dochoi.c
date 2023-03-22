#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX 100

typedef struct Node
{
    int maso;
    char dochoi[31];
    struct Node *leftChild;
    struct Node *rightChild;
} Node;

typedef struct Node_B
{
    int num;
    char toy[31];
} Node_B;

Node *root;
Node_B nodeB[100];
int count = 0;

// Ham tao ra 1 node (1 cap ma so - do choi moi)
Node *makeNode(int maso, char *dochoi)
{
    Node *p = (Node *)malloc(sizeof(Node));
    p->maso = maso;
    strcpy(p->dochoi, dochoi);
    p->leftChild = NULL;
    p->rightChild = NULL;
}

// Ham chen 1 node moi vao cay
Node *insert(Node *r, int maso, char *dochoi)
{
    if (r == NULL)
        return makeNode(maso, dochoi);
    if (r->maso == maso)
    {
        printf("Ma so %d da ton tai! Xin thu lai!\n", maso);
        return r;
    }
    else if (r->maso < maso)
    {
        r->rightChild = insert(r->rightChild, maso, dochoi);
        return r;
    }
    else
    {
        r->leftChild = insert(r->leftChild, maso, dochoi);
        return r;
    }
}
// Ham tim kiem node tren cay theo maso
Node *find(Node *r, int maso)
{
    if (r == NULL)
        return NULL;
    // int c = strcmp(r->name, name);
    if (r->maso == maso)
        return r;
    if (r->maso < maso)
        return find(r->rightChild, maso);
    return find(r->leftChild, maso);
}

// Ham xoa 1 node
Node *findMin(Node *r)
{
    if (r == NULL)
        return NULL;
    Node *lmin = findMin(r->leftChild);
    if (lmin != NULL)
        return lmin;
    return r;
}

Node *removeToy(Node *r, int maso)
{
    if (r == NULL)
        return NULL;
    // int c = strcmp(r->name, name);
    if (r->maso > maso)

        r->leftChild = removeToy(r->leftChild, maso);
    else if (r->maso < maso)
        r->rightChild = removeToy(r->rightChild, maso);
    else
    {
        if (r->leftChild != NULL && r->rightChild != NULL)
        {
            Node *tmp = findMin(r->rightChild);
            strcpy(r->dochoi, tmp->dochoi);
            r->maso = maso;

            r->rightChild = removeToy(r->rightChild, tmp->maso);
        }
        else
        {
            Node *tmp = r;
            if (r->leftChild == NULL)
                r = r->rightChild;
            else
                r = r->leftChild;
            free(tmp);
        }
    }
    return r;
}

// Ham duyet giua
void inOrder(Node *r)
{
    if (r == NULL)
        return;
    inOrder(r->leftChild);
    printf("%d\t%s\n", r->maso, r->dochoi);
    inOrder(r->rightChild);
}

void getStr(char ch[])
{
    fflush(stdin);
    scanf("%[^\n]s", ch);
}

// Chuc nang 1 ham doc du lieu tu file A roi ghi vao cay BST
void loadfileA(char *filename)
{
    FILE *f = fopen(filename, "r");
    root = NULL;

    int key;
    char toy[31];
    char query[51];
    char *p;

    while (!feof(f))
    {
        fgets(query, 50, f);
        p = strtok(query, "    ");
        if (atoi(p) == 0)
        {
            p[strlen(p) - 1] = '\0';
            printf("Thieu Id cho do choi %s vui long nhap them: ", p);
            scanf("%d", &key);
            strcpy(toy, p);
        }
        else
        {
            key = atoi(p);
            p = strtok(NULL, "    ");
            if (p == NULL)
            {
                printf("Thieu do choi cho id %d: ", key);
                getStr(toy);
            }
            else
            {
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
    inOrder(root);
}

// Chuc nang 2 ham doc du lieu tu file B roi ghi vao mang cau truc
void loadfileB(char *filename)
{
    FILE *f = fopen(filename, "r");
    
    int key;
    char toy[31];
    char query[51];
    char *p;
    while (!feof(f))
    {
        fgets(query, 50, f);
        p = strtok(query, " ");
        if (atoi(p) == 0)
        {
            p[strlen(p) - 1] = '\0';
            printf("Thieu Id cho do choi %s vui long nhap them: ", p);
            scanf("%d", &key);
            strcpy(toy, p);
        }
        else
        {
            key = atoi(p);
            p = strtok(NULL, " ");
            if (p == NULL)
            {
                printf("Thieu do choi cho id %d: ", key);
                getStr(toy);
            }
            else
            {
                p[strlen(p) - 1] = p[strlen(p) - 1] == '\n' ? '\0' : p[strlen(p) - 1];
                strcpy(toy, p);
            }
        }
        count++;
        nodeB[count - 1].num = key;
        strcpy(nodeB[count - 1].toy, toy);
        printf("%d %s\n", key, toy);
    }
    fclose(f);
}

// Chuc nang 3 tim kiem
void timkiem()
{
    for (int i = 0; i < count; i++)
    {
        Node *found = find(root, nodeB[i].num);
        if (found != NULL)
        {
            printf("Id: %d\n", found->maso);
            root = removeToy(root, nodeB[i].num);
            //insert(root, nodeB[i].num, nodeB[i].toy);
            printf("%d\n",found->maso);
        }
    }
    inOrder(root);
    
}

int main()
{

    int m;

    while (1)
    {

        printf("       *** MENU ***         ");
        printf("\n   -------------------------------");
        printf("\n   1. Doc file A                  ");
        printf("\n   2. Doc file B                  ");
        printf("\n   3. Tim kiem                    ");
        printf("\n   4. Tong hop                    ");
        printf("\n   5. Thong ke                    ");
        printf("\n\nBan muon chon so: ");
        scanf("%d", &m);
        getchar();
        if (m == 5)
        {
            printf("Chuong trinh ket thuc!");
            printf("\n");
            break;
        }
        else if (m == 1)
        {
            loadfileA("A.txt");
            printf("\n");
        }
        else if (m == 2)
        {
            loadfileB("B.txt");
            printf("\n");
        }
        else if (m == 3)
        {
            timkiem();
            printf("\n");
        }
        else if (m == 4)
        {

            printf("\n");
        }
        else
        {
            printf("\nBan chon sai so.");
        }
    }
}