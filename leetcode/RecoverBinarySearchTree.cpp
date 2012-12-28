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
    void recover(TreeNode* root, TreeNode* &pre, TreeNode* &first, TreeNode* &second) {
        if (root == NULL) return ;
        recover(root->left, pre, first, second);
        if (pre != NULL && pre->val > root->val) {
            if (first == NULL) first = pre;
            second = root;
        }
        pre = root;
        recover(root->right, pre, first, second);
    }
    void recoverTree(TreeNode *root) {
        TreeNode* pre = NULL;
        TreeNode* first = NULL;
        TreeNode* second = NULL;;
        recover(root, pre, first, second);
        swap(first->val, second->val);
    }
};
