class Solution {
public:
    int longestValidParentheses(string s) {
        int size = s.size();
        int max_len = 0;
        int begin = size;
        stack<int> st;
        int len = 0;
        
        for (int i = 0; i < size; i++) {
            if (s[i] == '(') {
                st.push(i);
                continue;
            } else {
                if (st.empty()) {
                    begin = size;
                } else {
                    begin = min(begin, st.top());
                    st.pop();
                    if (st.empty()) {
                        len = i - begin+1;
                    } else {
                        len = i - st.top();
                    }
                }
                max_len = max(max_len, len);
            }
        }
        return max_len;
        
    }
};

/**
 * 
class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length();
        vector<int> dp(n, 0);
        
        int m = 0;
        for (int i = n-2; i >= 0; i--) {
            if (s[i] == '(') {
                int j = i+1 + dp[i+1];
                if (j < n && s[j] ==')') {
                    dp[i] = dp[i+1]+2;
                    if (j +1 < n) {
                        dp[i] += dp[j+1];
                    }
                }
                m = max(m, dp[i]);
            }
        }
        return m;
    }
};

*/
