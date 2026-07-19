/*Write a menu driven program to implement following operations on the circular 
linked list. 
-> Insert a node at the front of the linked list. 
-> Delete a node from specified position. 
-> Insert a node at the end of the linked list. 
-> Display all nodes. */

#include<stdio.h>
#include<stdlib.h>

struct Node{
    int info;
    struct Node *link;
};
struct Node *first = NULL;
struct Node *last = NULL;


void insertAtFront(int x){
    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->info = x;
    if(first == NULL){
        first = last = newNode;
        last->link = first;
    }else{
        newNode -> link =first;
        first=newNode;
        last->link=first;
    }
}
// void deletePos(int x){
//     struct Node *save;
//     struct Node *prd = NULL;

//     save = first;
    
//     while(save!=NULL && save->info != x){
//         prd = save;
//         if(save->info == x){
//             prd->link = save->link;
//             free(save);
//         }
//     }
// }
void deletePos(int x){
    struct Node *save = first;
    struct Node *prd = last;

    if(first == NULL){
        printf("List is Empty\n");
        return;
    }

    while(save->info != x){
        if(save == last){
            printf("Node Not Found\n");
            return;
        }
        prd = save;
        save = save->link;
    }

    if(save == first){
        first = first->link;
        last->link = first;
    }
    else if(save == last){
        prd->link = first;
        last = prd;
    }
    else{
        prd->link = save->link;
    }

    free(save);
}
void insertAtEnd(int x){
    struct Node *newNode;
    

    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->info = x;
    if(first == NULL){
        first = last = newNode;
        last->link = first;
    }else{
         last->link = newNode;
        newNode->link = first;
        last = newNode;
    }
}
void display(){
    struct Node *save;

    if(first == NULL){
        printf("List is Empty");
        return;
    }

    save = first ; 
    while(save->link != first){
        printf("%d -> ",save->info);
        save=save->link;
    }
     printf("%d -> ", save->info);
     printf("FIRST\n");
}
int main(){
    insertAtFront(2);
    insertAtFront(3);
    insertAtFront(4);
    insertAtFront(5);
    deletePos(2);
    insertAtEnd(1);
    display();
    
    return 0;
}