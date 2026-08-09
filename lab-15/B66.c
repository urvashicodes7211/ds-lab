//Write a program to convert infix notation to prefix notation using stack. 

#include <stdio.h>
#include <ctype.h>
#include <string.h>

char stack[100];
int top = -1;

void push(char x){
    stack[++top] = x;
}

char pop(){
    return stack[top--];
}

int priority(char x){
    if (x == '+' || x == '-')
        return 1;

    if (x == '*' || x == '/')
        return 2;

    if (x == '^')
        return 3;

    return 0;
}

int main(){
    char infix[100], prefix[100];
    int i, j = 0;
    char ch;

    printf("Enter infix expression: ");
    scanf("%s", infix);

    strrev(infix);

    for (i = 0; infix[i] != '\0'; i++){
        ch = infix[i];

        if (ch == '(')
            ch = ')';
        else if (ch == ')')
            ch = '(';

        if (isalnum(ch)){
            prefix[j++] = ch;
        }

        else if (ch == '('){
            push(ch);
        }

        else if (ch == ')'){
            while (top != -1 && stack[top] != '('){
                prefix[j++] = pop();
            }

            pop();
        }

        else{
            while (top != -1 && priority(stack[top]) > priority(ch)){
                prefix[j++] = pop();
            }

            push(ch);
        }
    }

    while (top != -1){
        prefix[j++] = pop();
    }

    prefix[j] = '\0';

    strrev(prefix);

    printf("Prefix expression: %s\n", prefix);

    return 0;
}

