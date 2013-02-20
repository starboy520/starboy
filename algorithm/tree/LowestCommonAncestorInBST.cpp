struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
};

// Given the values of two nodes in a *binary search tree*,
// write a c program to find the lowest common ancestor.
// You may assume that both values already exist in the tree.

int FindLowestCommonAncestor(node* root, int value1, int value) {
    if (root == NULL) return -1;
    if (root->val >= value1 && root->val <= value2)
        return root->val;

    else if (root->val > value1 && root->val > value2)
        return FindLowestCommonAncestor(root->left, value1, value2);
    else
        return FindLowestCommonAncestor(root->right, value1, value2);
}

// not bst?
TreeNode* lca(TreeNode* root, TreeNode*p, TreeNode* q) {
    if (root == NULL) return NULL;
    if (root == p || root == q) return root;
    TreeNode* l = lca(root->left, p, q);
    TreeNode* r = lca(root->right, p, q);
    if (l && r) return root;
    return l?l:r;
}

