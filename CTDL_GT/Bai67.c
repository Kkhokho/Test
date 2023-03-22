#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct Node{
    char c;
    struct Node* next;
}Node;
int a[100];
Node* top;
Node* makeNode(char x){
    Node* p = (Node*)malloc(sizeof(Node));
    p->c = x; 
    p->next = NULL;
    return p;}
void initStack(){
    top = NULL;}
int stackEmpty(){
    return top == NULL;}
void push(char x){
    Node* p = makeNode(x);
    p->next = top; top = p;}
char pop(){
    if(stackEmpty()) return ' ';
    char x = top->c;
    //Node* tmp = top; 
    top = top->next; 
    //free(tmp);
    return x;}
int match(char a, char b){
    if(a == '(' && b == ')') return 1;
    if(a == '[' && b == ']') return 1;
    if(a == '{' && b == '}') return 1;
    return 0;}
void check(char* s){
    initStack();
    int d = 0;
    for(int i = 0; i < strlen(s); i++){ 
    if(s[i] == '(' || s[i] == '[' || s[i] == '{'){push(s[i]);d = d + 2;} 
    else{
    if(stackEmpty()) return ;
    char x = pop();
    if(match(x,s[i])){
        a[i] = d;
        printf("%d ",d);
    }}}}
int main(){
    char s[1000],s1[1000];
    int j=0;
    scanf("%s",s);
    for (int i=0;i<strlen(s);i++){
        if (s[i] == '(' || s[i] == '[' || s[i] == '{' ||s[i] == ')' || s[i] == ']' || s[i] == '}'){
            s1[j] = s[i];
            j++;
        }
    }
    check(s1);
    return 0;
}