// Write a program to copy a linked list. 
#include<stdio.h>
#include<stdlib.h>

struct Node {
    int info;
    struct Node *link;
};
struct Node *first = NULL;

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
void insertEnd(int x){
    struct Node *newNode;
    struct Node *save;

    newNode = (struct Node *)malloc(sizeof(struct Node));
    if(newNode == NULL){
        printf("Memory Allocation Failed\n");
        return;
    }

    newNode->info = x;
    newNode->link = NULL;

    if(first == NULL){
        first = newNode;
    }else{
        save = first;

        while(save->link != NULL){
            save = save->link;
        }

        save->link = newNode;
    }
}
void copyList(){
    struct Node *save = first;

    while(save != NULL){
        insertEnd(save->info);
        save = save->link;
    }
}
void displayCopy(){
    struct Node *save = first;

    printf("Copied List: ");

    while(save != NULL){
        printf("%d -> ", save->info);
        save = save->link;
    }

    printf("NULL\n");
}
int main(){
    insertEnd(5);
    insertEnd(4);
    insertEnd(3);
    insertEnd(2);
    insertEnd(1);
    display();

    copyList();
    displayCopy();
    return 0;
}