/*Write a menu driven program to implement following operations on the 
Doubled Ended Queue using an Array 
 Insert at front end, Insert at rear end 
 Delete from front end, Delete from rear end 
 Display all elements of the queue*/

#include <stdio.h>

#define SIZE 100

int deque[SIZE];
int front = -1;
int rear = -1;

void insertFront(int value){
    if ((front == 0 && rear == SIZE - 1) || (front == rear + 1)){
        printf("Deque is Full\n");
        return;
    }

    if (front == -1){
        front = rear = 0;
    }else if (front == 0){
        front = SIZE - 1;
    }else{
        front--;
    }

    deque[front] = value;
    printf("%d inserted at front\n", value);
}

void insertRear(int value){
    if ((front == 0 && rear == SIZE - 1) || (front == rear + 1)){
        printf("Deque is Full\n");
        return;
    }

    if (front == -1){
        front = rear = 0;
    }else if (rear == SIZE - 1){
        rear = 0;
    }else{
        rear++;
    }

    deque[rear] = value;
    printf("%d inserted at rear\n", value);
}

void deleteFront(){
    int value;

    if (front == -1){
        printf("Deque is Empty\n");
        return;
    }

    value = deque[front];

    if (front == rear){
        front = rear = -1;
    }else if (front == SIZE - 1){
        front = 0;
    }else{
        front++;
    }

    printf("%d deleted from front\n", value);
}

void deleteRear(){
    int value;

    if (front == -1){
        printf("Deque is Empty\n");
        return;
    }

    value = deque[rear];

    if (front == rear){
        front = rear = -1;
    }else if (rear == 0){
        rear = SIZE - 1;
    }else{
        rear--;
    }

    printf("%d deleted from rear\n", value);
}

void display(){
    int i;

    if (front == -1){
        printf("Deque is Empty\n");
        return;
    }

    printf("Deque elements: ");

    i = front;

    while (1){
        printf("%d ", deque[i]);

        if (i == rear)
            break;

        i = (i + 1) % SIZE;
    }

    printf("\n");
}

int main(){
    int choice, value;

    while (1){
        printf("\n--- DEQUE MENU ---\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at Rear\n");
        printf("3. Delete from Front\n");
        printf("4. Delete from Rear\n");
        printf("5. Display\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice){
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertFront(value);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertRear(value);
                break;

            case 3:
                deleteFront();
                break;

            case 4:
                deleteRear();
                break;

            case 5:
                display();
                break;

            case 6:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}