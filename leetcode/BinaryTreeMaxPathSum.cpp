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
    int maxSum(TreeNode* root, int& allmax) {
        if (!root) return 0;
        int left = maxSum(root->left, allmax);
        int right = maxSum(root->right, allmax);
        int localmx = root->val;
        if (left>0) localmx += left;
        if (right>0) localmx += right;
        allmax=max(localmx, allmax);
        return max(root->val, max(root->val+left, root->val+right));
    }
    int maxPathSum(TreeNode *root) {
        int mymax = root->val;
        int val = maxSum(root, mymax);
        return max(mymax, val);
    }
};
