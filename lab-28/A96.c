/*Given  an  array  nums  with  n  objects  colored  red,  white,  or  blue,  sort  them  in-
place so that objects of the same color are adjacent, with the colors in the order 
red,  white,  and  blue.  We  will  use  the  integers  0,  1,  and  2  to  represent  the  color 
red, white, and blue, respectively. 
Sample Example-1: 
Input: nums = [2,0,2,1,1,0]    
Output: [0,0,1,1,2,2] 
Sample Example-2: 
Input: nums = [2,0,1]    
Output: [0,1,2]*/

#include<stdio.h>
int main(){
    int n;
    printf("Enter n : ");
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        printf("Enter num (red=0,white=1,blue=2): ");
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(a[i] > a[j]){
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    return 0;
}