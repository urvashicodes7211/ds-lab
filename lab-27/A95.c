// Write a program to implement Quick Sort using Array.

#include<stdio.h>
void quickSort(int a[],int low,int high){
    int flag = 1;
    if(low<high){
        int i = low;
        int j = high+1;
        int pivot = a[low];
        while(flag){
            i = i + 1;
            while(a[i] <= pivot && i < high){
                i = i + 1;
            }
            j = j - 1;
            while(a[j] > pivot){
                j = j -1 ;  
            }
            if(i<j){
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }else{
                flag = 0;
            }
        }
        int temp = a[j];
        a[j] = a[low];
        a[low] = temp;

        quickSort(a, low, j - 1);
        quickSort(a, j + 1, high);
    }
}
int main(){
    int n;
    printf("Enter n : ");
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        printf("Enter num : ");
        scanf("%d",&a[i]);
    }

    quickSort(a, 0, n - 1);

    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    return 0;
}