// Given an array that contains both positive and negative integers, find the product of the maximum product subarray. Expected Time complexity is O(n) and only O(1) extra space can be used
//
//Input: arr[] = {6, -3, -10, 0, 2}
//Output:   180  // The subarray is {6, -3, -10}
//
//Input: arr[] = {-1, -3, -10, 0, 60}
//Output:   60  // The subarray is {60}
//
//Input: arr[] = {-2, -3, 0, -2, -40}
//Output:   80  // The subarray is {-2, -40}
//

#include <iostream>
#include <algorithm>
using namespace std;

int maxSubArrayProduct(int* arr, int n) {
    if (arr == NULL || n <= 0) {
        return -1;
    }

    int max_here = 1;
    int min_here = 1;
    int max_all;

    for (int i = 0; i < n; i++) {
        if (arr[i] > 0) {
            max_here = max_here * arr[i];
            min_here = min(1, min_here*arr[i]);
        } else if (arr[0] == 0) {
            max_here = 1;
            min_here = 1;
        } else {
            int temp = max_here;
            max_here = max(min_here*arr[i], 1);
            min_here = temp * arr[i];
        }
        max_all = max(max_all, max_here);
    }
    return max_all;
}
_
