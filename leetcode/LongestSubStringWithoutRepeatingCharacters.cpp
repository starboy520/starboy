class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int size = s.length();
        if (size == 0) return 0;
        
        int a[256];
        for (int i = 0; i < 256; i++) a[i] = -1;
        
        int begin = 0;
        
        a[s[0]] = 0;
        
        int len = 0;
        int i = 1;
        while (i < size) {
            if (a[s[i]] == -1) {
                a[s[i]] = i;
            } else {
                len = max(len, i - begin);
                int temp = a[s[i]];
                begin = a[s[i]]+1;
                a[s[i]] = i;
                for (int i = 0; i < 256; i++) {
                    if (a[i] != -1 && a[i] < temp) a[i] = -1;
                }
                
            }
            i++;
        }
        len = max(len, i-begin);
        return len;
    }
};
