//给两个ascend排序的integer array,找出他们的union,并且descend排序。
//

#include <vector>
#include <climits>
using namespace std;

vector<int> Union(vector<int> a, vector<int> b) {
  int size1 = a.size();
  int size2 = b.size();
  int i = size1-1;
  int j = size2-1;
  vector<int> result;

  while (i>=0 || j>=0) {
    while (i > 0 && a[i-1] == a[i]) i--;
    while (j > 0 && b[j-1] == b[j]) j--;

    int av = i >= 0 ? a[i] : INT_MAX;
    int bv = j >= 0 ? b[i] : INT_MAX;
    if (av < bv) {
      result.push_back(bv);
      j--;
    } else if (av > bv) {
      result.push_back(av);
      i--;
    } else {
      result.push_back(av);
      i--;j--;
    }
  }
  return result;
}
