#include <iostream>
using namespace std;

struct TreeNode {
	int val;
	struct TreeNode* left;
	struct TreeNode* right;

	TreeNode(int v) : val(v), left(NULL), right(NULL) {
	}
};

int leftHeight(TreeNode* root) {
    int height = 0;
    while (root) {
        root = root->left;
        height++;
    }
    return height;
}

int rightHeight(TreeNode* root) {
    int height = 0;
    while (root) {
        height++;
        root = root->right;
    }
    return height;
}

int numOfAll(int height) {
    int all = 0;
    int num = 1;
    for (int i = 0; i < height; i++) {
        all += num;
        num *= 2;
    }
    return all;
}

int numOfNode(TreeNode* root) {
    int h = leftHeight(root);
    int total = 0;
    while (h > 0 && root != NULL) {
        if (rightHeight(root->left) == h-1) {
            total += numOfAll(h-1)+1;
            root = root->right;
        } else {
            total += numOfAll(h-2) + 1;
            root = root->left;
        }
        h--;
    }
    return total;
}

/*
int numOfNode(TreeNode* root) {
    int h = height(root);

    TreeNode* tmp = root;
    TreeNode* q;
    int nums = 0;
    for (int i = 0; i < h; i++) {
        if (tmp == NULL) break;

        q = tmp->left;

        int hs = 0;
        while (q) {
            hs++;
            q = q->right;
        }

        nums += (1 + numOfAll(hs));

        if (hs == h-1-i) {
            tmp = tmp->right;
        } else {
            tmp = tmp->left;
        }
    }

    return nums;
}
*/

int main() {
    TreeNode* a = new TreeNode(1);
    TreeNode* b = new TreeNode(2);
    TreeNode* c = new TreeNode(3);
    TreeNode* d = new TreeNode(4);
    TreeNode* f = new TreeNode(5);

    TreeNode* m = new TreeNode(6);

    b->left = d;
    b->right = f;
    c->left = f;
    a->left = b;
    a->right = c;

    cout << numOfNode(a) << endl;
}
