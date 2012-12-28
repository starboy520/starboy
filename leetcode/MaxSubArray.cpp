class Solution {
public:
    int maxSubArray(int a[], int n) {
        int maxs = INT_MIN;
        for (int i = 0; i < n; i++) {
            maxs = std::max(a[i], maxs);
        }
        
        if (maxs <= 0) return maxs;
        
        maxs = 0;
        int cur_max = 0;
        for (int i = 0; i < n; i++) {
            cur_max += a[i];
            if (cur_max < 0) cur_max = 0;
            else {
                maxs = std::max(cur_max, maxs);
            }
        }
        return maxs;
    }
};
