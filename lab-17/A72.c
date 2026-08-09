/* Write a menu driven program to implement following operations on a circular 
queue using an Array 
 Insert 
 Delete 
 Display all elements of the queue*/
#include <stdio.h>

int queue[100];
int front = -1;
int rear = -1;
int size;

void insert(){
    int value;

    if ((rear + 1) % size == front){
        printf("Queue is Full\n");
        return;
    }

    printf("Enter element: ");
    scanf("%d", &value);

    if (front == -1){
        front = 0;
        rear = 0;
    }
    else{
        rear = (rear + 1) % size;
    }

    queue[rear] = value;
    printf("Element inserted successfully\n");
}

void delete(){
    if (front == -1){
        printf("Queue is Empty\n");
        return;
    }

    printf("Deleted element: %d\n", queue[front]);

    if (front == rear){
        front = -1;
        rear = -1;
    }else{
        front = (front + 1) % size;
    }
}

void display(){
    int i;

    if (front == -1){
        printf("Queue is Empty\n");
        return;
    }

    printf("Queue elements: ");

    i = front;

    while (1){
        printf("%d ", queue[i]);

        if (i == rear)
            break;

        i = (i + 1) % size;
    }

    printf("\n");
}

int main(){
    int choice;

    printf("Enter size of circular queue: ");
    scanf("%d", &size);

    while (1){
        printf("\n--- Circular Queue Menu ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice){
            case 1:
                insert();
                break;

            case 2:
                delete();
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}