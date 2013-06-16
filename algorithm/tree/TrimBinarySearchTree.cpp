#include <stdio.h>
struct Node {
    Node* left;
    Node* right;
    int val;

    Node(int v) : val(v), left(NULL), right(NULL) {
    }
};

Node* trimBinarySearchTree(Node* root, int min, int max) {
    if (root == NULL) {
        return NULL;
    }

    root->left = trimBinarySearchTree(root->left, min, max);
    root->right = trimBinarySearchTree(root->right, min, max);

    if (root->val < min) {
        Node* child = root->right;
        delete root;
        return child;
    }

    if (root->val > max) {
        Node* child = root->left;
        delete root;
        return child;
    }
    return root;
}
