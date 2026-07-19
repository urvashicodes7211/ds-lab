// WAP to split a circular linked list into two halves. 

#include<stdio.h>
#include<stdlib.h>

struct Node{
    int info;
    struct Node *link;
};

struct Node *first = NULL;
struct Node *last = NULL;

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
void display(struct Node *first){
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
int countNodes(){
    int count = 1;
    struct Node *save = first;

    while(save->link != first){
        save = save->link;
        count++;
    }
    return count;
}
void splitList(){
    int count = countNodes();
    int mid;

    if(count % 2 == 0){
        mid = count / 2;
    }else{
        mid = count / 2 + 1;
    }
    
    struct Node *first1 = first;
    struct Node *first2;
    struct Node *save = first;

    int i;

    for(i=1; i<mid; i++){
        save = save->link;
    }

    first2 = save->link;
    save->link = first1;

    save = first2;
    while(save->link != first){
        save = save->link;
    }
    save->link = first2;

    printf("\nFirst Half:\n");
    display(first1);

    printf("Second Half:\n");
    display(first2);
}
int main(){
    insertAtEnd(1);
    insertAtEnd(2);
    insertAtEnd(3);
    insertAtEnd(4);
    insertAtEnd(5);
    display(first);
    splitList();
    return 0;
}