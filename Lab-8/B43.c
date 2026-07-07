// WAP to check whether 2 singly linked lists are same or not.
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int info;
    struct Node *link;
};
struct Node *first = NULL;
struct Node *first1 = NULL;

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
void insertFront1(int x){
    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    if(newNode == NULL){
        printf("Memory Allocation Failed\n");
        return;
    }

    newNode->info = x;

    newNode->link = first1;

    first1 = newNode;
}
void display1(){
    struct Node *temp = first1;

    if (first1 == NULL){
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
int main() {

    insertFront(4);
    insertFront(2);
    insertFront(1);
    insertFront(3);
    display();

    insertFront1(3);
    insertFront1(2);
    insertFront1(1);
    display1();

    struct Node *save = first;
    struct Node *save1 = first1;


    while(save != NULL && save1 != NULL){
        if(save->info != save1->info){
            printf("Both Linked Lists are NOT Same.\n");
            return 0;
        }else{
            save=save->link;
            save1=save1->link;
        }
    }
    if (save == NULL && save1 == NULL) {
        printf("Both Linked Lists are Same.\n");
    } else {
        printf("Both Linked Lists are NOT Same.\n");
    }
    return 0;
}