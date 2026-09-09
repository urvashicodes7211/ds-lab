#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

int search(int arr[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (arr[i] == value)
            return i;
    }
    return -1;
}

struct Node* constructTree(int pre[], int post[], int *preIndex,int postStart, int postEnd, int n) {

    struct Node *root = (struct Node*)malloc(sizeof(struct Node));
    root->data = pre[*preIndex];
    root->left = NULL;
    root->right = NULL;

    (*preIndex)++;

    if (postStart == postEnd || *preIndex >= n)
        return root;

    int pos = search(post, postStart, postEnd, pre[*preIndex]);

    if (pos == -1)
        return root;

    root->left = constructTree(pre, post, preIndex,postStart, pos, n);

    if (*preIndex < n && pos < postEnd) {
        root->right = constructTree(pre, post, preIndex,pos + 1, postEnd - 1, n);
    }

    return root;
}

void inorder(struct Node *root) {
    if (root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    int n;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    int pre[n], post[n];

    printf("Enter Preorder traversal:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &pre[i]);
    }

    printf("Enter Postorder traversal:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &post[i]);
    }

    int preIndex = 0;

    struct Node *root = constructTree(
        pre, post, &preIndex, 0, n - 1, n
    );

    printf("\nInorder traversal of constructed tree: ");
    inorder(root);

    return 0;
}