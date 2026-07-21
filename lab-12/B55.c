// WAP to delete alternate nodes of a doubly linked list.

#include<stdio.h>
#include<stdlib.h>

struct Node{
    int info;
    struct Node *lptr;
    struct Node *rptr;
};

struct Node *first = NULL;
struct Node *last = NULL;

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
void deleteNode(){
    struct Node *temp = first;

    if(first == NULL){
        printf("List is Empty.\n");
        return;
    }

    while(temp != NULL && temp->rptr != NULL){
        struct Node *del = temp->rptr;

        temp->rptr = del->rptr;

        if(del->rptr != NULL){
            del->rptr->lptr = temp;
        }
        else{
            last = temp;
        }

        free(del);

        temp = temp->rptr;
    }
}

int main(){
    insertAtEnd(1);
    insertAtEnd(2);
    insertAtEnd(3);
    insertAtEnd(4);
    insertAtEnd(5);

    display();
    deleteNode();
    display();

    return 0;
}