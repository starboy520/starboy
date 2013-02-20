
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
};

void printLeaves(TreeNode* root) {
    if (root) {
        printLeaves(root->left);
        if (root->left == NULL && root->right == NULL) {
            printf("%d ", root->val);
        }
        printLeaves(root->right);
    }
}

void printBoundLeft(TreeNode* root) {
    if (root) {
        if (root->left) {
            printf("%d ", root->val);
            printBoundLeft(root->left);
        } else if (root->right) {
            printf("%d ", root->val);
            printBoundLeft(root->right);
        }
    }
}

void printBoundRight(TreeNode* root) {
    if (root) {
        if (root->right) {
            printBoundRight(root->right);
            printf("%d ", root->val);

        } else if (root->left) {
            printBoundLeft(root->left);
            printf("%d ", root->val);
        }
    }
}

void printBoundary(TreeNode* root) {
    if (root) {
        printf("%d", root->val);
        printBoundLeft(root->left);

        printLeaves(root->left);
        printLeaves(root->right);

        printBoundRight(root->right);
    }
}
