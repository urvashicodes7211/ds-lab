#include <stdio.h>

#define SIZE 100
int queue[SIZE];
int front = -1;
int rear = -1;

void enqueue(){
    int value;

    if (rear == SIZE - 1){
        printf("Queue is Full!\n");
        return;
    }

    printf("Enter value: ");
    scanf("%d", &value);

    if (front == -1)
        front = 0;

    rear++;
    queue[rear] = value;

    printf("Value inserted.\n");
}

void dequeue(){
    if (front == -1 || front > rear){
        printf("Queue is Empty!\n");
        return;
    }

    printf("Deleted value = %d\n", queue[front]);

    front++;

    if (front > rear){
        front = -1;
        rear = -1;
    }
}

void display(){
    int i;

    if (front == -1){
        printf("Queue is Empty!\n");
        return;
    }

    printf("Queue: ");

    for (i = front; i <= rear; i++){
        printf("%d ", queue[i]);
    }

    printf("\n");
}

int main(){
    int choice;

    do{
        printf("\n1. ENQUEUE");
        printf("\n2. DEQUEUE");
        printf("\n3. DISPLAY");
        printf("\n4. EXIT");

        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice){
            case 1:
                enqueue();
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exit");
                break;

            default:
                printf("Invalid choice!");
        }

    } while (choice != 4);

    return 0;
}