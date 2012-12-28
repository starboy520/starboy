class Solution {
public:
    void setZeroes(vector<vector<int> > &a) {
        int m = a.size();
        int n = a[0].size();
        bool row_zero = false;
        bool column_zero = false;
        for (int i = 0; i < n; i++) {
            if(a[0][i] == 0) {
                row_zero = true;
                break;
            }
        }
        
        for (int i = 0; i < m; i++) {
            if (a[i][0] == 0) {
                column_zero = true;
                break;
            }
        }
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (a[i][j] == 0) {
                    a[i][0] = 0;
                    a[0][j] = 0;
                }
            }
        }
        
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (a[i][j] != 0) {
                    if (a[i][0] == 0 ||a[0][j] == 0) {
                        a[i][j] = 0;
                    }
                }
            }
        }
        
        if (row_zero) {
            for (int i = 0; i < n; i++) a[0][i] = 0;
        }
        if (column_zero) {
            for (int i = 0; i < m; i++) a[i][0] = 0;
        }
        
    }
};
