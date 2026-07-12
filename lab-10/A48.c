/*WAP to swap Kth node from beginning with Kth node from end in a singly linked 
list.*/
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

int countNodes(){
    struct Node *save;
    int count = 0;

    save = first;

    while(save != NULL){
        count++;
        save = save->link;
    }
    return count;
}
void swapKthNode(int k){
    int n = countNodes();

    if(k > n || k <= 0)
        return;

    if(2*k - 1 == n) 
        return;

    struct Node *x = first, *px = NULL;
    struct Node *y = first, *py = NULL;

    for(int i=1; i<k; i++){
        px = x;
        x = x->link;
    }

    for(int i=1; i<n-k+1; i++){
        py = y;
        y = y->link;
    }

    if(px != NULL)
        px->link = y;
    else
        first = y;

    if(py != NULL)
        py->link = x;
    else
        first = x;

    struct Node *temp = x->link;
    x->link = y->link;
    y->link = temp;
}
int main(){
    insertFront(1);
    insertFront(4);
    insertFront(2);
    insertFront(5);
    insertFront(1);
    display();
    int k;

    printf("Enter K : ");
    scanf("%d",&k);

    swapKthNode(k);

    printf("After Swapping:\n");
    display();
    return 0;
}