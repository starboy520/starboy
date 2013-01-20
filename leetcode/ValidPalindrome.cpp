class Solution {
public:
    bool isPalindrome(string s) {
        int size = 0;
        int begin = 0;
        int end = s.length() - 1;
        while (begin < end) {
            while (begin < end && !isalnum(s[begin])) {
                begin++;
            }
            while (begin < end && !isalnum(s[end])) {
                end--;
            }
            if (toupper(s[begin]) != toupper(s[end])) return false;
            begin++;
            end--;
        }
        return true;
        
    }
};
