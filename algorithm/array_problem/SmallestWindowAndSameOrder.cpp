// Given an input array A of integers of size n, and a query array B of integers
// of size
// m, find the smallest window of input array that contains all the elements of
// query array and
// also in the same order.
// 例如:
// A = [1, 9, 3, 4, 12, 13, 9, 12, 21]
// B = [9, 12, 21]
// 那么应该返回A[6..8] = [9, 12, 21]
//

#include <iostream>
#include <climits>
#include <map>
using namespace std;

struct Pair {
  int q;
  int i;
};

int SmallestWindow(int* input_array, int n, int* query_array, int m) {
  int best[] = {-1, -1, INT_MAX};

  map<int, Pair> M;

  for (int i = 0; i < m; i++) {
    Pair p;
    p.i = -1;
    p.q = i;
    M[ query_array[i] ] = p;
  }

  for (int i = 0; i < n; i++) {
    if (M.find(input_array[i]) == M.end()) continue;

    Pair curPaire = M[input_array[i]];
    if (curPaire.q == 0) {
      curPaire.i = i;
      continue;
    }

    curPaire.i = M[input_array[curPaire.q - 1]].i;

    if (curPaire.i == m-1 && curPaire.i != -1 &&
        i - curPaire.i < best[2]) {
      best[0] = curPaire.i;
      best[1] = i;
      best[2] = i - curPaire.i;
    }
  }

  return best[2];
}
