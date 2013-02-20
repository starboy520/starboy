#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
};

int diameter(TreeNode* root, int* height) {
    int lh = 0;
    int rh = 0;

    int ldiameter = 0;
    int rdiameter = 0;

    if (root == NULL) {
        *height = 0;
        return 0;
    }

    ldiameter = diameter(root->left, &lh);
    rdiameter = diameter(root->right, &rh);
    *height = std::max(lh, rh) + 1;
    return (lh+rh+1, max(ldiameter, rdiameter));
}
