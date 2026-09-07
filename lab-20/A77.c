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

struct Node* createTree(){
    int data;

    printf("Enter data (-1 for NULL): ");
    scanf("%d", &data);

    if (data == -1)
        return NULL;

    struct Node* root = createNode(data);

    printf("Enter left child of %d:\n", data);
    root->left = createTree();

    printf("Enter right child of %d:\n", data);
    root->right = createTree();

    return root;
}

int isMirror(struct Node* left, struct Node* right){
    if (left == NULL && right == NULL)
        return 1;

    if (left == NULL || right == NULL)
        return 0;

    return (left->data == right->data &&
            isMirror(left->left, right->right) &&
            isMirror(left->right, right->left));
}

int isSymmetric(struct Node* root){
    if (root == NULL)
        return 1;

    return isMirror(root->left, root->right);
}

int main(){
    struct Node* root;

    printf("Create Binary Tree:\n");
    root = createTree();

    if (isSymmetric(root))
        printf("\nTree is Symmetric.\n");
    else
        printf("\nTree is NOT Symmetric.\n");

    return 0;
}