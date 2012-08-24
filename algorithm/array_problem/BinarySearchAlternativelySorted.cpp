// Given an array which is alternatively sorted.
// Find an element in it.
// e.g. 12,2,16,5,18,32,33,38
#include <stdio.h>
int binary_search(int* a, int begin, int end, int value) {
	//first search even position
	int first = begin;
	int last = end;

	if (begin % 2 == 1)
		first++;
	if (end % 2 == 1)
		last--;

	while (first <= last) {
		int mid = first + (last-first)/2;
		if (mid %2 == 1)
			mid++;
		if (mid > last)
			break;
		if (a[mid] == value) {
			return mid;
		} else if (a[mid] < value) {
			first = mid + 2;
		} else {
			last = mid - 2;
		}
	}

	//search odd position
	first = begin;
	last = end;
	if (begin % 2 == 0)
		first++;
	if (end % 2 == 0)
		last--;

	while (first <= last) {
		int mid = first + (last-first)/2;
		if (mid %2 == 0)
			mid++;
		if (mid > last)
			break;
		if (a[mid] == value) {
			return mid;
		} else if (a[mid] < value) {
			first = mid + 2;
		} else {
			last = mid - 2;
		}
	}

	return -1;
}


int main() {
	int arr[] = {12,2,16,5,18,32,33,34,39};
	int index = binary_search(arr, 0, 8, 34);
	printf("%d\n", index);

}
