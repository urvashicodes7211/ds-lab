// WAP to reverse a number.
#include<stdio.h>
int main(){
    int n,m,rev=0;
    printf("Enter n : ");
    scanf("%d",&n);
    while(n>0){
        m = n % 10;
        rev = (rev * 10) + m;
        n = n / 10;
    }
    printf("%d",rev);
    return 0;
}