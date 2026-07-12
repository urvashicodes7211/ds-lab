// Write a program to sort elements of a linked list. 
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
int main(){
    insertFront(1);
    insertFront(4);
    insertFront(2);
    insertFront(5);
    insertFront(1);
    display();
    struct Node *save;
    struct Node *prd;
    int temp;

    for(prd = first; prd != NULL; prd = prd->link){
        save = prd->link;

        while(save != NULL){
            if(prd->info > save->info){
                temp = prd->info;
                prd->info = save->info;
                save->info = temp;
            }
            save = save->link;
        }
    }
    display();
    return 0;
}