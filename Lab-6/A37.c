//WAP to find the largest element in the array using Pointer. 

#include<stdio.h>
int main(){
    int n , i;
    
    printf("Enter n : ");
    scanf("%d",&n);

    int a[n];
    int *ptr = a;

    for(i=0;i<n;i++){
        printf("Enter number : ");
        scanf("%d", ptr+i);
    } 
    
    int lar = *ptr;

    for(i=0;i<n;i++){
        if(*(ptr+i) > lar){
            lar = *(ptr+i) ;
        }
    }

    printf("the largest element : %d",lar);

    return 0;

}