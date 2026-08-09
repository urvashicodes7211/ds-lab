/* You have an array A of integers of size N, an array B (initially empty) and a stack 
S (initially empty). You are allowed to do the following operations: 
 
 Take the first element of array A and push it into S and remove it from A. 
 Take the top element from stack S, append it to the end of array B and 
remove it from S. 
 
You have to tell if it possible to move all the elements of array A to array B using 
the above operations such that finally the array B is sorted in ascending order. 
 
Input Format : 
 First line will contain T, number of testcases. Then the testcases follow. 
 First line of each testcase contains a single integer N. 
 Second line of each testcase contains N distinct integers : A1,A2...AN. 
 
Output Format : 
For each testcase, if it possible to move all the elements of array A to array B 
using the above operations such that finally, the array B is sorted in ascending 
order, print "YES" (without quotes), else print "NO" (without quotes). */

#include <stdio.h>

int main(){
    int T;
    scanf("%d", &T);

    while (T--){
        int N;
        scanf("%d", &N);

        int A[N], S[N];
        int top = -1;

        for (int i = 0; i < N; i++){
            scanf("%d", &A[i]);
        }

        int sorted[N];

        for (int i = 0; i < N; i++){
            sorted[i] = A[i];
        }

        for (int i = 0; i < N - 1; i++){
            for (int j = i + 1; j < N; j++){
                if (sorted[i] > sorted[j]){
                    int temp = sorted[i];
                    sorted[i] = sorted[j];
                    sorted[j] = temp;
                }
            }
        }

        int j = 0;

        for (int i = 0; i < N; i++){
            S[++top] = A[i];

            while (top >= 0 && S[top] == sorted[j]){
                top--;
                j++;

                if (j == N)
                    break;
            }
        }

        if (top == -1 && j == N)
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}