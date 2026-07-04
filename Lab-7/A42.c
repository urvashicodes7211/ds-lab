/* Write a menu driven program to implement following operations on the singly 
linked list.  
-> Insert a node at the front of the linked list. 
-> Display all nodes. 
-> Delete a first node of the linked list. 
-> Insert a node at the end of the linked list. 
-> Delete a last node of the linked list. 
-> Delete a node from specified position. 
-> Count the no. of nodes in the linked list. */


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

void deleteFront(){

    struct Node *save;

    if(first == NULL){
        printf("List is Empty\n");
        return;
    }

    save = first;          
    first = first->link;   
    free(save);            

    printf("First node deleted\n");
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

void deleteEnd(){
    struct Node *save, *prd;

    if(first == NULL){
        printf("List is empty\n");
        return;
    }

    if(first->link == NULL){
        free(first);
        first = NULL;
        printf("Last node deleted\n");
        return;
    }

    save = first;

    while(save->link != NULL){
        prd = save;
        save = save->link;
    }

    prd->link = NULL;
    free(save);

    printf("Last node deleted\n");
}

void deletePosition(int pos){
    struct Node *save, *temp;
    int i;

    if(first == NULL){
        printf("List is empty\n");
        return;
    }

    if(pos == 1){
        save = first;
        first = first->link;
        free(save);
        printf("Node deleted\n");
        return;
    }

    save = first;

    for(i = 1; i < pos - 1 && save != NULL; i++){
        save = save->link;
    }

    if(save == NULL || save->link == NULL){
        printf("Invalid Position\n");
        return;
    }

    temp = save->link;
    save->link = temp->link;
    free(temp);

    printf("Node deleted\n");
}

void countNodes(){
    struct Node *save;
    int count = 0;

    save = first;

    while(save != NULL){
        count++;
        save = save->link;
    }

    printf("Total Nodes = %d\n", count);
}

int main(){
    int choice;

    while (1){
        printf("\n------ MENU ------\n");
        printf("1. Insert at Front\n");
        printf("2. Display\n");
        printf("3. Delete First\n");
        printf("4. Insert at End\n");
        printf("5. Delete Last\n");
        printf("6. Delete from Position\n");
        printf("7. Count Nodes\n");
        printf("8. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice){
        case 1:{
            int x;
            printf("Enter value: ");
            scanf("%d", &x);

            insertFront(x);
            break;
        }
        case 2:
            display();
            break;

        case 3:
            deleteFront();
            break;

        case 4:{
            int x;
            printf("Enter value : ");
            scanf("%d", &x);

            insertEnd(x);
            break;
        }

        case 5:
            deleteEnd();
            break;

        case 6:{
            int pos;
            printf("Enter position : ");
            scanf("%d", &pos);

            deletePosition(pos);
            break;
        }

        case 7:
            countNodes();
            break;

        case 8:
            printf("Program End.\n");
            exit(0);

        default:
            printf("Invalid Choice.\n");
        }
    }

    return 0;
}