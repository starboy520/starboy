class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int size = prices.size();

        if (size == 0 || size == 1) return 0;

        vector<int> smaller(size);
        vector<int> bigger(size);

        int min = prices[0];
        for (int i = 1; i < size; i++) {
            min = std::min(min, prices[i]);
          smaller[i] = std::max(smaller[i-1], prices[i] - min);
        }

        int max = prices[size - 1];
        for (int i = size-2; i >= 0; i--) {
        	max = std::max(max, prices[i]);
        	bigger[i] = std::max(bigger[i+1], max - prices[i]);
        }

        int sum = 0;
        for (int i = 0; i < size; i++) {
        	sum = std::max(sum, smaller[i] + bigger[i]);

        }
        return sum;
    }
};