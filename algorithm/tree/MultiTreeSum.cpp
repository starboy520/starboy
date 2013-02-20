#include <vector>
using namespace std;
struct TreeNode {
    int val;
    vector<TreeNode*> child;
};


int TreeSum(TreeNode* root, int prefix) {
    if (root == NULL) return 0;
    prefix = prefix * 10 + root->val;

    if ((root->child).size() == 0) return prefix;

    int sum = 0;
    for (int i = 0; i < (root->child).size(); i++) {
        sum += TreeSum(root->child[i], prefix);
    }
    return sum;
}
