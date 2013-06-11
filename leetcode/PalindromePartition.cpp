class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<bool>> palindrome = isPalindrome(s);
        
        return partitionHelper(s, 0, s.length()-1, palindrome);
    }
    
    vector<vector<string> > partitionHelper(const string& s, int begin, int end, vector<vector<bool> >& helper) {
        vector<vector<string> > result;
        if (begin > end) {
            return result;
        }
        
        for (int i = begin; i <= end; i++) {
            if (helper[begin][i]) {
                string t = s.substr(begin, i-begin+1);
                vector<vector<string> > tmp = partitionHelper(s, i+1, end, helper);
                if (tmp.size() !=0) {
                    for (vector<vector<string> >::iterator it = tmp.begin(); it != tmp.end(); it++) {
                        it->insert(it->begin(), t);
                        result.push_back(*it);
                    }
                } else {
                    if (i == end) {
                        vector<string> tmp;
                        tmp.push_back(t);
                        result.push_back(tmp);
                    }
                }
            }
        }
        return result;
    }
    
    vector<vector<bool> > isPalindrome(string& s) {
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
        return result;
    }
};
