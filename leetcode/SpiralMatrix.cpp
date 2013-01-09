class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> result;
        
        int m = matrix.size();
        if (m == 0) return result;
        
        int n = matrix[0].size();
        if (n == 0) return result;
        
        int min_index = std::min(m, n);
        
        int i = 0;
        while ( i < (min_index+1)/2) {
            for (int j = i; j < n-i; j++) {
                result.push_back(matrix[i][j]);
            }
            
            for (int j = i+1; j < m-i; j++) {
                result.push_back(matrix[j][n-i-1]);
            }
            
            
            if (m-i-1 > i) {
                for (int j = n-i-2; j >= i; j--) {
                    result.push_back(matrix[m-i-1][j]);
                }
            }
            
            if (n-i-1 > i) {
                for (int j = m-i-2; j > i; j--) {
                    result.push_back(matrix[j][i]);
                }
            }
            i++;
        }
        
        return result;
    }
};
