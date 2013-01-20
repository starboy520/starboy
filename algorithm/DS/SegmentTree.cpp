#include <iostream>
#include <cassert>
using namespace std;

class SegmentTree {
public:
 SegmentTree(int* original, int nums);

 // i:index in the array,
 // value : new value in this index
 void updateValue(int i, int value);

 int querySumOfSegment(int begin, int end) {
   return getSum(0, n-1, begin, end, 0);
 }

private:
 int* a;
 int n;

 int* seg;

 // map value:index in the origianl array
 // std::map<int, int> index_map;

 // begin : start index of the  array;
 // end : end index of the array;
 // index: current index in the segmentree;
 int construct_segment_tree(int begin, int end, int index);

 // begin : start index of the array
 // end : end index of the array
 // i : the ith element of this array
 // diff : new value - a[i]
 // index : index in the segment tree
 void updateValueInternal(int begin, int end, int i, int diff, int index);

 // [first, last] sum of subarray in a;
 int getSum(int begin, int end, int first, int last, int index);

};

SegmentTree::SegmentTree(int* original, int nums) {
  assert(nums > 0 && original != NULL);
  n = nums;
  a= new int[nums];
  for (int i = 0; i < n; i++) a[i] = original[i];
  seg = new int[2*nums+1];

  construct_segment_tree(0, nums-1, 0);
}

void SegmentTree::updateValue(int index, int value) {
  if (index < 0 || index > n-1) return ;
  int diff = value - a[index];

  a[index] = value;
  updateValueInternal(0, n-1, index, diff, 0);
}

int SegmentTree::construct_segment_tree(int begin, int end, int index) {
  if (begin > end || index >= 2*n+1) return 0;

  if (begin == end) {
    seg[index] = a[begin];
    return a[begin];
  }

  int mid = begin + (end - begin)/2;
  seg[index] = construct_segment_tree(begin, mid, 2*index+1) +
      construct_segment_tree(mid+1, end, 2*index+2);
  return seg[index];
}


void SegmentTree::updateValueInternal(int begin, int end, int i, int diff, int index) {
  if (i <begin || i > end || index >= 2*n+1) return ;
  if (index >= n) return;
  seg[index] += diff;
  if (begin != end) {
    int mid = begin + (end - begin) / 2;
    updateValueInternal(begin, mid, i, diff, 2*index+1);
    updateValueInternal(mid+1, end, i, diff, 2*index+2);
  }
}

int SegmentTree::getSum(int begin, int end, int first, int last, int index) {
  if (index >= 2*n+1) return 0;
  if (first <= begin &&  last >= end) return seg[index];
  if (last < begin || first > end) return 0;

  int mid = begin + (end - begin)/2;
  return getSum(begin, mid, first, last, 2*index+1) +
      getSum(mid+1, end, first, last, 2*index+2);
}


int main() {
  int a[] = {1, 3, 5, 7, 9, 11, 12};
  int n = sizeof(a) / sizeof(a[0]);
  SegmentTree t(a, n);

  int s = t.querySumOfSegment(5, 6);

  cout << s << endl;

}
