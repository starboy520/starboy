class Solution {
public:
    int maxArea(vector<int> &height) {
        int i = 0; 
        int j = height.size()-1;
        int maxar = 0;
        while (i < j) {
            int temp = (j-i)*min(height[i], height[j]);
            maxar = max(maxar, temp);
            if (height[i] <= height[j]) i++;
            else j--;
        }
        return maxar;
    }
};
