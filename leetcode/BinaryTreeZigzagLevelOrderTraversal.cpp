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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector< vector<int> > result;
        if (root == NULL) return result;
        
        stack<TreeNode* > tree_stack;
        tree_stack.push(root);
        int i = 0;
        
        while(!tree_stack.empty()) {
            vector<int> tmp_result;
            stack<TreeNode* > tmp_stack;
            
            i++;
            while (!tree_stack.empty()) {
                TreeNode* cur = tree_stack.top();
                tmp_result.push_back(cur->val);
                if (i % 2 == 1) {
                    if (cur->left) tmp_stack.push(cur->left);
                    if (cur->right) tmp_stack.push(cur->right);    
                } else {
                    if (cur->right) tmp_stack.push(cur->right);
                    if (cur->left) tmp_stack.push(cur->left);
                }
                tree_stack.pop();
            }
            
            result.push_back(tmp_result);
            tree_stack = tmp_stack;
        }
        return result;
    }
};
