class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m == 0) return 0;
        vector<int> a(n, 0);
        for (int i = 0; i < n; i++) a[i] = 1;
        
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                a[j] = a[j] + a[j-1];
            }
        }
        return a[n-1];
    }
};
