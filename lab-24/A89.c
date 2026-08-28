//Write a program to implement a Linear Search using Array.

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

    int value;

    printf("Enter value : ");
    scanf("%d",&value);

    for(int i=0;i<n;i++){
        if(a[i] == value){
            printf("%d",i);
            break;
        }
        if(i == n-1){
            printf("Value not found");
        }
    }
    return 0;
}