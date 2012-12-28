/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (root == NULL) return ;
        queue<TreeLinkNode*> qu;
        TreeLinkNode* temp = NULL;
        qu.push(root);
        qu.push(temp);
        while (!qu.empty()) {
            TreeLinkNode* cur = qu.front();
            qu.pop();
            if (qu.empty())break;
            if (cur == NULL) {
                qu.push(cur);
            } else {
                if (qu.front() != NULL) cur->next = qu.front();
                if (cur->left != NULL) qu.push(cur->left);
                if (cur->right != NULL) qu.push(cur->right);
            }
        }
    }
};
