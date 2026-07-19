/*Write a program to perform addition of two polynomial equations using
appropriate data structure.*/

#include<stdio.h>
#include<stdlib.h>

struct Node{
    int coeff;
    int expo;
    struct Node *link;
};

struct Node *first1 = NULL;
struct Node *last1 = NULL;

struct Node *first2 = NULL;
struct Node *last2 = NULL;

struct Node *result = NULL;
struct Node *last = NULL;


void insertAtEnd(int coeff,int expo,int ch){

    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->coeff = coeff;
    newNode->expo = expo;
    newNode->link = NULL;

    if(ch == 1){
        if(first1 == NULL){
            first1 = last1 = newNode;
        }
        else{
            last1->link = newNode;
            last1 = newNode;
        }
    }
    else if(ch == 2){
        if(first2 == NULL){
            first2 = last2 = newNode;
        }
        else{
            last2->link = newNode;
            last2 = newNode;
        }
    }
    else{
        if(result == NULL){
            result = last = newNode;
        }
        else{
            last->link = newNode;
            last = newNode;
        }
    }
}

void add(){

    struct Node *temp1;
    struct Node *temp2;

    temp1 = first1;
    temp2 = first2;

    while(temp1 != NULL && temp2 != NULL){

        if(temp1->expo > temp2->expo){

            insertAtEnd(temp1->coeff,temp1->expo,3);
            temp1 = temp1->link;

        }
        else if(temp1->expo < temp2->expo){

            insertAtEnd(temp2->coeff,temp2->expo,3);
            temp2 = temp2->link;

        }
        else{

            insertAtEnd(temp1->coeff + temp2->coeff,temp1->expo,3);
            temp1 = temp1->link;
            temp2 = temp2->link;

        }
    }

    while(temp1 != NULL){
        insertAtEnd(temp1->coeff,temp1->expo,3);
        temp1 = temp1->link;
    }

    while(temp2 != NULL){
        insertAtEnd(temp2->coeff,temp2->expo,3);
        temp2 = temp2->link;
    }

}

void display(struct Node *first){

    struct Node *save;

    if(first == NULL){
        printf("Polynomial is Empty\n");
        return;
    }

    save = first;

    while(save != NULL){

        printf("%dx^%d",save->coeff,save->expo);

        if(save->link != NULL){
            printf(" + ");
        }

        save = save->link;
    }

    printf("\n");
}

int main(){

    insertAtEnd(5,3,1);
    insertAtEnd(4,2,1);
    insertAtEnd(2,0,1);

    insertAtEnd(3,3,2);
    insertAtEnd(2,1,2);
    insertAtEnd(1,0,2);

    printf("First Polynomial : ");
    display(first1);

    printf("Second Polynomial : ");
    display(first2);

    add();

    printf("Result : ");
    display(result);

    return 0;
}