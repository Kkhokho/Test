#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include <stdint.h>
#include <sys/time.h>
int *a;
typedef struct {
    long         tv_sec ;   //used for seconds
    long        tv_usec ;   //used for microseconds
}timeval;
//sinh ngau nhien so co gia tri toi co 1tr
int getNextRandNumber(){
    int a = rand();
    int b = rand();
    return a*1000+b;
}
struct timeval timeSub(struct timeval s, struct timeval e){
    struct timeval tval_result;
    tval_result.tv_sec = 	e.tv_sec - s.tv_sec;
    tval_result.tv_usec = e.tv_usec - s.tv_usec;
    if(tval_result.tv_usec<0) {
    tval_result.tv_usec = 1000000+tval_result.tv_usec;
    tval_result.tv_sec--;
    }
    return tval_result;
}
// ham sinh ngau nhien phan tu cua mang va cac phan tu khong trung nhau
int *generateRandomArray(int size) 
{
    struct timeval tval_before, tval_after, tval_result;
    gettimeofday(&tval_before, NULL);	
// khai bao mang dong
    int *arr = (int*) malloc(size*sizeof(int));
    int n=0, nextNum, check, i;
    while(n<size){
    nextNum = getNextRandNumber();
// kiem tra xem da bi trung? O(n^2)
    check = 0;
    for(i=0;i<n;i++){
        if(arr[i]==nextNum) {
            check =1;
            break;}}
    if(check==0){ // so khong bi trung
        arr[n]=nextNum;
        n++;}}
    gettimeofday(&tval_after, NULL);
    tval_result = timeSub(tval_before, tval_after);
    printf("thoi gian sinh mang : %ld.%06ld\n", (long int)tval_result.tv_sec, (long int)tval_result.tv_usec);
return arr;
}
void sortArray(int *arr,int size){
    struct timeval tval_before, tval_after, tval_result;
    gettimeofday(&tval_before, NULL);
    for (int i=0;i<size-1;i++){
        for (int j=i+1;j<size;j++){
            if (arr[i]>arr[j]){
                int tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
    gettimeofday(&tval_after, NULL);
    tval_result = timeSub(tval_before, tval_after);
    printf("thoi gian bubble sort : %ld.%06ld\n", (long int)tval_result.tv_sec, (long int)tval_result.tv_usec);
}
int BinarySearch(int size,int target){
    int l=0,r=size-1,mid;
    while (l<=r){
        mid = (l+r)/2;
        if (a[mid] > target){
            r = mid - 1;
        }else if (a[mid] < target){
            l = mid + 1;
        }else return mid;
    }
    return -1;
}
int search(int size,int target){
    for (int i=0;i<size;i++){
        if (a[i]==target){
            return i;
        }
    }
    return -1;
}
int main(){
    a = generateRandomArray(10000);
    sortArray(a,10000);
    
    struct timeval tval_before, tval_after, tval_result;
    gettimeofday(&tval_before, NULL);
    int j=1;
    long long b[11];
    while (j<=10){
        printf("nhap so de tim kiem: ");
        scanf("%d",&b[j]);
        long long k = BinarySearch(10000,b[j]);
        if ( k !=-1){
            printf("index = %d\n",k);
        }else{
            printf("khong tim thay\n");
        }
        j++;
    }
    gettimeofday(&tval_after, NULL);
    tval_result = timeSub(tval_before, tval_after);
    printf("thoi gian thuc hien 10 lan BS : %ld.%06ld\n", (long int)tval_result.tv_sec, (long int)tval_result.tv_usec);
    struct timeval tval_before1, tval_after1, tval_result1;
    gettimeofday(&tval_before1, NULL);
    int t=1;
    while(t<=10){
        long long h = search(10000,b[t]);
        t++;
    }
    gettimeofday(&tval_after1, NULL);
    tval_result1 = timeSub(tval_before1, tval_after1);
    printf("thoi gian thuc hien 10 lan NS : %ld.%06ld\n", (long int)tval_result1.tv_sec, (long int)tval_result1.tv_usec);
    return 0;
}


