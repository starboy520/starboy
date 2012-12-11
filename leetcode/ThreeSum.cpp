// Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? 
// Find all unique triplets in the array which gives the sum of zero.
// Note:
// Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
// The solution set must not contain duplicate triplets.

#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    vector< vector<int> > threeSum(vector<int> &num) {

        vector< vector<int>  > all_result;
        
        if (num.size() == 0) {
            return all_result;
        }
        std::sort(num.begin(), num.end());

        vector<int>::iterator ll_begin_iter = num.begin();
        vector<int>::iterator ll_end_iter = num.end();
        ll_end_iter--;


        while (ll_begin_iter < ll_end_iter) {

            vector<int>::iterator ll_temp = ll_begin_iter;

            while (ll_temp < ll_end_iter) {
                bool flag = std::binary_search(ll_temp+1, ll_end_iter, -(*ll_temp + *ll_end_iter));
                if (flag) {
                    vector<int> temp;
                    temp.push_back(*ll_temp);
                    temp.push_back(-(*ll_temp + *ll_end_iter));
                    temp.push_back(*ll_end_iter);
                    all_result.push_back(temp);
                }
                    
                int value = *ll_temp;
                while (value == *++ll_temp) {
                     ;
                 }

            }

            int end_value = *ll_end_iter;
            while (end_value == *--ll_end_iter) {
                ;
            }
        }
        
        return all_result;
    }

};
