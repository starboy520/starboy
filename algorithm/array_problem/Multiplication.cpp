// There is an array A[N] of N numbers.
// You have to compose an array Output[N] such that Output[i]
// will be equal to multiplication of all the elements of A[N] except A[i].
// For example Output[0] will be multiplication of A[1] to A[N-1] and
// Output[1] will be multiplication of A[0] and from A[2] to A[N-1].
//
// Solve it without division operator and in O(n).
#include <iostream>
using namespace std;
void multiplication(int* a, int n, int * output) {
  int foward[n];
  foward[0] = 1;
  for (int i = 1; i < n; i++) {
    foward[i] = foward[i-1]*a[i-1];
    cout << foward[i] << endl;
  }

  int reverse[n];
  reverse[n-1] = 1;
  for (int i =  n-2; i >= 0; i--) {
    reverse[i] = reverse[i+1] * a[i+1];
    cout << foward[i] << endl;
  }

  for (int i = 0; i < n; i++) {
    output[i] = foward[i] * reverse[i];
  }

}

void funct(int* a, int size, int* output) {
  long result = 1;
  for (int i = 0; i < size; i++) {
    output[i] = result;
    result *= a[i];
  }

  result = 1;
  for (int i = size-1; i >= 0; i--) {
    output[i] *= result;
    result *= a[i];
  }
}

int main() {
  int a[4] = {1,2,3,4};
  int b[4];
  multiplication(a, 4, b);
  cout << b[0] << " "  << b[1] <<" " << b[2] << " "  << b[3] << endl;
  return 0;
}
