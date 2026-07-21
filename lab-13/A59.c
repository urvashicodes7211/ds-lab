/*How stack can be used to recognize strings aca, bcb, abcba, abbcbba? Write a 
program to solve the above problem. */

#include <stdio.h>
#include <string.h>

char stack[20];
int top = -1;

void push(char ch){
    top++;
    stack[top] = ch;
}

char pop(){
    char ch;
    ch = stack[top];
    top--;
    return ch;
}

int main(){
    char str[20];
    int i, len, flag = 1;

    printf("Enter String: ");
    scanf("%s", str);

    len = strlen(str);

    for(i = 0; i < len; i++){
        push(str[i]);
    }

    for(i = 0; i < len; i++){
        if(str[i] != pop()){
            flag = 0;
            break;
        }
    }

    if(flag == 1){
        printf("String is Palindrome (Recognized)");
    }else{
        printf("String is Not Palindrome");
    }
    
    return 0;
}