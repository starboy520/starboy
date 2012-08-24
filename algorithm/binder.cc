// Given a sorted array, 
// output all triplets <a,b,c> such that a-b = c.  // here it just means that a = b + c
// Expected time is O(n^2). 
// When you attempt an approach, test your code with this example 
// and list your outputs for verification.
// -12, -7, -4, 0, 3, 5, 9, 10, 15, 16
#include <iostream>
using namespace std;
void binder(int*a, int n) {
  for (int i = 0; i < n; i++) {
    int current = a[i];
    int left = 0;
    int right = n-1;
    while (left < right) {
      if ( left == i ) {
        left++;
        continue;
      }

      if (right == i) {
        right--;
        continue;
      }

      if (a[left] + a[right] < current) {
        left++;
      } else if (a[left] + a[right] > current) {
        right--;
      } else {
        cout << current << " = " << a[left] << " + " << a[right] <<endl;
        left++;
        right--;
      }
    }
  }
}

int main() {
  int a[] = {-12, -7, -4, 0, 3, 5, 9, 10, 15, 16};
  binder(a, 10);
  return 0;
}
