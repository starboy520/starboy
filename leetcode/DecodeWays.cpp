//  A message containing letters from A-Z is being encoded to numbers using the following mapping:
//
// 'A' -> 1
// 'B' -> 2
// ...
// 'Z' -> 26
//
// Given an encoded message containing digits, determine the total number of ways to decode it.
//
// For example,
// Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).
//
// The number of ways decoding "12" is 2.
//
#include <iostream>
using namespace std;

class Solution {
public:
int numDecodings(string s) {
  int size = s.length();
  if (size == 0)
    return 0;
  if (size == 1) {
    if ( (s[0] - '0') == 0) {
      return 0;
    }
    return 1;
  }

  int len1 = 1;
  int len2 = 1;
  int a = s[size-2] - '0';
  int b = s[size-1] - '0';
  int d = a * 10 + b;
  if (a == 0) {
    len1 = 0;
    if (b == 0) {
      len2 = 0;
    }
  } else {
    if (b == 0) {
      if (a>=3) {
          len1 = 0;
          len2 = 0;
      } else {
        len1 = 1;
        len2 = 0;
      }
    } else {
        if (d<=26 && d>=10) {
            len1= 2;
            len2 = 1;
        } else {
            len1 = 1;
            len2 = 1;
        }
     }
  }

  for (int j = size-3; j >= 0; j--) {
    int a1 = s[j] - '0';
    int a2 = s[j+1] - '0';
    int temp1 = 0;
    int temp2 = 0;
    if (a1 == 0) {
      len2 = len1;
      len1 = 0;
      continue;
    } else {
      temp1 = 1;
      int t = a1*10 +a2;
      if (t>=10 && t<=26) {
        temp2 = 1;
      }
      int k_tmp = len1;
      len1 = temp1 * len1 + temp2 * len2;
      len2 = k_tmp;
    }
  }
  return len1;
}


};
