#include <iostream>
using namespace std;

// produce a zig-zag array. A zig-zag array is a square arrangement
// of the first N^2 integers, where the numbers increase sequentially as you zigzag along the anti-diagonals of the array.
// for a graphical representation, see jpg zigzag.
// For example give 5, produce this array
// 0  1  5  6  14
// 2  4  7  13 15 
// 3  8  12 16 21
// 9  11 17 20 22
// 10 18 19 23 24
#define NUM 4
#include <cstdio>
void arrays(int (*a)[NUM], int n) {
  int current = 0;
  for (int i = 0; i < 2*n-1; i++) {
    if ( i%2 == 0) {
      for (int k = 0; k <= i; k++) {
        if (k <= n-1 && i-k <= n-1) 
          a[i-k][k] = current++;
      }
    } else {
      for (int k = 0; k <= i; k++) {
        if (k <= n-1 && i-k <= n-1)
          a[k][i-k] = current++;
      }
    }
  }
}

int main() {
  int a[NUM][NUM] = {0};
  arrays(a, NUM);
  for (int i = 0; i < NUM;i++) {
    for (int j = 0; j < NUM; j++) {
      printf("%d ", a[i][j]);
    }
    printf("\n");
  }
  return 0;
}

