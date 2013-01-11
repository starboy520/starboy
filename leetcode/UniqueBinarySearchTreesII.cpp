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
    vector<TreeNode* > gen(int begin, int end) {
        vector<TreeNode*> result;
        if (begin > end) {
          result.push_back(NULL);
          return result;
        }

        for (int i = begin; i <= end; i++) {
            vector<TreeNode*> tmpall;
            vector<TreeNode*> tmp1 = gen(begin, i-1);
            vector<TreeNode* >tmp2 = gen(i+1, end);


            for (int j = 0; j < tmp1.size(); j++) {
              for (int k = 0; k < tmp2.size(); k++) {
                TreeNode* c = new TreeNode(i);
                c->left = tmp1[j];
                c->right = tmp2[k];
                result.push_back(c);
              }
            }
        }
        return result;
    }

    vector<TreeNode *> generateTrees(int n) {
        return gen(1, n);
    }
};
