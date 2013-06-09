class Solution {
public:
    int searchInsert(int a[], int n, int target) {
        int begin = -1;
        int end = n;
        while (begin+1 != end) {
            int mid = begin + (end - begin)/2;
            
            if (a[mid] <= target) {
                begin = mid;
            } else {
                end = mid;
            }
        }
        if (begin == -1) return 0;
        if (a[begin] == target) return begin;
        else return begin+1;
    }
};


class Solution {
public:
    int searchInsert(int a[], int n, int target) {
        int low = 0;
        int high = n-1;
        while (low < high) {
            int mid = low + (high-low+1)/2;
            if ( a[mid] <= target) {
                low = mid;
            } else {
                high = mid - 1;
            }
        }
        if (a[low] == target) return low;
        else if (target>a[low]) return low+1;
        else return 0;
    
    }
    
};
