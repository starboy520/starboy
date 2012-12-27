class Solution {
public:
    void flatten(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(root == NULL) return;
        TreeNode* res = NULL;
        stack<TreeNode*> stk;
        stk.push(root);
        while(!stk.empty()){
            TreeNode* top = stk.top();
            stk.pop();
            if(top->right){
                stk.push(top->right);
                top->right = NULL;
            }
            if(top->left){
                stk.push(top->left);
                top->left=NULL;
            }
            if(res == NULL) res = top;
            else{
                res->right = top;
                res = res->right;
            }
        }
        //root = res;
    }
};
