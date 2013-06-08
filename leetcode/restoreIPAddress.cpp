class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        if (s.size() > 12) return result;
        vector<string> tmp(4);
        restore(s, 0, s.length()-1, 0, tmp, result);
        
        return result;
    }
    
    void restore(string& s, int begin, int end, int index, vector<string>& cur, vector<string>& result) {
        if (index == 4) {
            if (begin <= end) return ;
            string tmp = cur[0] + "." + cur[1] + "." + cur[2] + "." + cur[3];
            result.push_back(tmp);
        }
        
        for (int i = begin; i <= end; i++) {
            string tmp = s.substr(begin, i-begin+1);
            if (isValid(tmp)) {
                cur[index] = tmp;
                restore(s, i+1, end, index+1, cur, result);
            }
        }
    }
    
    bool isValid(string s) {
        if (s[0] == '0') return s.length() == 1;
        int t = atoi(s.c_str());
        return t>=0 && t <=255;
    }
};
