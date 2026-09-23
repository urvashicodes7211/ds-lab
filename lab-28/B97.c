/*You  are  given  an  array  of  positive  integers  and  an  integer  K. Find  the  length  of 
the longest subarray such that the sum of the subarray is less than or equal to K.*/

#include<stdio.h>
int main(){
    int n;
    printf("Enter n : ");
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        printf("Enter num : ");
        scanf("%d",&a[i]);
    }
    int k;
    printf("Enter k : ");
    scanf("%d",&k);
    int m=0,b[m],sum=0;
    for(int i=0;i<n;i++){
        sum =sum + a[i];
        if(sum <= k){
            b[m] = a[i];
            m++;
        }else{
            break;
        }
    }
    for(int i=0;i<m;i++){
        printf("%d ",b[i]);
    }
    return 0;
}