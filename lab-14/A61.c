/*Chef has a string which contains only the characters '{', '}', '[', ']', '(' and ')'.  
Now Chef wants to know if the given string is balanced or not.  
If is balanced then print 1, otherwise print 0.  
A balanced parenthesis string is defined as follows: 
 The empty string is balanced 
 If P is balanced then (P), {P}, [P] is also balanced 
 if P and Q are balanced PQ is also balanced 
 "([])", "({})[()]" are balanced parenthesis strings  
 "([{]})", "())" are not balanced.*/

#include<stdio.h>
#include <string.h>

char stack[10];
int top = -1;

void push(char ch){
    stack[++top] = ch;
}

char pop(){
    if (top == -1)
        return '\0';
    return stack[top--];
}


int main(){
    char str[100];
    int i;

    printf("Enter string: ");
    scanf("%s", str);

    for (i = 0; str[i] != '\0'; i++){
        char ch = str[i];

        if (ch == '(' || ch == '{' || ch == '['){
            push(ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']'){
            char temp = pop();

            if ((ch == ')' && temp != '(') ||
                (ch == '}' && temp != '{') ||
                (ch == ']' && temp != '[')){
                printf("0");
                return 0;
            }
        }
    }
    if (top == -1){
        printf("1");
    }else{
        printf("0");
    }

    return 0;
}