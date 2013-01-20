
void inner_mclosest(TreeNode* root, int key, int m, deque<TreeNode*>& que) {
  if (NULL == root) return;

  inner_mclosest(root->left, key, m, que);
  if (que.size() < m) {
    que.push_back(root);
  } else {
    if (abs(root->val-key) < abs(que.front()->val-key)) {
      que.pop_front();
      que.push_back(root);
    }
  }
  inner_mclosest(root->right, key, m, que);
}
