//WAP to find factorial of a number. (Using recursion) 
#include<stdio.h>
int fac(int);
int main(){
    int n,f;
    printf("Enter n :");
    scanf("%d",&n);
    f = fac(n);
    printf("%d",f);
    return 0;
}
int fac(int n){
    if(n == 0 || n == 1){
        return 1;
    }else{
        return n * fac(n-1);
    }
}