/* Write a program to implement a Binary Search using Array. (Iterative & 
recursive)*/

#include<stdio.h>

int recursiveSearch(int a[], int first, int last, int value){
    if(first > last){
        return -1;
    }

    int mid = (first + last) / 2;

    if(a[mid] == value){
        return mid;
    }
    else if(value < a[mid]){
        return recursiveSearch(a, first, mid - 1, value);
    }
    else{
        return recursiveSearch(a, mid + 1, last, value);
    }
}

int iterativeSearch(int a[], int n, int value){
    int first = 0;
    int last = n - 1;

    while(first <= last){
        int mid = (first + last) / 2;

        if(a[mid] == value){
            return mid;
        }
        else if(value < a[mid]){
            last = mid - 1;
        }
        else{
            first = mid + 1;
        }
    }

    return -1;
}

int main(){
    int n;

    printf("Enter n : ");
    scanf("%d", &n);

    int a[n];

    printf("Enter sorted array :\n");

    for(int i = 0; i < n; i++){
        printf("Enter num : ");
        scanf("%d", &a[i]);
    }

    int value;

    printf("Enter value : ");
    scanf("%d", &value);

    int result = iterativeSearch(a, n, value);

    if(result != -1){
        printf("\nIterative Search : Value found at index %d\n", result);
    }
    else{
        printf("\nIterative Search : Value not found\n");
    }

    result = recursiveSearch(a, 0, n - 1, value);

    if(result != -1){
        printf("Recursive Search : Value found at index %d\n", result);
    }
    else{
        printf("Recursive Search : Value not found\n");
    }

    return 0;
}