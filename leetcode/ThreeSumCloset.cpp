//
//  Given an array S of n integers,
//  find three integers in S such that the sum is closest to a given number, target. 
//  Return the sum of the three integers. 
//  You may assume that each input would have exactly one solution.

class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        // std::sort(num.begin(),  num.end());
        int result = 111111;
        int size = num.size();
        for (int i = 0; i < size; i++) {
            for (int j = i+1; j < size; j++) {
                for (int k = j+1; k < size; k++) {
                    int m = num[i] + num[j] + num[k];
                    if (m == target) {
                        return m;
                    }
                    if (abs(target-m)  < abs(target-result)) {
                        result = m;
                    }
                }
            }
        }
        return result;
    }
};

#include <iostream>
using namespace std;
int main() {

}
