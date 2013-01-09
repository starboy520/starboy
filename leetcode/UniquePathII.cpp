class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &a) {
        int m = a.size();
        int n = a[0].size();
        
        vector<int> result(n, 0);
        
        int i = 0;
        while (i < n && a[0][i] == 0) {
            result[i] = 1;
            i++;

        }
        
        for (int j = i; j < n; j++) result[j] = 0;
        
        for (int i = 1; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (j == 0) {
                    if (result[j] == 0) {
                        ;
                    }
                    if (a[i][0] == 1) {
                        result[j] = 0;
                    }
                } else {
                    if (a[i][j] == 1) {
                        result[j] = 0;
                    } else {
                        result[j] = result[j] + result[j-1];
                    }
                }
            }
        }
        
        return result[n-1];
    }
};
