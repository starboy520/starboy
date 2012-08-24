// You are given an unsorted array with both positive
// and negative elements.
// You have to find the smallest positive number missing
// from the array in O(n) time using constant extra space.
// You can modify the original array.
// Example:
// Input: {2, 3, 7, 6, 8, -1, -10, 15}
// Output: 1
// Input: {2,3,-7,6,8,1, -10, 15}
// Output: 4

// Solution: 
#include <iostream>
using namespace std;

int ChangePositiveRight(int* a, int n) {
  if (a == NULL) {
    return -1;
  }

  int j = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] <= 0) {
      int temp = a[i];
      a[i] = a[j];
      a[j] = temp;
      j++;
    }
  }
  return j;
}

int abs(int a) {
  if (a < 0) {
    return -a;
  }

  return a;
}

int findMissingPositive(int* a, int n) {
  for (int i = 0; i < n; i++) {
    if (abs(a[i]) -1 < n && a[abs(a[i])-1] > 0) {
        a[abs(a[i])-1] = -a[abs(a[i])-1];
    }
  }

  for (int i = 0; i < n; i++) {
    if (a[i] > 0) {
      return i+1;
    }
  }

  return n+1;
}

int findMissing(int* a, int n) {
  int index = ChangePositiveRight(a, n);
  return findMissingPositive(a+index, n-index);
}

int main() {
  int a[] = {0, 10, 2, -10, -20};
  cout << findMissing(a, 5) << endl;
}


