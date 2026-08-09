// Write a program for evaluation of postfix Expression using Stack.
#include <stdio.h>
#include <ctype.h>

int stack[100];
int top = -1;

void push(int x){
    stack[++top] = x;
}

int pop(){
    return stack[top--];
}

int main(){
    char postfix[100];
    int i, a, b, result;

    printf("Enter postfix expression: ");
    scanf("%s", postfix);

    for (i = 0; postfix[i] != '\0'; i++){
        if (isdigit(postfix[i])){
            push(postfix[i] - '0');
        }
        else{
            b = pop();
            a = pop();

            switch (postfix[i]){
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