 #include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <cassert>
#define MAX 1000
using namespace std;


class Solution {
public:
double findMedianBaseCase(int med, int C[], int n) {
  if (n == 1)
    return (med+C[0])/2.0;
 
  if (n % 2 == 0) {
    int a = C[n/2 - 1], b = C[n/2];
    if (med <= a)
      return a;
    else if (med <= b)
      return med;
    else /* med > b */
      return b;
  } else {
    int a = C[n/2 - 1], b = C[n/2], c = C[n/2 + 1];
    if (med <= a)
      return (a+b) / 2.0;
    else if (med <= c)
      return (med+b) / 2.0;
    else /* med > c */
      return (b+c) / 2.0;
  }
}
 
double findMedianBaseCase2(int med1, int med2, int C[], int n) {
  if (n % 2 == 0) {
    int a = (((n/2-2) >= 0) ? C[n/2 - 2] : INT_MIN);
    int b = C[n/2 - 1], c = C[n/2];
    int d = (((n/2 + 1) <= n-1) ? C[n/2 + 1] : INT_MAX);
    if (med2 <= b)
      return (b+max(med2,a)) / 2.0;
    else if (med1 <= b)
      return (b+min(med2,c)) / 2.0;
    else if (med1 >= c)
      return (c+min(med1,d)) / 2.0;
    else if (med2 >= c)
      return (c+max(med1,b)) / 2.0;
    else  /* a < med1 <= med2 < b */
      return (med1+med2) / 2.0;
  } else {
    int a = C[n/2 - 1], b = C[n/2], c = C[n/2 + 1];
    if (med1 >= b)
      return min(med1, c);
    else if (med2 <= b)
      return max(med2, a);
    else  /* med1 < b < med2 */
      return b;
  }
}
 
double findMedianSingleArray(int A[], int n) {
  assert(n > 0);
  return ((n%2 == 1) ? A[n/2] : (A[n/2-1]+A[n/2])/2.0);
}
 
double findMedianSortedArrays(int A[], int m, int B[], int n) {
  assert(m+n >= 1);
  if (m == 0)
    return findMedianSingleArray(B, n);
  else if (n == 0)
    return findMedianSingleArray(A, m);
  else if (m == 1)
    return findMedianBaseCase(A[0], B, n);
  else if (n == 1)
    return findMedianBaseCase(B[0], A, m);
  else if (m == 2)
    return findMedianBaseCase2(A[0], A[1], B, n);
  else if (n == 2)
    return findMedianBaseCase2(B[0], B[1], A, m);
 
  int i = m/2, j = n/2, k;
  if (A[i] <= B[j]) {
    k = ((m%2 == 0) ? min(i-1, n-j-1) : min(i, n-j-1));
    assert(k > 0);
    return findMedianSortedArrays(A+k, m-k, B, n-k);
  } else {
    k = ((n%2 == 0) ? min(m-i-1, j-1) : min(m-i-1, j));
    assert(k > 0);
    return findMedianSortedArrays(A, m-k, B+k, n-k);
  }
}
};
