// Write a program to copy a linked list. 
#include<stdio.h>
#include<stdlib.h>

struct Node {
    int info;
    struct Node *link;
};
struct Node *first = NULL;
struct Node *copyFirst = NULL;

void insertFront(int x){
    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    if(newNode == NULL){
        printf("Memory Allocation Failed\n");
        return;
    }

    newNode->info = x;

    newNode->link = first;

    first = newNode;
}
void display(){
    struct Node *temp = first;

    if (first == NULL){
        printf("Linked List is Empty.\n");
        return;
    }

    printf("Linked List: ");

    while (temp != NULL){
        printf("%d -> ", temp->info);
        temp = temp->link;
    }

    printf("NULL\n");
}
void copyList(){
    struct Node *temp = first;
    struct Node *newNode, *last = NULL;

    while(temp != NULL){
        newNode = (struct Node *)malloc(sizeof(struct Node));

        newNode->info = temp->info;
        newNode->link = NULL;

        if(copyFirst == NULL){
            copyFirst = newNode;
            last = newNode;
        }else{
            last->link = newNode;
            last = newNode;
        }

        temp = temp->link;
    }
}
void displayCopy(){
    struct Node *temp = copyFirst;

    while(temp != NULL){
        printf("%d -> ", temp->info);
        temp = temp->link;
    }

    printf("NULL\n");
}
int main(){
    insertFront(5);
    insertFront(4);
    insertFront(3);
    insertFront(2);
    insertFront(1);
    display();

    copyList();
    displayCopy();
    return 0;
}