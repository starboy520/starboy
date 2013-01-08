class Solution {
public:
    bool check(int* a, int cur) {
        for (int i = 1; i < cur; i++) {
            if (a[i] == a[cur] || a[i] - a[cur] == i - cur ||
                a[i] - a[cur] == cur - i) {
                    return false;
                }
        }
        return true;
    }
    
    void output(int* a, int n , vector<vector<string> >&result) {
        vector<string> tmp;
        for (int i = 1; i <= n; i++) {
            string t(n, '.');
            t[a[i]-1] = 'Q';
            tmp.push_back(t);
        }
        result.push_back(tmp);
    }
    
    void queen(int*a, int cur, int n, vector<vector<string> >&result) {
        if (cur > n) {
            output(a, n, result);
            return;
        }
        
        for (int i = 1; i <= n; i++) {
            a[cur] = i;
            if (check(a, cur)) {
                queen(a, cur+1, n, result);
                
            }
            a[cur] = 0;
        }
    }
    
    vector<vector<string> > solveNQueens(int n) {
        int *a = new int[n+1];
        memset(a, 0, sizeof(int)*(n+1));
        
        vector<vector<string > > result;
        
        queen(a, 1, n, result);
        return result;
    }
};
