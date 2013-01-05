class Solution {
public:
    string longestPalindrome(string s) {
        int size = s.length();
        if (size == 0) {
            return "";
        }
        
        int begin = 0;
        int end = 0;
        int max_len = 1;
        
        bool a[size][size];
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                a[i][j] = false;
            }
        }
        
        for (int i = 0; i < size; i++) {
            a[i][i] = true;
        }
        
        for (int i = 0; i < size-1; i++) {
            if (s[i] == s[i+1])  {
                a[i][i+1] = true;
                begin = i;
                end = i+1;
                max_len = 2;
            }
        }
        
        for (int d = 2; d <=size-1; d++) {
            for (int i = 0; i < size-d; i++) {
                if (s[i] == s[i+d] && a[i+1][i+d-1] == true) {
                    a[i][i+d] = true;
                    if (d > max_len-1) {
                        max_len = d+1;
                        begin = i;
                        end = i+d;
                    }
                }
            }
        }
        string tmp = s.substr(begin, max_len);
        return tmp;
    }
};
