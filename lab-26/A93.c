// Write a program to implement Insertion Sort using Array.

#include<stdio.h>
int main(){
    int n;
    printf("Enter n : ");
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        printf("Enter num : ");
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n;i++){
        int key = a[i];
        int j=i-1;
        while(j>=0 && a[j]>key){
            a[j+1] = a[j];
            j = j - 1;
        }
        a[j+1] = key;
    }
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    return 0;
}