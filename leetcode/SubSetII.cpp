class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function            
        vector<int> path;
        vector<vector<int> > result;

        sort(S.begin(), S.end());
        sub(S, 0, path, result);
        return result;
    }

    void sub(vector<int> &s, int begin, vector<int> &path, vector<vector<int> > &result) {
        result.push_back(path);

        for (int i = begin; i < s.size(); ++i) {
            if (i != begin && s[i] == s[i - 1]) continue;

            path.push_back(s[i]);
            sub(s, i + 1, path, result);
            path.pop_back();
        }
    }
};
