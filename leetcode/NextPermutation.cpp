class Solution {
public:
    void nextPermutation(vector<int> &num) {
        int size = num.size();
        if (size == 0 || size == 1) return;
        int end = size -1;
        while (end-1 >= 0 && num[end-1] >= num[end]) {
            end--;
        }
        if (end == 0) {
            std::reverse(num.begin(), num.end());
            return ;
        }
        int c = end-1;
        end = size -1;
        while (num[c] >= num[end]) {
            end--;
        }
        std::swap(num[c], num[end]);
        std::reverse(num.begin() + c + 1, num.end());
    }
};
