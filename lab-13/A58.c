// Write a program to implement stack using singly linked list.

#include<stdio.h>
#include<stdlib.h>

struct Node{
    int info;
    struct Node *link;
};

struct Node *first = NULL;

void push(){
    int x;
    struct Node *newNode;

    printf("Enter element: ");
    scanf("%d",&x);

    newNode = (struct Node *)malloc(sizeof(struct Node));

    if(newNode == NULL){
        printf("Memory Allocation Failed\n");
        return;
    }

    newNode->info = x;
    newNode->link = first;
    first = newNode;

    printf("Element Pushed\n");
}

void pop(){
    struct Node *temp;

    if(first == NULL){
        printf("Stack Underflow\n");
        return;
    }

    temp = first;
    printf("Deleted Element = %d\n",temp->info);

    first = first->link;
    free(temp);
}

void display(){
    struct Node *temp;

    if(first == NULL){
        printf("Stack is Empty\n");
        return;
    }

    temp = first;

    printf("Stack:\n");

    while(temp != NULL){
        printf("%d\n",temp->info);
        temp = temp->link;
    }
}

void peep(){
    int pos,i;
    struct Node *temp;

    if(first == NULL){
        printf("Stack is Empty\n");
        return;
    }

    printf("Enter Position from Top: ");
    scanf("%d",&pos);

    temp = first;

    for(i=1;i<pos && temp!=NULL;i++){
        temp = temp->link;
    }

    if(temp == NULL){
        printf("Invalid Position\n");
    }
    else{
        printf("Element = %d\n",temp->info);
    }
}

void change(){
    int pos,value,i;
    struct Node *temp;

    if(first == NULL){
        printf("Stack is Empty\n");
        return;
    }

    printf("Enter Position from Top: ");
    scanf("%d",&pos);

    printf("Enter New Value: ");
    scanf("%d",&value);

    temp = first;

    for(i=1;i<pos && temp!=NULL;i++){
        temp = temp->link;
    }

    if(temp == NULL){
        printf("Invalid Position\n");
    }
    else{
        temp->info = value;
        printf("Element Changed Successfully\n");
    }
}

int main(){
    int choice;

    do{
        printf("\n----- STACK MENU -----");
        printf("\n1. PUSH");
        printf("\n2. POP");
        printf("\n3. DISPLAY");
        printf("\n4. PEEP");
        printf("\n5. CHANGE");
        printf("\n6. EXIT");

        printf("\nEnter your choice: ");
        scanf("%d",&choice);

        switch(choice){

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
                printf("Program Ended\n");
                break;

            default:
                printf("Invalid Choice\n");
        }

    }while(choice != 6);

    return 0;
}