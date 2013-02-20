// Question: Given an arbitrary binary tree,
// convert it to a binary tree that holds Children Sum Property.
// You can only increment data values in any node
// (You cannot change structure of tree and cannot decrement value of any node).
#include <stdio.h>

struct TreeNode {
    struct TreeNode* left;
    struct TreeNode* right;
    int val;
};

void increment(TreeNode* root, int val) {
    if (root->left != NULL) {
        root->left->val += val;
        increment(root->left, val);
    } else if (root->right != NULL) {
        root->right->val += val;
        increment(root->right, val);
    }
}
void convertTree(TreeNode* root) {
    if (root == NULL ) return;
    if (root->left == NULL && root->right == NULL) return ;

    convertTree(root->left);
    convertTree(root->right);

    int left = 0;
    if (root->left != NULL) left = root->left->val;
    int right = 0;
    if (root->right != NULL) right = root->right->val;

    int diff = left + right - root->val;

    if (diff > 0) root->val = root->val + diff;
    if (diff < 0) {
        increment(root, -diff);
    }
}
