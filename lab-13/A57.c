/* Write a menu driven program to implement following operations on the Stack
   using an Array
   -> PUSH, POP, DISPLAY
   -> PEEP, CHANGE */

#include<stdio.h>

int stack[10];
int top = -1;

void push() {
    int data;

    if(top == 9){
        printf("\nStack Overflow");
        return;
    }

    printf("Enter element: ");
    scanf("%d", &data);

    top++;
    stack[top] = data;
}

void pop(){
    if(top == -1) {
        printf("\nStack Underflow");
        return;
    }

    printf("\nDeleted element = %d", stack[top]);
    top--;
}

void display() {
    if(top == -1) {
        printf("\nStack is Empty");
        return;
    }

    printf("\nStack elements are:\n");

    for(int i = top; i >= 0; i--) {
        printf("%d\n", stack[i]);
    }
}

void peep() {
    int pos;

    if(top == -1){
        printf("\nStack is Empty");
        return;
    }

    printf("Enter position from TOP: ");
    scanf("%d", &pos);

    if(pos <= 0 || pos > top + 1){
        printf("Invalid Position");
        return;
    }

    printf("Element = %d", stack[top - pos + 1]);
}

void change(){
    int pos, value;

    if(top == -1) {
        printf("\nStack is Empty");
        return;
    }

    printf("Enter position from TOP: ");
    scanf("%d", &pos);

    if(pos <= 0 || pos > top + 1){
        printf("Invalid Position");
        return;
    }

    printf("Enter new value: ");
    scanf("%d", &value);

    stack[top - pos + 1] = value;

    printf("Element Changed Successfully");
}

int main() {
    int choice;

    do {
        printf("\n\n----- STACK MENU -----");
        printf("\n1. PUSH");
        printf("\n2. POP");
        printf("\n3. DISPLAY");
        printf("\n4. PEEP");
        printf("\n5. CHANGE");
        printf("\n6. EXIT");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                push();
                break;

            case 2:
                pop();
                break;

            case 3:
                display();
                break;

            case 4:
                peep();
                break;

            case 5:
                change();
                break;

            case 6:
                printf("Program Ended");
                break;

            default:
                printf("Invalid Choice");
        }

    } while(choice != 6);

    return 0;
}