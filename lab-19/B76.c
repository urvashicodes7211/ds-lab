// Write a program to check whether the given two trees are same or not.
#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* createNode(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

int areSame(struct Node* root1, struct Node* root2){

    if (root1 == NULL && root2 == NULL)
        return 1;

    if (root1 == NULL || root2 == NULL)
        return 0;

    return (root1->data == root2->data &&
            areSame(root1->left, root2->left) &&
            areSame(root1->right, root2->right));
}

int main() {

    struct Node* root1 = createNode(1);
    root1->left = createNode(2);
    root1->right = createNode(3);

    struct Node* root2 = createNode(1);
    root2->left = createNode(2);
    root2->right = createNode(3);

    if (areSame(root1, root2))
        printf("Both trees are SAME.");
    else
        printf("Both trees are NOT SAME.");

    return 0;
}