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
    bool isValidBST(TreeNode *root) {
        stack<TreeNode*> st;
        if (root == NULL) return true;
        
        TreeNode* last = NULL;
        while (root || !st.empty()) {
            while (root) {
                st.push(root);
                root = root->left;
            }
            
            if (!st.empty()) {
                root = st.top();
                st.pop();
                if (last == NULL) {
                    last = root;
                } else {
                    if (last->val >= root->val) {
                        return false;
                    }
                    last = root;
                }
                root = root->right;
            }
        }
        return true;
    }
};
