#include <iostream>
#include <cassert>
using namespace std;

int normalBinarySearch(int*a, int n, int target) {
    int begin = 0; int end = n-1;
    while (begin <= end) {
        int mid = begin + (end - begin)/2;
        if (a[mid] == target) {
            return mid;
        } else if (a[mid] > target) {
            end = mid - 1;
        } else {
            begin = mid + 1;
        }
    }
    return -1;
}

// Search in a sorted array, find a value > target
int binarySearchUpperWithoutBound(int*a, int n, int target) {
    if (a[n-1] <= target) {
        return -1;
    }

    int begin = 0;
    int end = n-1;
    while (begin < end) {
        int mid = begin + (end - begin)/2;
        if (a[mid] <= target) {
            begin = mid + 1;
        } else {
            end = mid;
        }
    }
    return end;
}

// Search in a sorted array, find a value >= target
// if has a value == target, return the left most;
int binarySearchUpperWithBoundLeftMost(int*a, int n, int target) {
    if (a[n-1] < target) {
        return -1;
    }

    int begin = 0;
    int end = n-1;
    while (begin < end) {
        int mid = begin + (end - begin)/2;
        if (a[mid] < target) {
            begin = mid + 1;
        } else {
            end = mid;
        }
    }
    return end;
}

// Search in a sorted array, find a value >= target
// if has a value == target, return the right most;
//
//int binarySearchUpperWithBoundRightMost(int*a, int n, int target) {
//    // TODO
//}

// Search in a sorted array, find a value < target
int binarySearchLowerWithoutBound(int*a, int n, int target) {
    if (a[0] >= target) {
        return -1;
    }

    int begin = 0;
    int end = n-1;
    while (begin < end) {
        int mid = begin + (end - begin+1)/2; // be carefully.
        if (a[mid] >= target) {
            end = mid - 1;
        } else {
            begin = mid;
        }
    }
    return begin;
}

// Search in a sorted array, find a value <= target
int binarySearchLowerWithBound(int*a, int n, int target) {
    if (a[0] > target) {
        return -1;
    }

    int begin = 0;
    int end = n-1;
    while (begin < end) {
        int mid = begin + (end - begin+1) / 2; // be carefully.
        if (a[mid] > target) {
            end = mid - 1;
        } else {
            begin = mid;
        }
    }
    return begin;
}

int main() {
    // add test
}
