//WAP to find factorial of a number. (Using loop) 
#include<stdio.h>
int main(){
    int n,fac=1,i;
    printf("Enter n : ");
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        fac = fac * i;
    }
    printf("%d",fac);
    return 0;
}