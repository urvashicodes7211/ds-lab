//Write a program to find whether the array contains a duplicate number or not. 
#include<stdio.h>
int main(){
    int n,i,j;
    printf("Enter n : ");
    scanf("%d",&n);
    
    int a[n]; 

    for(i=0;i<n;i++){
        printf("Enter number : ");
        scanf("%d",&a[i]);
    }
    
    for(i=0;i<n;i++){
        for(j=i+1;j<n-1;j++){
            if(a[i] == a[j]){
                printf("the array contains a duplicate number");
            }else{
                printf("the array contains a not duplicate number");
            }
        }
    }
    return 0;
}