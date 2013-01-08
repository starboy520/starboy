class Solution {
public:
    void merge(int a[], int m, int b[], int n) {
        int k = m+n;
        int i = m-1;
        int j = n-1;
        while (i >= 0 && j >= 0) {
            if (a[i] >= b[j]) {
                a[--k] = a[i];
                i--;
            } else {
                a[--k] = b[j];
                j--;
            }
        }
        while (i >= 0) {
            a[--k] = a[i--];
        }
        
        while (j >= 0) {
            a[--k] = b[j--];
        }
    }
};
