class Solution {
public:
    bool isScramble(string s1, string s2) {
     return isScrambleHelper(s1, 0, s1.size()-1, s2, 0, s2.size()-1);   
    }
    
    bool isScrambleHelper(string& s1, int begin, int end, string& s2, int first, int last) {
        
        //if (begin > end) return false;
        if (end==begin) {
            return s1[begin] == s2[first];
        }
        
        if (end - begin != last -first) {
            return false;
        }
        
        int t = begin;
        for (; t <= end; t++) {
            if (s1[t] != s2[first + t-begin]) break;
        }
        
        if (t > end) return true;
        
        int a[256] = {0};
        for (int i = begin; i <= end; i++) {
            a[s1[i]]++;
        }
        for (int i = first; i <= last; i++) {
            a[s2[i]]--;
        }
        for (int i = 0; i < 256; i++) {
            if (a[i] != 0) return false;
            
        }
        
        for (int i = begin; i < end; i++) {
            if (isScrambleHelper(s1, begin, i, s2, first, first+i-begin) &&
                isScrambleHelper(s1, i+1, end, s2, first+i-begin+1, last)) {
                    return true;
            }
                
            if (isScrambleHelper(s1, begin, i, s2, last-i+begin,  last) &&
                isScrambleHelper(s1, i+1, end, s2, first, end-i-1+first)) {
                    return true;
            }
        }
        return false;
    }
};
