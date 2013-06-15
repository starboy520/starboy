#include <iostream>
#include <vector>
using namespace std;

vector< vector<int> > threesum(vector<int> & sum) {

    // find index which value smaller or equall to 0
    /*
    int small_equal_zero = 0;
    int great_zero = 0;
    for (int i = 0; i < sum.size(); i++) {
        if (sum[i] < 0) {
            small_equal_zero = i;
        } else if (sum[i] == 0) {
            // do nothing;
        } else {
            great_zero = i;
            break;
        }
    }
    */

    // 很多可以优化的地方
    sort(sum.begin(), sum.end());
    vector< vector<int> > re;
    // more 优化空间
    int i = 0;
    while ( i < sum.size() ) {
        int j = i+1;
        while (j < sum.size()) {
            int t = sum[i] + sum[j];
            //bs(sum, -t, j+1, sum.size());
            if (binary_search(&sum[j+1], &sum[sum.size()], -t)) {
                vector< int > curr;
                curr.push_back(sum[i]);
                curr.push_back(sum[j]);
                curr.push_back(-t);
                re.push_back(curr);
            }

            //next greate sum;
            int cu = sum[j];
            while (sum[j] == cu) {
                j++;
            }
        }
        int cu = sum[i];
        while (sum[i] == cu) {
            i++;
        }
    }
    return re;
}

int main() {
    int a[] = {-1, 0, 1, 2, -1, -4};
    vector<int> s(a, a+6);

    vector< vector<int> > re = threesum(s);

    cout << re.size() << endl;
    return 0;

}

// vim: set expandtab ts=4 sw=4 sts=4 tw=100: 
