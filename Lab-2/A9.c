//WAP to find power of a number using loop.
#include<stdio.h>
int main(){
    int x,y,i,p=1;
    printf("Enter x and y : ");
    scanf("%d %d",&x,&y);
    for(i=1;i<=y;i++){
        p = p * x ;
    }
    printf("%d",p);
    return 0;
}