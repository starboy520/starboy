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
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int> > result;
        if (root == NULL) return result;
        
        TreeNode* temp = NULL;
        
        queue<TreeNode*> tmpque;
        
        tmpque.push(root);
        tmpque.push(temp);
        
        vector<int> a;
        
        while (!tmpque.empty()) {
            TreeNode* tmp = tmpque.front();
            tmpque.pop();
            if (tmp == NULL) {
                result.push_back(a);
                if (tmpque.empty()) {
                    break;
                }
                tmpque.push(tmp);
                a.clear();
            } else {
                a.push_back(tmp->val);
                if (tmp->left != NULL) tmpque.push(tmp->left);
                if (tmp->right != NULL) tmpque.push(tmp->right);
            }
        }
    }
};
