// you are given an array of positive integers. Convert it to a sorted array
// with minimum cost, only valid operation are:
// decrement -> cost = 1;
// delete an element completely from this array ->cost = value of this element
//
// for example 4,3,5,6, ->cost 1;
// 10,3,11,12 cost 3;
//
// use c(n,m) as the cost of makeing a[1:n] into a non-decreasing
// sequence with the last element being no more than m.
//
// c(1,m) = max(a[1] - m, 0);
// c(n,m) = min(
// a[n] + c(n-1,m), // delete a[n];
// (a[n] < m ? c(n-1, a[n]): c(n-1,m)+a[n]-m;
// )
#include <climits>

int min(int *a, int n) {
  int max = INT_MIN;
  for(int i = 0; i < n; i++) {
    if(max < a[i])
      max = a[i];
  }

  int value[n][max];

  // pass 
}

