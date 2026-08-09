// Write a program for evaluation of prefix Expression using Stack.

#include <stdio.h>
#include <ctype.h>
#include <string.h>

int stack[100];
int top = -1;

void push(int x){
    stack[++top] = x;
}

int pop(){
    return stack[top--];
}

int main(){
    char prefix[100];
    int i, a, b, result;

    printf("Enter prefix expression: ");
    scanf("%s", prefix);

    for (i = strlen(prefix) - 1; i >= 0; i--){
        if (isdigit(prefix[i])){
            push(prefix[i] - '0');
        }
        else{
            a = pop();
            b = pop();

            switch (prefix[i]){
                case '+':
                    result = a + b;
                    break;

                case '-':
                    result = a - b;
                    break;

                case '*':
                    result = a * b;
                    break;

                case '/':
                    result = a / b;
                    break;

                case '%':
                    result = a % b;
                    break;
            }

            push(result);
        }
    }

    printf("Result = %d\n", pop());

    return 0;
}