class Solution {
public:
    int factorial(int n) {
        if (n == 0) return 1;
        int result = 1;
        for (int i = 1; i <= n; i++) result *= i;
        return result;
    }
    
    string getPermu(vector<int>& num, int k) {
        int size = num.size();
        if (size == 1 && k == 0 ) {
            return string(1, num[0]+'0');
        }
        
        int fac = factorial(size-1);
        int f = k / (fac);
        
        string s(1, num[f]+'0');
        num.erase(num.begin()+f);
        return s+getPermu(num, k-f*fac);
    }
    
    string getPermutation(int n, int k) {
        vector<int> num;
        for (int i = 1; i <= n; i++) num.push_back(i);
        return getPermu(num, k-1);
    }
};
