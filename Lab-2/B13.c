// WAP to print prime numbers between given interval.
#include<stdio.h>
int main(){
    int n1 ,n2 ,i,j;
    printf("Enter n1 and n2 : ");
    scanf("%d %d",&n1,&n2);
    for(i=n1;i<=n2;i++){
        int c=0;
        for(j=1;j<=i;j++){
            if(i%j==0){
                c++;
            }
        }
        if(c == 2){
            printf("%d\n",i);
        }
    }
    return 0;
}