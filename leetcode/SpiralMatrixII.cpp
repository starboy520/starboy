class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > result(n, vector<int>(n, 0));
        
        int i = 0;
        int j = 1;
        while (i < (n+1)/2) {
            for (int t = i; t < n-i; t++) {
                result[i][t] = j++;
            }
            
            for (int t = i+1; t < n-i; t++) {
                result[t][n-i-1] = j++;
            }
            
            if (n-i-1 > i) {
                for (int t = n-i-2; t > i; t--) result[n-i-1][t] = j++;
            }
            
            if (n-i-1 > i) {
                for (int t = n-i-1; t > i; t--) result[t][i] = j++;
            }
            i++;
        }
        return result;
    }
};
