/*You are given a string s, which contains stars *. In one operation, you can: 
Choose a star in s. Remove the closest non-star character to its left, as well as 
remove the star itself. Return the string after all stars have been removed. 
 
Note :  
 The input will be generated such that the operation is always possible. 
 It can be shown that the resulting string will always be unique. 
 
Sample Example-1: 
Input: s = "leet**cod*e".             
Output: "lecoe" 
 
Sample Example-2: 
Input: s = "erase*****"     
Output: ""*/

#include <stdio.h>
#include <string.h>

int main() {
    char s[1000];
    char stack[1000];
    int top = -1;

    printf("Enter string: ");
    scanf("%s", s);

    for (int i = 0; s[i] != '\0'; i++){
        if (s[i] == '*') {
            if (top != -1){
                top--;  
            }      
        } else {
            stack[++top] = s[i]; 
        }
    }

    stack[top + 1] = '\0';

    printf("Output: %s\n", stack);

    return 0;
}