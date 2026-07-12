/*WAP to perform given operation in the linked list. There exist a Linked List. Add 
a node that contains the GCD of those two nodes between every pair adjacent 
node of Linked List.*/
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
int gcd(int a, int b){
    while(b != 0){
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
void insertGCD(){

    struct Node *temp = first;

    while(temp != NULL && temp->link != NULL){

        int g = gcd(temp->info, temp->link->info);

        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

        newNode->info = g;

        newNode->link = temp->link;

        temp->link = newNode;

        temp = newNode->link;
    }
}

int main(){
    insertFront(12);
    insertFront(4);
    insertFront(24);
    insertFront(15);
    insertFront(10);
    display();
    insertGCD();
    display();
    return 0;
} 