//WAP to get and print the array elements using Pointer.

#include<stdio.h>
int main(){
    int n,i;
    printf("Enter n : ");
    scanf("%d",&n);

    int a[n];
    int *ptr;
    ptr = a;

    for(i=0;i<n;i++){
        printf("Enter number : ");
        scanf("%d",ptr);
        ptr++;
    } 

    ptr = a;

    for(i=0;i<n;i++){
        printf("%d\n",*ptr);
        ptr++;
    }

    return 0;
}