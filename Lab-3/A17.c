// Write a program to calculate sum of numbers from m to n. 
#include<stdio.h>
int main(){
    int m,n,sum=0,i;
    printf("Enter m and n : ");
    scanf("%d %d",&m,&n);
    for(i=m;i<=n;i++){
        sum += i;
    }
    printf("%d",sum);
    return 0;
}