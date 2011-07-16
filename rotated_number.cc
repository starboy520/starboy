#include <iostream>
using std::endl;
using std::cout;
#include <climits>
// Given a sorted array, which can be rotated,
// such as [4,5,6,7,8,1,2,3]
// find the minimum numbers.which is called a reset point.

// solutions: O(n) algorithm will be very trivial
// So we need to use binary search which will give
// a O(logn) algorithm


int noReset = INT_MAX;


// In this program, I assume all numbers in the array are different.
//
// But if there is the same numbers in this array ? such as 
int minNumInRotatedArrya(int *a, int begin, int end) {
    // If the array are sorted or there are only 1 or 2 element,
    // then there is no reset point.
    if (a[begin] < a[end] || end-begin == 1 || end == begin)
        return INT_MAX;

    while (begin <= end) {
        // there are left one or two element,
        // such as 3,1, then will return 1;
        // this can happen when array such as 2,3,4,1,5
        // if (end == begin)
        //    return a[end];

        if (end - begin == 1) {
            return a[begin] < a[end] ? a[begin] : a[end];
        }

        // There is at most 3 elements;
        // This can also happen such as 2,1,3,4.
        int mid = begin + (end - begin)/2;
        if (a[mid-1] > a[mid] && a[mid] < a[mid+1] )
            return a[mid];

        if (a[begin] < a[mid])
            begin = mid+1;
        else
            end = mid-1;
    }
}

void print (int *a, int begin, int end) {
    int reset = minNumInRotatedArrya(a, begin, end);
    if (reset == INT_MAX)
        cout << "no reset point in this array" << endl;
    else 
        cout << "reset point is: " << reset <<endl;
}


void test() {
    int noreset[] = {1,2,3,4};
    print(noreset, 0, 3);
    
    int rest1[] = {5,1,2,3,4};
    print(rest1, 0, 4);
    
    int reset2[] = {4,1,2,3};
    print(reset2, 0, 3);

    int reset3[] = {3,4,5,6,7,1};
    print(reset3, 0, 5);

    int reset4[] = { 3,4,5,6,7,1,2};
    print(reset4, 0, 7);
}


int main() {
    test();
}

