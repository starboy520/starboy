#include <iostream>
using namespace std;
#include <algorithm>

int ugly_number(int k) {
  int i2 = 0;
  int i3 = 0;
  int i5 = 0;

  int* ugly = new int[k];

  ugly[0] = 1;
  int i = 1;
  for (i = 1; i < k; i++) {
    while(ugly[i2] * 2 <= ugly[i-1]) {
      i2++;
    }
    while (ugly[i3] * 3 <= ugly[i-1]) {
      i3++;
    }
    while (ugly[i5] * 5 <= ugly[i-1]) {
      i5++;
    }

    ugly[i] = min(min(ugly[i2]*2, ugly[i3]*3), ugly[i5]*5);
  }
  int num = ugly[k-1];
  delete[] ugly;
  ugly = NULL;
  return num;
}

int main() {
  int k = 10;
  cout << ugly_number(k) << endl;
