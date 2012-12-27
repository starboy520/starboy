/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int height(TreeNode* root) {
        if (root == NULL) return 0;
        return 1+max(height(root->left), height(root->right));
    }
    
    bool isBalanced(TreeNode *root) {
        if (root== NULL) return true;
        return isBalanced(root->left) && isBalanced(root->right) &&
            abs(height(root->left)-height(root->right))<=1;
    }
};
