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


class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        int len = height.size();
        vector<int> left(len, 0);
        vector<int> right(len, 0);
        
        for (int i = 0; i < len; i++) {
            left[i] = i;
            while (left[i] >= 1 && height[left[i]-1] >= height[i]) {
                left[i] = left[left[i]-1];
            }
        }
        
        for (int i = len-1; i >= 0; i--) {
            right[i] = i;
            while (right[i] <= len-2 && height[i] <= height[right[i]+1]) {
                right[i] = right[right[i]+1];
            }
        }
        
        int m = 0;
        for (int i = 0; i < len; i++) {
            int area = (right[i] - left[i]+1) * height[i];
            m = max(m, area);
        }
        return m;
    }
};
