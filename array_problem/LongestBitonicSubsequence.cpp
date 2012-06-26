// Given an array arr[0 ... n-1] containing n positive integers,
// a subsequence of arr[] is called Bitonic if it is first increasing,
// then decreasing. Write a function that takes an array as argument and
// returns the length of the longest bitonic subsequence.
// A sequence, sorted in increasing order is considered Bitonic with the decreasing part as empty.
// Similarly, decreasing order sequence is considered Bitonic with the increasing part as empty.
//

#include <stdio.h>
int lbs(int* array, int n) {
  int* lis = new int[n];
  for (int i = 0; i < n; i++) {
    lis[i] = 1;
  }

  for (int i = 1; i < n; i++) {
    for (int j = 0; j < i; j++) {
      if (array[i] > array[j] &&lis[i] < lis[j] + 1) {
        lis[i] = lis[j] + 1;
      }
    }
  }

  int* lds = new int[n];
  for (int i = 0; i < n; i++) {
    lds[i] = 1;
  }

  for (int i = n-2; i >= 0; i--) {
    for (int j = n-1; j > i; j--) {
      if (array[i] > array[j] && lds[i] < lds[j] + 1) {
        lds[i] = lds[j] + 1;
      }
    }
  }

  int max = lis[0] + lds[0] -1;
  for (int i = 1; i < n; i++) {
    if (lis[i] + lds[i] - 1 > max) {
      max = lis[i] + lds[i] -1;
    }
  }

  delete[] lis;
  delete[] lds;
  return max;
}


int main() {
  int arr[] = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
  int n = sizeof(arr)/sizeof(arr[0]);
  printf("Length of LBS is %d\n", lbs( arr, n ) );
  return 0;
}
