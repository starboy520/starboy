class Solution {
public:
    int minCut(string s) {
        vector<vector<bool> > result(s.size(), vector<bool>(s.size(), false));
        
        for (int i = 0; i < s.size(); i++) {
            result[i][i] = true;
        }
        
        for (int i = 0; i < s.size()-1; i++) {
            if (s[i] == s[i+1]) {
                result[i][i+1] = true;
            }
        }
        
        int size = s.size();
        for (int d = 2; d < size; d++) {
            for (int i = 0; i < size-d; i++) {
                if (s[i] == s[i+d] && result[i+1][i+d-1] == true) {
                    result[i][i+d] = true;
                }
            }
        }
        
        vector<int> dp(s.size(), 0);
        int tmp;
        for (int i = 0; i < s.size(); i++) {
            if (result[0][i]) {
                dp[i] = 0;
                continue;
            } else {
                tmp = i;
            }
            
            for (int j = 0; j < i; j++) {
                if (result[j+1][i]) {
                    tmp = min(tmp, dp[j] + 1);
                }
            }
            dp[i] = tmp;
        }
        return dp[s.size()-1];
        
    }
};
