class Solution {
public:
    void rotate(vector<vector<int> > &a) {
        int size = a.size();
        for (int i = 0; i < size/2; i++) {
            for (int j = i; j < size-i-1; j++) {
                int tmp = a[j][size-1-i];
                a[j][size-1-i] = a[i][j];
                int tmp2 = a[size-1-i][size-1-j];
                a[size-1-i][size-1-j] = tmp;
                int tmp3 = a[size-1-j][i];
                a[size-1-j][i] = tmp2;
                a[i][j] = tmp3;
            }
        }
    }
};
