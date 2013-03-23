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

    void nums(TreeNode* root, int &cur, int& num) {
        if (root->left == NULL && root->right == NULL) {
            cur = cur*10 + root->val;
            num += cur;
            return;
        } else if (root->left != NULL && root->right == NULL) {
            cur = cur*10 + root->val;
            nums(root->left, cur, num);
        } else if (root->right != NULL && root->left == NULL) {
            cur = cur*10 + root->val;
            nums(root->right, cur, num);
        } else {
            cur = cur*10 + root->val;
            int tmp = cur;
            nums(root->left, cur, num);
            cur = tmp;
            nums(root->right, cur, num);
        }
        
    }
    int sumNumbers(TreeNode *root) {
        int sum = 0;
        int cur = 0;
        if (root != NULL) {
            nums(root, cur, sum);
        }
        return sum;
    }
};
