// Given Preorder traversal of a BST, check if each non-leaf node has only one child. Assume that the BST contains unique entries.

bool hasOnlyOneChild(int* a, int size) {
    if (a == NULL) return false;

    for (int i = 0; i < size; i++) {
        int nextDiff = a[i] - a[i+1];
        int lastDiff = a[i] - a[size-1];
        if (nextDiff * lastDiff < 0)
            return false;
    }
    return true;
}
