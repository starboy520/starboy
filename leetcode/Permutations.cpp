class Solution {
public:
    vector<vector<int> > permu(vector<int> num, int begin, int end) {
        
        if (begin == end) {
            vector<vector<int> >result;
            vector<int> a;
            a.push_back(num[begin]);
            result.push_back(a);
            return result;
        }
        
        vector<vector<int> > result;
        for (int i = begin ; i<= end; i++) {
            swap(num[begin], num[i]);
            
            vector<vector<int> > tmp_result = permu(num, begin+1, end);
            for (vector<vector<int> >::iterator it = tmp_result.begin(); it != tmp_result.end(); it++) {
                it->push_back(num[begin]);
                result.push_back(*it);
            }
            swap(num[begin], num[i]);
        }
        return result;
    }
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int> > result;
        int size = num.size();
        return permu(num, 0, size-1);
    }
};


   

