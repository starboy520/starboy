class Solution {
public:
    string minWindow(string s, string t) {
        int t_sz = t.size();
        int s_sz = s.size();
        if (t_sz == 0|| t_sz > s_sz) return "";
        
        int need[256] = {0};
        int doing[256] = {0};
        
        
        for (int i = 0; i < t_sz; i++) {
            need[t[i]]++;
        }
        
        int count = 0;
        int begin = 0;
        int max_window = INT_MAX;
        int w_begin = 0;
        int w_end = 0;
        
        for (int i = 0; i < s_sz; i++) {
            if (need[s[i]] == 0) {
                continue;
            }
            doing[s[i]]++;
            
            if (doing[s[i]] <= need[s[i]]) {
                count++;
            }
            
            if (count == t_sz) {
                while (need[s[begin]] == 0 || doing[s[begin]] >need[s[begin]]) {
                    if (doing[s[begin]] > need[s[begin]]) {
                        doing[s[begin]]--;
                    }
                    begin++;
                }
                int windows = i - begin+1;
                if (windows < max_window) {
                    max_window = windows;
                    w_begin = begin;
                    w_end = i;
                    
                }
            }
        }
        if (count != t_sz) return "";
        return s.substr(w_begin, max_window);
    }
};
