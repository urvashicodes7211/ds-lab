//WAP to print Pascal triangle. 
#include<stdio.h>
int main(){
    int n,i,j;
    printf("Enter n: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        for(j=0;j<n-i-1;j++){
            printf(" ");
        }
        long num = 1;
        for(j=0;j<=i;j++){
            printf("%3ld",num);
            num = num * (i-j)/(j+1);
        }
        printf("\n");
    }
    return 0;
}