class Solution {
public:
    void flatten(TreeNode *root) {
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
    }
};

/*
 * class Solution {
	void flatten(TreeNode* root) {
		if (root == NULL) return;
		if (root->left) flatten(root->left);
		if (root->right) flatten(root->right);
		if (root->left == NULL) return;

		TreeNode** ptn = &(root->left->right);
		while (*ptn) 
			ptn = &((*ptn)->right);
		*ptn = root->right;

		root->right = root->left;
		root->left = NULL;
	}
}
*/
