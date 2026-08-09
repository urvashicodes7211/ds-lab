#include <stdio.h>

int queue[100];
int priority[100];
int size = 0;

void insert(){
    int value, p;

    if (size == 100){
        printf("Queue is Full!\n");
        return;
    }

    printf("Enter value: ");
    scanf("%d", &value);

    printf("Enter priority: ");
    scanf("%d", &p);

    queue[size] = value;
    priority[size] = p;
    size++;

    printf("Element inserted successfully.\n");
}

void delete(){
    int i, pos = 0;

    if (size == 0){
        printf("Queue is Empty!\n");
        return;
    }

    for (i = 1; i < size; i++){
        if (priority[i] < priority[pos]){
            pos = i;
        }
    }

    printf("Deleted element: %d\n", queue[pos]);

    for (i = pos; i < size - 1; i++){
        queue[i] = queue[i + 1];
        priority[i] = priority[i + 1];
    }

    size--;
}

void display(){
    int i;

    if (size == 0){
        printf("Queue is Empty!\n");
        return;
    }

    printf("\nValue\tPriority\n");

    for (i = 0; i < size; i++){
        printf("%d\t%d\n", queue[i], priority[i]);
    }
}

int main(){
    int choice;

    do{
        printf("\n--- Priority Queue ---\n");
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
                printf("Exit...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 4);

    return 0;
}