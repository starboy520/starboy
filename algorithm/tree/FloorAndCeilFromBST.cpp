struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
};


int ceil(TreeNode* root, int input) {
    if (root == NULL)
        return -1;

    if (root->val == input)
        return input;

    if (root->key < input)
        return ceil(root->right, input);

    int ce = ceil(root->left, input);
    return ce>input?ce:root->val;
}
