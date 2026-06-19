//Write a program to read and display n numbers using an array. 
#include<stdio.h>
int main(){
    int n,i;
    printf("Enter n : ");
    scanf("%d",&n);
    int a[n];

    for(i=0;i<n;i++){
        printf("Enter number : ");
        scanf("%d",&a[i]);
    }

    for(i=0;i<n;i++){
        printf("%d\n",a[i]);
    }
    return 0;
}