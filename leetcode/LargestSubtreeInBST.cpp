#include <stdio.h>
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
};

// Given a binary tree, find the largest subtree which is a Binary Search Tree (BST),
// where largest means subtree with largest number of nodes in it.

int findLargestBSTSubtree (TreeNode* root, int &min, int& max, int& max_node, TreeNode*&largestBST) {
    if (root == NULL) return 0;

    bool isBST = true;
    int leftNode = findLargestBSTSubtree(root->left, min, max, max_node, largestBST);
    int curMin = (leftNode == 0) ? root->val : min;
    if (leftNode == -1 || (leftNode != 0) && root->val < max) {
        isBST = false;

    }

    int rightNode = findLargestBSTSubtree(root->right, min, max, max_node, largestBST);

    int curMax = (rightNode == 0) ? root->val : max;

    if (rightNode == -1 || (rightNode != 0 && root->val >= min)) isBST = false;

    if (isBST) {
        min = curMin;
        max = curMax;
        int total = leftNode + rightNode + 1;
        if (total > max_node) {
            max_node = total;
            largestBST = root;
        }
        return total;
    } else {
        return -1;
    }
}
