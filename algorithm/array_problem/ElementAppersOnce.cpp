// Given an array where every element occurs three times, except one element which occurs only once. Find the element that occurs once. Expected time complexity is O(n) and O(1) extra space.
// Examples:

// Input: arr[] = {12, 1, 12, 3, 12, 1, 1, 2, 3, 3}
// Output: 2

// algorithm : sum bits in the same position for all numbers and take modulo 3. the bits for which sum is not multiple of 3 are the bits of numebers with single occurrences.
//
// Let us consider the example array {5, 5, 5, 8}. The 101, 101, 101, 1000
// Sum of first bits%3 = (1 + 1 + 1 + 0)%3 = 0;
// Sum of second bits%3 = (0 + 0 + 0 + 0)%0 = 0;
// Sum of third bits%3 = (1 + 1 + 1 + 0)%3 = 0;
// Sum of fourth bits%3 = (1)%3 = 1;
// Hence number which appears once is 1000

#include <stdio.h>
const static int INT_SIZE = 8 * sizeof(int);

int getSingle(int * arr, int n) {
	if (arr == NULL) {
        return -1;
    }
    
    int result = 0;
 
    int x, sum;
    for (int i = 0; i < INT_SIZE; i++) {
        sum = 0;
        x = (1 << i);
        for (int j = 0; j < n; j++) {
            if (arr[j] & x)
                sum++;
        }
        
        if (sum % 3)
            result |= x;

    }

    return result;
}




int main()
{
	    int arr[] = {12, 1, 12, 3, 12, 1, 1, 2, 3, 2, 2, 3, 7};
		int n = sizeof(arr) / sizeof(arr[0]);
		printf("The element with single occurrence is %d ",
				getSingle(arr, n));
		return 0;
}
