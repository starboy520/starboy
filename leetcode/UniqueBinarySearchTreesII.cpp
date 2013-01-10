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
        if (begin > end) return result;

        
        for (int i = begin; i <= end; i++) {
            vector<TreeNode*> tmpall;
            vector<TreeNode*> tmp1 = gen(begin, i-1);
            vector<TreeNode* >tmp2 = gen(i+1, end);
            
            if (tmp1.size() == 0 && tmp2.size() == 0) {
                TreeNode* c = new TreeNode(i);
                result.push_back(c);
                
            } else if (tmp1.size() == 0) {
                for (int j = 0; j < tmp2.size(); j++) {
                    TreeNode* c = new TreeNode(i);
                    c->right = tmp2[j];
                    result.push_back(c);
                }
            } else  if (tmp2.size() == 0) {
                for (int j = 0; j < tmp1.size(); j++) {
                    TreeNode* c = new TreeNode(i);
                    c->left = tmp1[j];
                    result.push_back(c);
                }
            }  else {
            
                for (int j = 0; j < tmp1.size(); j++) {
                    for (int k = 0; k < tmp2.size(); k++) {
                        TreeNode* c = new TreeNode(i);
                        c->left = tmp1[j];
                        c->right = tmp2[k];
                        result.push_back(c);
                    }
                }
            }
        }
        return result;
    }
    
    vector<TreeNode *> generateTrees(int n) {
        if (n == 0) {
            vector<TreeNode* > tmp;
            tmp.push_back(NULL);
            return tmp;
        }
        return gen(1, n);
        
    }
};
