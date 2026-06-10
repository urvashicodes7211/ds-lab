//WAP to check whether a number is prime or not.
#include<stdio.h>
int main(){
    int n,c=0,i;
    printf("Enter n : ");
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        if(n % i == 0){
            c++;
        }
    }
    if(c == 2){
        printf("prime");
    }else{
        printf("Not prime");
    }
    return 0;
}