class Solution {
public:
    int search_left(int *a, int n, int target) {
        int left = -1;
        int right = n;
        int mid;
        while (left + 1 != right) {
            mid = left  + (right - left)/2;
            if (a[mid] < target) {
                left = mid;
            } else {
                right = mid;
            }
        }
        if (right >= n || a[right] != target) right = -1;
        return right;
    }
    
    int search_right(int *a, int n, int target) {
        int left = -1;
        int right = n;
        int mid;
        while (left + 1 != right) {
            mid = left  + (right - left)/2;
            if (a[mid] > target) {
                right = mid;
            } else {
                left = mid;
            }
        }
        if (left < 0 || a[left] != target) left = -1;
        return left;
    } 
    
    vector<int> searchRange(int a[], int n, int target) {
        vector<int> result;
        if (a == NULL || n <= 0) return result;
        
        int left = search_left(a, n, target);
        
        int right = search_right(a, n, target);
        
        if (left < 0 || right < 0) {
            left = -1;
            right = -1;
            result.push_back(left);
            result.push_back(right);
            return result;
            
        } else {
            result.push_back(left);
            result.push_back(right);
            return result;
        }
    }
};
