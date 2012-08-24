// how to merge two sorted arrays provided not to use a third array nor you can allocate
// extra space try to optimize the problem to the best, time complexity should be less than O(n^2)

// algorithm:
//    just see the code.
#include <stdio.h>
#include <algorithm>
using namespace std;

void rotateRight(int*a, int s, int e, int step) {
  if (NULL == a || s > e-1)
    return;

  //step %= e-s;

  if (step == 0) 
    return;

  reverse(a, s, e-step);
  reverse(a, e-step, e);
  reverse(a, s, e);
}



void sortedListMerge(int* a, int num, int mid) {
    if (NULL == a || mid > num || 0 >= mid)
        return ;
    
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
