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
