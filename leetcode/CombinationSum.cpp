class Solution {
 public:
  vector< vector<int> > combinations(vector<int>& candidate, int begin, int end, int target) {
    vector< vector<int> > result;
    if (begin > end || target <= 0) {
			return result;
		}

		for (int i = 0; i * candidate[begin] <= target; i++) {
			vector< vector<int> > temp = combinations(candidate, begin+1, end, target-i*candidate[begin]);
			if (temp.size() != 0) {
				for (int j = 0; j < temp.size(); j++) {
					vector<int>a = temp[j];
					for (int t = 0; t < i; t++) {
						a.push_back(candidate[begin]);
					}
					result.push_back(a);
				}
			} else {
				if (target == (i *candidate[begin])) {
					vector<int> a;
					for (int j = 0; j < i; j++) {
						a.push_back(candidate[begin]);
					}
					result.push_back(a);
				}
			}
		}
		return result;
	}

	vector< vector<int> > combinationSum(vector<int>& candidates, int target) {
          vector< vector<int> > result = combinations(candidates, 0, candidates.size()-1, target);
          for (vector< vector<int> >::iterator it = result.begin(); it!=result.end();it++) {

              std::sort(it->begin(), it->end());
          }
          return result;
	}
};
