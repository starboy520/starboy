class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        int m = grid.size();
        int n = grid[0].size();
        int *a = new int[n];
        a[0] = grid[0][0];
        for (int i = 1; i < n; i++) {
            a[i] = a[i-1] + grid[0][i];
        }
        for (int i = 1; i < m; i++) {
            a[0] = a[0] + grid[i][0];
            for (int j = 1; j < n; j++) {
                a[j] = min(a[j-1], a[j]) + grid[i][j];
            }
        }
        return a[n-1];
    }
};
