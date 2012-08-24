#include <iostream>
using namespace std;


// Given a integer array[0:n]
// this number of this array is als0
// [0:n], write a program to determine
// whether there is duplicated number in this array
// Given the time complex O(n)
// space complex O(1)
bool duplicate(int *a, int n) {
  for (int i = 0 ; i <= n; i++) {
    while (a[i] != i) {
      if (a[a[i]] == a[i]) {
        return false;
      } else {
        int temp = a[a[i]];
        a[a[i]] = a[i];
        a[i] = temp;
      }
    }
  }
  return true;
}

int main() {
  int a[] = {6,5,5,3,2,0,0};
  if (duplicate(a, 6) == true) 
    cout << "true" << endl;
  else
    cout << "false" << endl;
  return 0;
}

