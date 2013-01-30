class Solution {
public:
    int trap(int a[], int n) {
        if (a == NULL || n <=2) return 0;
        vector<int> leftHeight(n, 0);
        leftHeight[0] = 0;
        int maxleft = a[0];
        for (int i = 1; i < n; i++) {
            leftHeight[i] = maxleft;
            maxleft = std::max(maxleft, a[i]);
        }
        
        int trap = 0;
        int maxright = a[n-1];
        
        for (int i = n-2; i >= 0; i--) {
            int left = leftHeight[i];
            int right = maxright;
            int mins = std::min(left, right);
            if (mins > a[i]) {
                trap += mins - a[i];
            }
            maxright = std::max(maxright, a[i]);
        }
        
        return trap;
    }
};
