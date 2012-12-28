class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        stack<int> tmp;
        int maxars = 0;
        int i = 0;
        int size = height.size();
        while (i < size) {
            if (tmp.empty() || tmp.top() <= height[i]) {
                tmp.push(height[i]);
                i++;
            } else {
                int count = 0;
                while ( (!tmp.empty()) && tmp.top() > height[i]) {
                    count++;
                    int top = tmp.top();
                    tmp.pop();
                    maxars = std::max(maxars, count*top);
                }
                for (int j = 0; j < count+1; j++) {
                    tmp.push(height[i]);
                }
                i++;
            }
        }
        int count = 0;
        while (!tmp.empty()) {
            count++;
            maxars = std::max(maxars, tmp.top()*count);
            tmp.pop();
        }
        return maxars;
    }
};
