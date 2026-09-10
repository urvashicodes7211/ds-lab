// Write a program to implement phone book dictionary using Binary Search Tree 
// which provides following operations: 
//  Add new entry in phone book,  
//  Remove entry from phone book,  
//  Search phone number  
//  List all entries in ascending order of name and 
//  List all entries in descending order of name

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct TreeNode{
    char name[100];
    char phone[20];

    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* createNode(char name[], char phone[]){
    struct TreeNode *newNode;

    newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));

    strcpy(newNode->name, name);
    strcpy(newNode->phone, phone);

    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

struct TreeNode* insertNode(struct TreeNode *root,char name[], char phone[]){
    if (root == NULL){
        return createNode(name, phone);
    }

    if (strcmp(name, root->name) < 0){
        root->left = insertNode(root->left, name, phone);
    }else if (strcmp(name, root->name) > 0){
        root->right = insertNode(root->right, name, phone);
    }else{
        printf("Name already exists!\n");
    }

    return root;
}

struct TreeNode* getInOrderSuccessor(struct TreeNode *root){
    while (root != NULL && root->left != NULL){
        root = root->left;
    }

    return root;
}

struct TreeNode* deleteNode(struct TreeNode *root, char name[]){
    struct TreeNode *temp;
    struct TreeNode *in;

    if (root == NULL){
        printf("Entry not found!\n");
        return NULL;
    }

    if (strcmp(name, root->name) < 0){
        root->left = deleteNode(root->left, name);
    }else if (strcmp(name, root->name) > 0){
        root->right = deleteNode(root->right, name);
    }else{
        if (root->left == NULL && root->right == NULL){
            free(root);
            return NULL;
        }else if (root->left == NULL){
            temp = root->right;
            free(root);  
            return temp;
        }else if (root->right == NULL){
            temp = root->left;
            free(root);
            return temp;
        }else{
            in = getInOrderSuccessor(root->right);

            strcpy(root->name, in->name);
            strcpy(root->phone, in->phone);

            root->right = deleteNode(root->right, in->name);
        }
    }

    return root;
}

struct TreeNode* searchNode(struct TreeNode *root, char name[]){
    if (root == NULL){
        return NULL;
    }

    if (strcmp(root->name, name) == 0){
        return root;
    }

    if (strcmp(name, root->name) < 0){
        return searchNode(root->left, name);
    }else{
        return searchNode(root->right, name);
    }
}

void inOrder(struct TreeNode *root){
    if (root == NULL){
        return;
    }

    inOrder(root->left);

    printf("Name  : %s\n", root->name);
    printf("Phone : %s\n\n", root->phone);

    inOrder(root->right);
}

void reverseInOrder(struct TreeNode *root){
    if (root == NULL){
        return;
    }

    reverseInOrder(root->right);

    printf("Name  : %s\n", root->name);
    printf("Phone : %s\n\n", root->phone);

    reverseInOrder(root->left);
}

int main(){
    struct TreeNode *root = NULL;
    struct TreeNode *result;

    int choice;
    char name[100];
    char phone[20];

    while (1){
        printf("\n========== PHONE BOOK ==========\n");
        printf("1. Add New Entry\n");
        printf("2. Remove Entry\n");
        printf("3. Search Phone Number\n");
        printf("4. List All Entries - Ascending\n");
        printf("5. List All Entries - Descending\n");
        printf("6. Exit\n");
        printf("================================\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice){
            case 1:

                printf("\nEnter Name: ");
                scanf(" %[^\n]", name);

                printf("Enter Phone Number: ");
                scanf(" %[^\n]", phone);

                root = insertNode(root, name, phone);

                printf("Entry added successfully!\n");

                break;


            case 2:

                printf("\nEnter Name to Remove: ");
                scanf(" %[^\n]", name);

                result = searchNode(root, name);

                if (result == NULL){
                    printf("Entry not found!\n");
                }else{
                    root = deleteNode(root, name);
                    printf("Entry removed successfully!\n");
                }

                break;


            case 3:

                printf("\nEnter Name to Search: ");
                scanf(" %[^\n]", name);

                result = searchNode(root, name);

                if (result == NULL){
                    printf("Entry not found!\n");
                }else{
                    printf("\nEntry Found!\n");
                    printf("Name  : %s\n", result->name);
                    printf("Phone : %s\n", result->phone);
                }

                break;


            case 4:

                printf("\n--- PHONE BOOK (ASCENDING ORDER) ---\n");

                if (root == NULL){
                    printf("Phone Book is empty!\n");
                }else{
                    inOrder(root);
                }

                break;


            case 5:

                printf("\n--- PHONE BOOK (DESCENDING ORDER) ---\n");

                if (root == NULL){
                    printf("Phone Book is empty!\n");
                }else{
                    reverseInOrder(root);
                }

                break;


            case 6:

                printf("\nProgram ended.\n");
                exit(0);


            default:
                printf("\nInvalid choice! Try again.\n");
        }
    }

    return 0;
}