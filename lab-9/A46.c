// Write a program to reverse a linked list. 
#include <stdio.h>
#include <stdlib.h>

struct Node{
    int info;
    struct Node *link;
};

struct Node *first = NULL;
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
int main(){
    insertFront(5);
    insertFront(4);
    insertFront(3);
    insertFront(2);
    insertFront(1);
    display();
    struct Node *prd = NULL;
    struct Node *current = first;
    struct Node *next = NULL;

    while(current != NULL){
        next  = current -> link;
        current -> link = prd;
        prd = current;
        current = next ;
    }
    first = prd ;
    display();
    return 0;
}