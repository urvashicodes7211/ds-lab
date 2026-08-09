//Write a program to implement queue using singly linked list. 
#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

void enqueue(int value){
    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = NULL;

    if (front == NULL){
        front = rear = newNode;
    }
    else{
        rear->next = newNode;
        rear = newNode;
    }

    printf("%d inserted into queue\n", value);
}

void dequeue(){
    struct Node *temp;

    if (front == NULL){
        printf("Queue is empty\n");
        return;
    }

    temp = front;
    printf("%d deleted from queue\n", front->data);

    front = front->next;
    free(temp);

    if (front == NULL)
        rear = NULL;
}

void display(){
    struct Node *temp;

    if (front == NULL){
        printf("Queue is empty\n");
        return;
    }

    temp = front;

    printf("Queue: ");

    while (temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

int main(){
    int choice, value;

    while (1){
        printf("\n--- QUEUE MENU ---\n");
        printf("1. ENQUEUE\n");
        printf("2. DEQUEUE\n");
        printf("3. DISPLAY\n");
        printf("4. EXIT\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice){
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                enqueue(value);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}