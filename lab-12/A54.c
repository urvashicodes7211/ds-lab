/* Write a menu driven program to implement following operations on the doubly 
linked list. 
-> Insert a node at the front of the linked list. 
-> Delete a node from specified position. 
-> Insert a node at the end of the linked list. 
-> Display all nodes. */

#include<stdio.h>
#include<stdlib.h>

struct Node{
    int info;
    struct Node *lptr;
    struct Node *rptr;
};

struct Node *first = NULL;
struct Node *last = NULL;

void insertAtFront(int x){
    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->info = x;

    newNode->lptr = NULL;
    newNode->rptr = first;

    if(first == NULL){
        first = last = newNode;
    }
    else{
        first->lptr = newNode;
        first = newNode;
    }
}
void deletePos(int pos){
    struct Node *save;
    int i;

    if(first == NULL){
        printf("List is Empty.\n");
        return;
    }

    save = first;

    for(i=1;i<pos && save!=NULL;i++){
        save = save->rptr;
    }

    if(save == NULL){
        printf("Invalid Position.\n");
        return;
    }

    if(first == last){
        first = last = NULL;
    }
    else if(save == first){
        first = first->rptr;
        first->lptr = NULL;
    }
    else if(save == last){
        last = last->lptr;
        last->rptr = NULL;
    }
    else{
        save->lptr->rptr = save->rptr;
        save->rptr->lptr = save->lptr;
    }

    free(save);
    printf("Node Deleted.\n");
}

void insertAtEnd(int x){
    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->info = x;

    newNode->rptr = NULL;

    if(first == NULL){
        newNode->lptr = NULL;
        first = last = newNode;
    }
    else{
        newNode->lptr = last;
        last->rptr = newNode;
        last = newNode;
    }
}
void display(){
    struct Node *save;

    if(first == NULL){
        printf("List is Empty.\n");
        return;
    }

    save = first;

    while(save != NULL){
        printf("%d -> ",save->info);
        save = save->rptr;
    }

    printf("\n");
}
int main(){
    insertAtFront(1);
    insertAtFront(2);
    insertAtFront(3);
    deletePos(2);
    insertAtEnd(4);
    insertAtEnd(5);
    display();
    return 0;
}