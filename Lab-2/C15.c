//WAP to print Armstrong number from 1 to 1000.
#include <stdio.h>
int main(){
    int num,temp,rem,sum;

    for(num = 1; num <= 1000; num++){
        temp = num;
        sum = 0;

        while(temp > 0){
            rem = temp % 10;
            sum = sum + (rem * rem * rem);
            temp = temp / 10;
        }

        if(sum == num){
            printf("%d ", num);
        }
    }
    return 0;
}