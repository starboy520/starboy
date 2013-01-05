class Solution {
public:
    vector<vector<int> > com(vector<int>& sum, int begin, int end, int target) {
        vector<vector<int> > result;
        if (begin > end || target <= 0) {
            return result;
        }
        
        vector< vector<int> > tmp_result = com(sum, begin+1, end, target-sum[begin]);
        
        if (tmp_result.size() != 0) {
            for (int j = 0; j < tmp_result.size(); j++) {
                vector<int>a = tmp_result[j];
                a.push_back(sum[begin]);
                result.push_back(a);
            }
        } else {
            if (target == sum[begin]) {
                vector<int> a;
                a.push_back(sum[begin]);
                result.push_back(a);
            }
        }
        
        while (sum[++begin] == sum[begin-1]);
        
        vector< vector<int> > tmp_result1 = com(sum, begin, end, target);
        
        for (int k = 0; k < tmp_result1.size(); k++) {
            result.push_back(tmp_result1[k]);
        }
        
        return result;
    }
    
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        std::sort(num.begin(), num.end());
        vector<vector<int> > result = com(num, 0, num.size()-1, target);
        for (vector< vector<int> >::iterator it = result.begin(); it!= result.end(); it++) {
            std::sort(it->begin(), it->end());
        }
        return result;
    }
};
