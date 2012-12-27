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
    TreeNode* tran(vector<int>& sum, int begin, int end) {
        int mid = begin + (end - begin)/2;
        TreeNode* root = new TreeNode(sum[mid]);
        if (begin == end) return root;
        
        if (mid == begin) {
            root->left = NULL;
            root->right = tran(sum, mid+1, end);
        } else if (mid == end) {
            root->right = NULL;
            root->left = tran(sum, begin, mid-1);
        } else {
            root->left = tran(sum, begin, mid-1);
            root->right = tran(sum, mid+1, end);
        }
        return root;
    }
    TreeNode *sortedArrayToBST(vector<int> &num) {
        int size = num.size();
        if (size == 0) return NULL;
        return tran(num, 0, size-1);
    }
};
