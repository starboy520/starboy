class Solution {
public:
    bool isValid(string s) {
        int size = s.length();
        if (size % 2 == 1) return false;
        
        stack<char> st;
        int i = 0;
        while (i < size) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                st.push(s[i]);
            } else {
                if (st.empty()) {
                    return false;
                }
                if (s[i] == ')' && st.top() != '(') return false;
                if (s[i] == ']' && st.top() != '[') return false;
                if (s[i] == '}' && st.top() != '{') return false;
                st.pop();
            }
            i++;
        }
        
        return st.empty() == true;
    }
};
