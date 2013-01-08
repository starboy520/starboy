class Solution {
public:

    void swap(int *a, int i, int j) {
        int tmp = a[i];
        a[i] = a[j];
        a[j] = tmp;
    }
    void sortColors(int a[], int n) {
        int begin = 0;
        int i = 0;
        int end = n-1;
        while (i <= end) {
            if (a[i] == 0) {
                swap(a, i, begin);
                i++;
                begin++;
            } else if (a[i] == 2) {
                swap(a, i, end);
                end--;
            } else {
                i++;
            }
        }
    }
};
