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
