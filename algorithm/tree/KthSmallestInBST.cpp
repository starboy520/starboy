struct TreeNode {
    TreeNode* left;
    TreeNode* right;
    int val;
};

TreeNode* findKthSmallest(TreeNode* root, int& val, int k) {
    TreeNode* tmp = NULL;
    if (root->left && val < k) {
        tmp = findKthSmallest(root->left, val, k)
    }
    val++;
    if (val == k) return tmp;

    if (root->right && *n < k)
        tmp = findKthSmallest(root->right, val, k);

    return tmp;
}

// find a node's successor
TreeNode* inOrderSucessor(TreeNode* root, TreeNode* p) {
    if (p->right) {
        TreeNode* q = p->right;
        while (q->left) q = q->left;
        return q;
    }

    TreeNode* succ = NULL;

    while (root != NULL) {
        if (p->val < root->val) {
            succ = root;
            root = root->left;
        } else if (n->val > root->val) root = root->right;
        else break;
    }

    return succ;
}
