#include <algorithm>
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
};

// Given a Binary Tree, find the maximum sum path from a leaf to root

int getMaxPath(TreeNode* root) {
    if (root == NULL) return 0;
    return root->val + std::max(getMaxPath(root->left), getMaxPath(root->right));
}

void PrintMaxPath(TreeNode* root, int maxsum, int sum, vector<int>& path, vector<vector<int> >& allsum) {
    if (root == NULL) return ;

    path.push_back(root->val);
    sum += root->val;

    if (root->left == NULL && root->right == NULL && sum == maxsum) {
        allsum.push_back(path);
    }

    PrintMaxPath(root->left, maxsum, sum, path, allsum);
    PrintMaxPath(root->right, maxsum, sum, path, allsum);

    path.pop_back();
}
