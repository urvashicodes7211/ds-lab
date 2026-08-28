/* Write a menu driven program to implement Binary Search Tree (BST) & perform 
following operations:  
- Insert a node 
- Delete a node 
- Search a node 
- Preorder Traversal 
- Postorder Traversal 
- Inorder Traversal*/

// #include<stdio.h>
// void insertNode(){
//     printf("hi");
// }
// void deleteNode(){
//     printf("hi");
// }
// void searchNode(){
//     printf("hi");
// }
// void preOrder(){
//     printf("hi");
// }
// void postOrder(){
//     printf("hi");
// }
// void inOrder(){
//     printf("hi");
// }
// int main(){
//     int choice;
//     printf("1.Insert \n 2.Delete \n 3.Search \n 4.Preorder Traversal \n 5.Postorder Traversal \n 6.Inorder Traversal \n");
//     printf("Enter choice : ");
//     scanf("%d",choice);
//     switch (choice) {
//     case 1 : 
//         insertNode();
//         break;
//     case 2 :
//         deleteNode();
//         break;
//     case 3 :
//         searchNode();
//         break;
//     case 4 : 
//         preOrder();
//         break;
//     case 5 :
//         postOrder();
//         break;
//     case 6 : 
//         inOrder();
//         break;
    
//     }
//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

/* Create a new node */
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

/* Insert a node */
struct Node* insert(struct Node* root, int data) {

    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    }
    else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    else {
        printf("Duplicate value not allowed!\n");
    }

    return root;
}

/* Search a node */
struct Node* search(struct Node* root, int data) {

    if (root == NULL || root->data == data) {
        return root;
    }

    if (data < root->data) {
        return search(root->left, data);
    }

    return search(root->right, data);
}

/* Find minimum node */
struct Node* findMin(struct Node* root) {

    while (root->left != NULL) {
        root = root->left;
    }

    return root;
}

/* Delete a node */
struct Node* deleteNode(struct Node* root, int data) {

    if (root == NULL) {
        return root;
    }

    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    }
    else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    }
    else {

        /* Node with no child */
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }

        /* Node with only right child */
        else if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        }

        /* Node with only left child */
        else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        /* Node with two children */
        else {
            struct Node* temp = findMin(root->right);

            root->data = temp->data;

            root->right = deleteNode(root->right, temp->data);
        }
    }

    return root;
}

/* Preorder: Root Left Right */
void preorder(struct Node* root) {

    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

/* Inorder: Left Root Right */
void inorder(struct Node* root) {

    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

/* Postorder: Left Right Root */
void postorder(struct Node* root) {

    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

/* Main function */
int main() {

    struct Node* root = NULL;

    int choice, value;

    while (1) {

        printf("\n\n===== BINARY SEARCH TREE =====\n");
        printf("1. Insert a node\n");
        printf("2. Delete a node\n");
        printf("3. Search a node\n");
        printf("4. Preorder Traversal\n");
        printf("5. Postorder Traversal\n");
        printf("6. Inorder Traversal\n");
        printf("7. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("Enter value: ");
                scanf("%d", &value);

                root = insert(root, value);

                printf("Node inserted successfully.\n");
                break;

            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &value);

                if (search(root, value) == NULL) {
                    printf("Node not found.\n");
                }
                else {
                    root = deleteNode(root, value);
                    printf("Node deleted successfully.\n");
                }
                break;

            case 3:
                printf("Enter value to search: ");
                scanf("%d", &value);

                if (search(root, value) != NULL) {
                    printf("Node found.\n");
                }
                else {
                    printf("Node not found.\n");
                }
                break;

            case 4:
                printf("Preorder: ");
                preorder(root);
                printf("\n");
                break;

            case 5:
                printf("Postorder: ");
                postorder(root);
                printf("\n");
                break;

            case 6:
                printf("Inorder: ");
                inorder(root);
                printf("\n");
                break;

            case 7:
                printf("Program ended.\n");
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}