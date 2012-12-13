//
//
// ven two integers n and k, return all possible combinations of k numbers out of 1 ... n.
//
// For example,
// If n = 4 and k = 2, a solution is:
//
// [
//   [2,4],
//   [3,4],
//   [2,3],
//   [1,2],
//   [1,3],
//   [1,4],
// ]

class Solution {
 public:
  vector<vector<int> > combine(int n, int k) {
    vector<vector<int> > result;
    if (k > n || k < 0) {
      return result;
    }

    if (k == n) {
      vector<int> temp;
      for (int i = 1; i <=n ;i++) {
        temp.push_back(i);
      }
      result.push_back(temp);
      return result;
    }

    vector<vector<int> > temp = combine(n-1, k);
    result.insert(result.begin(), temp.begin(), temp.end());

    vector<vector<int> > temp1 = combine(n-1, k-1);

    for (vector<vector<int> >::iterator it = temp1.begin(); it != temp1.end(); ++it) {
      it->push_back(n);
    }
    result.insert(result.begin(), temp1.begin(), temp1.end());

    return result;
  }

};
