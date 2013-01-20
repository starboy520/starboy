// 5. 2个BST,按大小顺序打印两棵树的所有节点。

// printf one bst in recursion

struct TreeNode {
  int val;
  struct TreeNode* left;
  struct TreeNode* right;
};

void PrintBST(TreeNode* root, int min, int max) {
  if (root == NULL) return;
  if (root->val <= min) {
    PrintBST(r->right, min, max);
  } else if (root->val >= max) {
    PrintBST(root->left, min, max);
  } else {
    PrintBST(root->left, min, root->val);
    cout << root->val;
    PrintBST(root->right, root->val, max);
  }
}

void Print2BST(TreeNode* r1, TreeNode* r2, int min, int max) {
  if (r1 == NULL && r2 == NULL) return;
  else if (r1 == NULL) {
    PrintBST(r2, min, max);
  } else if (r2 == NULL) {
    PrintBST(r1, min, max);
  } else {
    if (r1->val > r2->val) std::swap(r1, r2);

    if (r1->val <=min)
      Print2BST(r1->right, r2, min, max);
    else if (r1->val >= max)
      Print2BST(r1->left, r2, min, max);
    else if (r2->val <=min)
      Print2BST(r1, r2->right, min, max);
    else if (r2->val >= max)
      Print2BST(r1, r2->left, min, max);
    else {
      Print2BST(t1->left, r2->left, min, r1->val);
      cout << r1->val;
      Print2BST(r1->right, r2->left, r1->val, r2->val);
      cout << r2->val;
      Print2BST(r1->right, r2->right, r2->val, max);
    }
  }
}
