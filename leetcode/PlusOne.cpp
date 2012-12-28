class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        if (digits.size() == 0) {
            digits.push_back(1);
            return digits;
        }
        
        int size = digits.size();
        
        int i = 0;
        for (; i < size; i++) {
            if (digits[i] != 9) break;
        }
        
        if (i == size) {
            vector<int> result;
            result.push_back(1);
            for (int i = 0; i < size ; i++) result.push_back(0);
            return result;
        }
        
        int add = 1;
        for (vector<int>::reverse_iterator it = digits.rbegin(); it != digits.rend(); it++) {
            int tmp = *it + add;
            add = tmp/10 ;
            *it = tmp%10;
            if (add == 0) break;
        }
        return digits;
    }
};
