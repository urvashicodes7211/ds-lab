/* Read  n  numbers  in  an  array  then  read  two  different  numbers,  replace  1st 
number with 2nd number in an array and print its index and final array. */
#include<stdio.h>
int main(){
    int n,i;
    printf("Enter n : ");
    scanf("%d",&n);
    int a[n];

    for(i=0;i<n;i++){
        printf("Enter number : ");
        scanf("%d",&a[i]);
    }

    int n1,n2;
    printf("Enter two number : ");
    scanf("%d %d",&n1,&n2);

    for(i=0;i<n;i++){
        if(a[i] == n1){
            n2 = a[i];
            printf("index : %d\n",i);
        }
    }
    for(i=0;i<n;i++){
        printf("%d\n",a[i]);
    }
    return 0;
}