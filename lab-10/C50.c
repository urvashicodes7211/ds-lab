/* Write a program to swap two consecutive nodes in the linked list. Don’t change 
the values of nodes, implement by changing the link of the nodes. 
- Input: 1 → 2 → 3 → 4 → 5 → 6 → 7 → 8 
- Output: 2 → 1 → 4 → 3 → 6 → 5 → 8 → 7*/
#include<stdio.h>
#include<stdlib.h>

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
void twoNodeSwap(){
    if(first == NULL || first->link == NULL){
        return;
    }

    struct Node *prev = NULL;
    struct Node *curr = first;
    struct Node *next;

    first = curr->link;

    while(curr != NULL && curr->link != NULL){
        next = curr->link;

        curr->link = next->link;
        next->link = curr;

        if(prev != NULL){
            prev->link = next;
        }

        prev = curr;
        curr = curr->link;
    }
}
int main(){
    insertFront(1);
    insertFront(4);
    insertFront(2);
    insertFront(5);
    insertFront(1);
    display();
    twoNodeSwap();
    display();
    return 0;
}