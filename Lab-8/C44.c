/* Write a program to remove the duplicates nodes from given sorted Linked List. 
- Input: 1 → 1 → 6 → 13 → 13 → 13 → 27 → 27 
- Output: 1 → 6 → 13 → 27 */

#include <stdio.h>
#include <stdlib.h>

struct Node {
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

void removeDuplicate(){
    struct Node *current = first;
    struct Node *next;

    while (current != NULL && current->link != NULL){
        if (current->info == current->link->info){
            next = current->link;
            current->link = next->link;
            free(next);
        }
        else{
            current = current->link;
        }
    }
}

int main(){
    insertFront(27);
    insertFront(27);
    insertFront(13);
    insertFront(13);
    insertFront(13);
    insertFront(6);
    insertFront(1);
    insertFront(1);

    display();

    removeDuplicate();

    display();

    return 0;
}