class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        std::sort(num.begin(), num.end());
        int i = 0;
        int j = 0;
        int k = 0;
        vector< vector<int> > result;

        int size = num.size();
        if (size <= 3) return result;

        while (i < size) {
            j = i+1;
            while (j < size) {
                k = j+1;
                while (k < size) {
                    int s = target - num[i] - num[j] - num[k];
                    if (s < num[k]) break;
                    bool flag = binary_search(num.begin()+k+1, num.end(), s);
                    if (flag) {
                        vector<int> tmp;
                        tmp.push_back(num[i]);
                        tmp.push_back(num[j]);
                        tmp.push_back(num[k]);
                        tmp.push_back(s);
                        result.push_back(tmp);
                    }
                    while (++k < size && num[k] == num[k-1]);
                }
                while (++j < size && num[j] == num[j-1]);
            }
            while (++i < size && num[i] == num[i-1]);
        }
        return result;
    }
};

#ifndef SOLUTION_H_
#define SOLUTION_H_
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

class Solution{
public:
        struct TwoSum{
                int sum;
                int x,y;
        };

        struct TwoSumComp{
                bool operator()(const TwoSum& ts1, const TwoSum& ts2){
                        return ts1.sum < ts2.sum;
                }
        };
        vector<vector<int> > fourSum(vector<int>& num,int target){
                if(num.size() < 4)
                        return vector<vector<int> >();


                vector<TwoSum> twoSums;
                TwoSum tmpTS;
                size_t nNum = num.size();
                for(size_t i=0;i<(nNum-1);i++){
                        for(size_t j=i+1;j<nNum;j++){
                                tmpTS.sum = num[i]+num[j];
                                tmpTS.x = i;
                                tmpTS.y = j;
                                twoSums.push_back(tmpTS);
                        }
                }

                sort(twoSums.begin(),twoSums.end(),TwoSumComp());

                size_t nts = twoSums.size();
                size_t h = 0,t = nts-1;

                set<vector<int> > results;
                vector<int> r(4);
                while(h<t){
                        int tmpSum = twoSums[h].sum + twoSums[t].sum;
                        if(tmpSum == target){
                                size_t ht = h+1;
                                while((ht<t) && (twoSums[ht].sum == twoSums[h].sum)) ht++;
                                size_t tt = t-1;
                                while((tt>=ht)&&(twoSums[tt].sum == twoSums[t].sum)) tt--;
                                for(size_t i = h;i<ht;i++){
                                        for(size_t j = t;j>tt;j--){
                                                if(!checkIndexRepeat(twoSums[i],twoSums[j])){
                                                        r[0] = num[twoSums[i].x];
                                                        r[1] = num[twoSums[i].y];
                                                        r[2] = num[twoSums[j].x];
                                                        r[3] = num[twoSums[j].y];
                                                        sort(r.begin(),r.end());
                                                        results.insert(r);
                                                }
                                        }
                                }
                                h = ht;
                                t = tt;
                        }
                        else if(tmpSum > target){
                                t--;
                        }
                        else{
                                h++;
                        }
                }

                return vector<vector<int> >(results.begin(),results.end());

        }

        bool checkIndexRepeat(const TwoSum& ts1, const TwoSum& ts2){
                return (ts1.x == ts2.x) || (ts1.x == ts2.y)
                        || (ts1.y == ts2.x) || (ts1.y == ts2.y);
        }
};
#endif

