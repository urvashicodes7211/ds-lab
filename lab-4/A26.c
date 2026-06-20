/*Write  a  program  to  insert  a  number  in  an  array  that  is  already  sorted  in  an 
ascending order. */

#include<stdio.h>
int main(){
    int n,num,i,pos;

    printf("Enter n : ");
    scanf("%d",&n);

    int a[n+1];

    for(i=0 ; i<n ; i++){
        printf("Enter number : ");
        scanf("%d",&a[i]);
    }

    printf("Enter num : ");
    scanf("%d",&num);

    pos = n;

    for(i=0;i<n;i++){
        if(num < a[i]){
            pos = i;
            break;
        }
    }

    for(i=n;i>pos;i--){
        a[i] = a[i-1];
    }

    a[pos] = num;
    n=n+1;

    for(i=0;i<n;i++){
        printf("%d\n",a[i]);
    }
    
    return 0;
}