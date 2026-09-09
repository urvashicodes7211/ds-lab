#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Node {
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

int checkHeight(struct Node* root){
    if (root == NULL)
        return 0;

    int leftHeight = checkHeight(root->left);
    if (leftHeight == -1)
        return -1;

    int rightHeight = checkHeight(root->right);
    if (rightHeight == -1)
        return -1;

    if (abs(leftHeight - rightHeight) > 1)
        return -1;

    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

int isBalanced(struct Node* root){
    return checkHeight(root) != -1;
}

int main(){
    struct Node* root = createNode(3);

    root->left = createNode(9);
    root->right = createNode(20);

    root->right->left = createNode(15);
    root->right->right = createNode(7);

    if (isBalanced(root))
        printf("TRUE");
    else
        printf("FALSE");

    return 0;
}