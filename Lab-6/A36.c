//WAP to calculate the sum of n numbers using Pointer. 

#include<stdio.h>
int main(){
    
    int n , i , sum = 0;
    
    printf("Enter n : ");
    scanf("%d",&n);

    int a[n];
    int *ptr = a;

    for(i=0;i<n;i++){
        printf("Enter number : ");
        scanf("%d", ptr+i);
    } 


    for(i=0;i<n;i++){
        sum += *(ptr+i);
    }

    printf("sum = %d",sum);

    return 0;
}