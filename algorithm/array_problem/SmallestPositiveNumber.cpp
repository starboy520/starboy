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

int firstMissingPositive(int a[], int n) {
    int idx = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > 0) {
            a[idx++] = a[i];
        }
    }

    for (int i = 0; i < idx; i++) {
        if (a[i] < 0) {
            int index = -a[i];
            if (index <= idx && a[index-1] > 0) {
                a[index-1] = -a[index-1];
            }
        } else if (a[i] > idx) {

        } else {
            int index = a[i];
            if (a[index-1] > 0) {
                a[index-1] = -a[index-1];
            }
        }
    }

    for (int i = 0; i < idx; i++) {
        if (a[i] > 0) return i + 1;
    }
    return idx + 1;
}

int main() {
  int a[] = {0, 10, 2, -10, -20};
  cout << firstMissingPositive(a, 5) << endl;
}


