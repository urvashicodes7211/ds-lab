/*Given a set of time intervals in any order, our task is to merge all overlapping 
intervals into one and output the result which should have only mutually 
exclusive intervals. 
 
Sample Example-1: 
Input: Intervals = {{1,3},{2,4},{6,8},{9,10}} 
Output: {{1, 4}, {6, 8}, {9, 10}} 
Explanation: Given intervals: [1,3],[2,4],[6,8],[9,10], we have only two overlapping 
intervals here,[1,3] and [2,4]. Therefore we will merge these two and return [1,4],[6,8], 
[9,10] 
 
Sample Example-2: 
Input: Intervals = {{6,8},{1,9},{2,4},{4,7}} 
Output: {{1, 9}} */

#include <stdio.h>

struct Interval{
    int start;
    int end;
};

void sortIntervals(struct Interval arr[], int n){
    int i, j;
    struct Interval temp;

    for(i = 0; i < n - 1; i++){
        for(j = i + 1; j < n; j++){
            if(arr[i].start > arr[j].start){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void mergeIntervals(struct Interval arr[], int n){
    int i;

    sortIntervals(arr, n);

    struct Interval result[n];
    int index = 0;

    result[0] = arr[0];

    for(i = 1; i < n; i++){
        if(arr[i].start <= result[index].end){
            if(arr[i].end > result[index].end)
                result[index].end = arr[i].end;
        }
        else{
            index++;
            result[index] = arr[i];
        }
    }

    printf("\nMerged Intervals:\n");
    for(i = 0; i <= index; i++){
        printf("{%d,%d} ", result[i].start, result[i].end);
    }
    printf("\n");
}

int main(){
    int n, i;

    printf("Enter number of intervals: ");
    scanf("%d", &n);

    struct Interval arr[n];

    printf("Enter intervals (start end):\n");
    for(i = 0; i < n; i++){
        scanf("%d %d", &arr[i].start, &arr[i].end);
    }

    mergeIntervals(arr, n);

    return 0;
}