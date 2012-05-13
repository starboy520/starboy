//数组a[0, mid-1] 和 a[mid, num-1] 对数组a[0, num-1] 的两个子有序进行merge, 得到a[0, num-1]有序, 空间复杂度为o(1)
//
#include <stdio.h>
#include <algorithm>
using namespace std;

void reversed(int* a, int s, int e) {
  if (NULL == a || s > e-1)
    return;

  e = e - 1;
  while (s < e) {
    int k = s;
    s = e;
    e = k;
    s++;
    e--;
  }
}

void rotateRight(int*a, int s, int e, int step) {
  if (NULL == a || s > e-1)
    return;

  step %= e-s;

  if (step == 0) 
    return;

  reversed(a, s, e-step);
  reversed(a, e-step, e);
  reversed(a, s, e);
}



void sortedListMerge(int* a, int num, int mid) {
  if (NULL == a || mid > num || 0 >= mid) return ;

  int i = 0;
  int j = mid;

  while (i < num) {
    while (a[i] < a[j]) {
      i++;
    }
    
    int step = j;

    while (a[j] < a[i]) {
      j++;
    }

    step = j - step;

    rotateRight(a, i, j, j-step);
  }

}





