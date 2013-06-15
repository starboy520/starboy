#include <iostream>
#include <climits>
#include <cassert>
using namespace std;
int noReset = INT_MAX;

// this is a more effient binary search
// we assume begin = -1 and end = n;

int binarysearch(int *a, int begin, int end, int x) {
  int b = begin;
  int e = end;
  while (begin + 1 != end) {
    int mid = begin + (end - begin) / 2;
    if (a[mid] <= x) {
      begin = mid;
    } else {
      end = mid;
    }
  }

  assert(begin + 1 == end && a[begin] <= x && a[end] > x);
  
  int p = begin;
  if (p <= b || a[p] != x) {
    p = -1;
  }
  return p;
}

// Given a sorted array, which can be rotated,
// such as [4,5,6,7,8,1,2,3]
// find the minimum numbers.which is called a reset point.

// solutions: O(n) algorithm will be very trivial
// So we need to use binary search which will give
// a O(logn) algorithm

// In this program, I assume all numbers in the array are different.
// But if there is the same numbers in this array ? such as 
// 2,3,3,4,1,1,2 how to do it?
int minNumInRotatedArrya(int *a, int begin, int end) {
    // If the array are sorted or there are only 1 or 2 element,
    // then there is no reset point.
    if (a[begin] < a[end] || end-begin == 1 || end == begin)
        return INT_MAX;

    while (begin <= end) {
        // there are left  two element,
        // such as 3,1, then will return 1;
        // this can happen when array such as 2,3,4,1,5
        if (end - begin == 1) {
            return a[begin] < a[end] ? a[begin] : a[end];
        }

        // There is at most 3 elements;
        // This can also happen such as 2,1,3,4.
        int mid = begin + (end - begin)/2;
        if (a[mid-1] > a[mid] && a[mid] < a[mid+1] )
            return a[mid];

        if (a[begin] < a[mid])
            begin = mid+1;
        else
            end = mid-1;
    }
}

// Another problem.
// How to search a num in this kind of array?
// For binary search, we need to track begin, end, mid element
// there are 4 kind of possiblities:
// begin < mid && mid < end : in this way, the array must be in a sorted status
// begin < mid && mid > end : 
// begin > mid && mid > end : this will not happen, decreased sorted status
// begin > mid && mid < end :
// so, Now we can use binary search to solve this problem
int search(int value, int *a, int begin, int end) {
    while (begin <= end) {
        int mid = begin + (end - begin)/2;
        if (value == a[mid])
            return mid;
        else if (a[begin] < a[mid]) {  // from begin to mid this is a increasing order
            if( a[begin] <= value && value < a[mid]) {
                end = mid - 1;
            } else {
                begin = mid + 1;
            }
        } else {  // from the mid to end is an increasing order
            if (a[mid] <= value && value <= a[end]) {
                begin = mid +1;
            } else {
                end = mid -1;
            }
        }
    }

    return INT_MAX;
}



void print (int *a, int begin, int end) {
    int reset = minNumInRotatedArrya(a, begin, end);
    if (reset == INT_MAX)
        cout << "no reset point in this array" << endl;
    else 
        cout << "reset point is: " << reset <<endl;
}


void test() {
    int noreset[] = {1,2,3,4};
    print(noreset, 0, 3);
    
    int rest1[] = {5,1,2,3,4};
    print(rest1, 0, 4);
    
    int reset2[] = {4,1,2,3};
    print(reset2, 0, 3);

    int reset3[] = {3,4,5,6,7,1};
    print(reset3, 0, 5);

    int reset4[] = { 3,4,5,6,7,1,2};
    print(reset4, 0, 7);
}


int main() {
    //test();
    //int a[10] = {6,7,8,9,0,1,2,3,4,5};
    //int x = search(6, a, 0, 9);
    //cout << x <<endl;

    int b[10] = {2,3,4,4,4,4,4,4,5,6};
    cout << binarysearch(b, -1, 10, 4) << endl;
    return 0;

}

