//WAP to sort the array elements using Pointer.

#include<stdio.h>
int main(){
    int n , i , j , temp;
    
    printf("Enter n : ");
    scanf("%d",&n);

    int a[n];
    int *ptr = a;

    for(i=0;i<n;i++){
        printf("Enter number : ");
        scanf("%d", ptr+i);
    }

    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
            if(*(ptr+i) > *(ptr+j)){
                temp = *(ptr+i);
                *(ptr+i) = *(ptr+j);
                *(ptr+j) = temp;
            }
        }
    }

    for(i=0;i<n;i++){
        printf("%d\n",*(ptr+i));
    }

    return 0;
}