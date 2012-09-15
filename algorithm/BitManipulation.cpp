#include <limits.h>
#include <stdio.h>

/*
void test {
	// compute sign of the value
	int v;
	int sign;
	sign = -(v < 0);
	// or to avoid branching on CPU with flag registers
	sign = -(int)((unsigned int)((int)v) >> (sizeof(int) * CHAR_BIT-1));

	// or for one less instruction (but not protable)
	sign = v >> (sizeof(int)* CHAR_BIT-1);

	//detected if two integers have opposite sign
	int x;
	int y;
	bool f = ( (x^y)< 0);

	// compute the integer absolue value without branching
	int v;
	unsigned int r;
	int const mask = v >> sizeof(int) * CHAR_BIT-1;
	r = (v + mask) ^ mask;  // I do not understand this one
	r = (v ^ mask) - mask; // if v < 0, mask = -1; asb(v) = (v^mask) +1
	                       // = abs(v) = (v^mask) - mask;

	// compute the min or max value of two 
	int x;
	int y;
	int r;
	// if x < y the -(x < y) will be -1( binary presentation is all 1)
	// so r = y ^ ( (x ^ y)&~0 )
	// r = y ^ (x^y) = x;
	// if x > y then -(x < y) will be 0, then r = y ^ ((x^y)&0) = y
	//
	r = y ^ ((x^y) & -(x < y));

	// to find max
	r = x ^ ((x^y) & -(x<y));


	r = y + ( (x-y) & ((x-y) >> (sizeof(int) * CHAR_BIT - 1)) );
	r = x - ( (x-y) & ((x-y) >> (sizeof(int) * CHAR_BIT - 1)) );

	//determining if an integer is a power of 2
	unsigned int v;
	bool f;
	f = (v & (v-1)) == 0;
	f = v && !(v & (v-1));
	
	// count bits set
	unsigned int v;
	unsigned int c;
	for (c = 0; v; v >>= 1) {
		c += v & 1;
	}
*/

/*
	// count bits set by lookup table
	static const unsigned char BitsSetTable[256] = {
#define B2(n) n, n+1, n+2
#define B4(n) B2(n), B2(n+1), B2(n+2)
#define B6(n) B4(n), B4(n+1), B4(n+2)
		B6(0), B6(1), B6(2)
	}

	c = BitsSetTable[v & 0xff] +
		BitsSetTable[(v>>8) & 0xff] +
		BitsSetTable[(v>>16) & 0xff] +
		bitsSetTable[v>>24];
*/
/*
	unsigned int v;
	unsigned int c;
	for (c = 0, v; c++) {
		v &= v - 1;
	}

	unsigned int v;
	unsigned int r = v;
	int s = sizeof(v) * CHAR_BIT -1;
	for (v >>= 1; v; v >>= 1) {
		r << 1;
		r | = v & 1;
		s--;
	}
	r <<= s;
}

dd*/

// swapping values using xor
void swap(int& a, int& b) {
	a ^= b;
	b ^= a;
	a ^= b;
}

template <typename It>
bool next_permutation(It begin, It end) {
	if (begin == end) {
		return false;
	}

	It i = begin;
	++i;
	if (i == end) {
		return false;
	}

	i = end;
	--i;

	while (true) {
		It j = i;
		if (*i < *j) {
			It k =end;
			while (!(*i < *--k)) {
				;
			}
			iter_swap(i, k);
			reverse(j, end);
			return true;
		}

		if (i == begin) {
			reverse(begin ,end);
			return false;
		}
	}
}
// Given an integer, 
// 1: print the next smaller and next larger number
// that have the same number of 1 bits in their binary representation

// the problem is equivalent to pick k bits out of n bits, just enumerate
// next combination

// http://www.sureinterview.com/shwqst/40004
//
// bit operation:
//     remove last set bit	:	i&(i-1)
//     get last set bit		:	i&~(i-1)
//     remote the trailing 0:	i / (i&(i-1))
//
//	10011100
//	00011100 - right most string of 1's in x
//	00000011 - right shifted pattern except left most bit ------> [A]
//	00010000 - isolated left most bit of right most 1's pattern
//	00100000 - shiftleft-ed the isolated bit by one position ------> [B]
//	10000000 - left part of x, excluding right most 1's pattern ------> [C]
//	10100000 - add B and C (OR operation) ------> [D]
//	10100011 - add A and D which is required number 163'''
//
int greater(int num) {
  int lastSetBit = num & ~(num-1);
  int largerNum = num + lastSetBit;

  int fb = num^largerNum;
  int lastBit = fb/lastSetBit;
  lastBit >>= 2;
  largerNum |= lastBit;
  return largerNum;
}

// unsigned int t = v | (v -1);
// w = (t + 1) | (((~t & -~t) >> (__builtin_ctz(v) + 1)));
//
int main() {
	int s  = 6;
	printf("%d\n", greater(6));
}
