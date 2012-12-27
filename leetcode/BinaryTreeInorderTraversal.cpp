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
    vector<int> inorderTraversal(TreeNode *root) {
        stack<TreeNode*> p_stack;
        vector<int> result;
        while (root != NULL || !p_stack.empty()) {
            while (root != NULL) {
                p_stack.push(root);
                root = root->left;
            }
            if (!p_stack.empty()) {
                root = p_stack.top();
                p_stack.pop();
                result.push_back(root->val);
                root  = root->right;
            }
        }
        return result;
    }
};
