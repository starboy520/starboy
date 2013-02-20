struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode* nextRight;
};

TreeNode* getNextRight(TreeNode* root) {
    TreeNode* temp = root->nextRight;
    while (temp != NULL) {
        if (temp->left != NULL) {
            return temp->left;
        }
        if (temp->right != NULL) {
            return temp->right;
        }
        temp = temp->nextRight;
    }
    return NULL;
}

void Connect(TreeNode* root) {
    if (root == NULL) return;

    if (root->nextRight != NULL) {
        Connect(root->nextRight);
    }

    if (root->left) {
        if (root->right) {
            root->left->nextRight = root->right;
            root->right->nextRight = getNextRight(root);
        } else {
            root->left->nextRight = getNextRight(root);
        }
        connect(root->left);
    } else if (root->right) {
        root->right->nextRight = getNextRight(root);
        Connect(p->right);
    } else {
        Connect(getNextRight(root));
    }

}

void connect(TreeNode* root) {
    if (root == NULL) return ;
    root->nextRight = NULL;
    TreeNode* temp;
    while (root) {
        TreeNode* q = root;
        while (q != NULL) {
            if (q->left) {
                if (q->right) {
                    q->left->nextRight = q->right;
                } else {
                    q->left->nextRight = getNextRight(q);
                }
            }

            if (q->right) q->right->nextRight = getNextRight(q);
            q = q->nextRight;
        }

        if (root->left) root = root->left;
        else if (root->right) root = root->right;
        else root = getNextRight(root);
    }
}
