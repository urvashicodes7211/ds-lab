// WAP to find the sum of 1 + (1+2) + (1+2+3) + (1+2+3+4)+ ...+(1+2+3+4+....+n).
#include<stdio.h>
int main(){
    int n,sum=0,i,j;
    printf("Enter n : ");
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        for(j=1;j<=i;j++){
            sum=sum+j;
        }
    }
    printf("%d",sum);
    return 0;
}