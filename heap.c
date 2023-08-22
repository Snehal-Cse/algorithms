#include<stdio.h>

void maxHeapify(int arr[],int n ,int i){
    int largest = i;
    int l = 2*i+1;
    int r = (2*i)+2;
    while(l<n&&arr[l]>arr[largest]) largest = l;
    while(r<n&&arr[r]>arr[largest]) largest = r;
    if(largest!=i){
        int temp = arr[largest];
        arr[largest]=arr[i];
        arr[i] = temp;
        maxHeapify(arr,n,largest);
    }
}
void heapSort(int arr[],int n){
    for(int i=n/2-1;i>=0;i--){
        maxHeapify(arr,n,i);
    }
    for(int i = n-1 ;i>=0;i--){
        int temp = arr[0];
        arr[0]=arr[i];
        arr[i] = temp;
        maxHeapify(arr,i,0);
    }
}
int main(){
    int arr[]={2,1,3,0};
    int n =4;
    heapSort(arr,n);

    for(int i =0;i<n;i++){
        printf("%d ",arr[i]);
    }
}
