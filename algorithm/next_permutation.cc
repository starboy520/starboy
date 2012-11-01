#include <stdio.h>
#include <algorithm>
// next_permutation algorithms:
// 1) first from the end to begin,
//    search the element, assume that the first one is fisrt
//    and the second one is next, find the first pair that 
//    first > next, it be elem
//  2) from the end search element that bigger than  elem
//  3) swap this two element
//  4) reverse the element to end

template <class Iter>
bool next_permutation1(Iter begin, Iter end) {
	if (begin == end) {
		return false;
	}

	Iter i = begin;
	++i;
	if (i == end) {
		return false;
	}

	i = end;
	--i;

	for (;;) {
		Iter ii = i;
		--i;
		if (*i < *ii) {
			Iter j = end;
			while (!(*i < *--j)){
			}

			std::swap(*i, *j);
			std::reverse(ii, end);
			return true;
		}

		if (i == begin) {
			std::reverse(begin, end);
			return false;
		}
	}
}

// prev_permutation

template <typename Iter>
bool prev_permutation(Iter begin, Iter end) {
	if (begin == end) {
		return false;
	}

	Iter i = begin;
	++i;
	if (i == end) {
		return false;
	}

	i = end;
	--i;

	for (;;) {
		Iter ii = i;
		i--;
		if (*ii < *i) {
			Iter j = end;
			while (!(*--j < *i)) {}
			std::swap(i, j);
			std::reverse(ii, end);
			return true;
		}

		if (i == begin) {
			std::reverse(begin, end);
			return false;
		}
	}

}

int main() {
	int a[3] = {1,2,3};
	bool flag = next_permutation1(a, a+3);
	if (flag) {
		for (int i = 0; i < sizeof(a)/sizeof(a[0]); i++) {
			printf("a[%d] = %d\n", i, a[i]);
		}
	}
	return 0;
}
