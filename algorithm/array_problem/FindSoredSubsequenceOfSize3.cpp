// Given an array of n integers find 3 elements such 
// a[i] < a[j] < a[k] for i < j < k
// if there are multiple such triplets then print any one of them
// example:
//
// Input array[] = { 12, 11, 10, 5, 6, 2, 30 }
// Output: 5,6,30
// 
// Input array[] = {4, 3, 2, 1}
// Output : No such triplet
#include <stdio.h>
void printTriplet(int* array, int n) {
  int* smaller = new int[n];
  smaller[0] = -1;
  int min = 0;
  for (int i = 1; i < n; i++) {
    if (array[i] <= array[min]) {
      min = i;
      smaller[i] = -1;
    } else {
      smaller[i] = min;
    }
  }

  int* greater = new int[n];
  greater[n-1] = -1;
  int max = n-1;
  for (int i = n-2; i >= 0; i--) {
    if (array[i] >= array[max]) {
      max = i;
      greater[i] = -1;
    } else {
      greater[i] = max;
    }
  }

  for (int i = 1; i < n; i++) {
    if (smaller[i] != -1 && greater[i] != -1) {
      printf("%d %d %d\n", array[smaller[i]], array[i], array[greater[i]]);
      return;
    }
  }

  printf("No such triplet found");
  delete[] smaller;
  delete[] greater;

};

int main() {
  int a[] = {12, 11, 10, 5, 6, 2, 30};
  printTriplet(a, 7);
  return 0;
}

