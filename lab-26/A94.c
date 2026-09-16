// Write a program to implement Merge Sort using Array.

#include<stdio.h> 
void merge(int a[],int low,int mid,int high){
    int b[100];
    int h = low ,i = low ,j = mid + 1;
    while(h<=mid && j<=high){
        if(a[h] <= a[j]){
            b[i] = a[h];
            h = h + 1;
        }else{
            b[i] = a[j];
            j = j + 1;
        }
        i = i + 1;
    }
    if(h>mid){
        for(int k=j;k<=high;k++){
            b[i]  = a[k];
            i = i + 1;
        }
    }else{
        for(int k=h;k<=mid;k++){
            b[i]  = a[k];
            i = i + 1;
        }
    }
    for(int k=low;k<=high;k++){
        a[k] = b[k];
    }
}
void mergeSort(int a[],int low,int high){
    if(low<high){
        int mid = (low+high)/2;
        mergeSort(a,low,mid);
        mergeSort(a,mid+1,high);
        merge(a,low,mid,high);
    }
}
int main(){
    int n;
    printf("Enter n : ");
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        printf("Enter num : ");
        scanf("%d",&a[i]);
    }
    mergeSort(a,0,n-1);
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    return 0;
}