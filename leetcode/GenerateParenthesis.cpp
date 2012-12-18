class Solution {
public:

    void gen(int left, int right, char* a, int index, vector<string>& result) {
        if (left > right) return; 
        if (right == 0) {
            result.push_back(a);
            return;
        }
        
        if (left > 0) {
            a[index] = '(';
            gen(left-1, right, a, index+1, result);
        } 
        
        if (left <= right) {
            a[index] = ')';
            gen(left, right-1,a, index+1, result); 
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        if(n <= 0) return result;
        char *a  = new char[2*n+1];
        a[2*n] = '\0';
        gen(n, n, a, 0, result);
        return result;
    }
};
