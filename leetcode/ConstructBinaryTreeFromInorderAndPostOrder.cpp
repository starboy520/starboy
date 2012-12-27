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

    TreeNode* buid(vector<int> &inorder, int begin, int end, vector<int>& postorder, int first, int last) {
      if (begin > end) return NULL;

      int val = postorder[last];
      TreeNode* root = new TreeNode(val);
      if (end == begin) return root;

      int i = begin;
      for (; i <= end; i++)
        if (inorder[i] == val) break;

      if (i == begin) {
        root->left = NULL;
        root->right = buid(inorder, begin+1, end, postorder, first, last-1);

      } else if (i == end) {
        root->right = NULL;
        root->left = buid(inorder, begin, end-1, postorder, first, last-1);
      } else {
        root->left = buid(inorder, begin, i-1, postorder, first, first + (i-begin)-1);

        root->right = buid(inorder, i+1, end, postorder, first+(i-begin), last-1);
      }
      return root;
    }

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        int size1 = inorder.size();
        int size2 = postorder.size();

        return buid(inorder, 0, size1-1, 0, size2-1);
    }
};
