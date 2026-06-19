/*Write  a  program  to  find position  of the  smallest number  & the  largest  number 
from given n numbers. */
#include<stdio.h>
int main(){
    int n,i;
    printf("Enter n : ");
    scanf("%d",&n);
    int a[n],sm = a[0] , lg = a[0] , temp1 = 0, temp2 = 0;
    for(i=0;i<n;i++){
        printf("Enter number : ");
        scanf("%d",&a[i]);
    }
    for(i=1;i<=n;i++){
        if(a[i]<sm){
            sm = a[i];
            temp1 = i;
        }
        if(a[i]>lg){
            lg = a[i];
            temp2 = i;
        }
    }

    printf("smallest number of position: %d\n",temp1);
    printf("largest number of position: %d",temp2);

    return 0;
}