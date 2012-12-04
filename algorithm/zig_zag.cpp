//    The string "PAYPALISHIRING" is written in a zigzag pattern on a given
//    number of rows like this: (you may want to display this pattern in a fixed
//    font for better legibility)
//
//    P   A   H   N
//    A P L S I I G
//    Y   I   R
//
//    And then read line by line:
//    "PAHNAPLSIIGYIR"
//
//    Write the code that will take a string and make this conversion given a number of rows:
//     string convert(string text, int nRows);convert("PAYPALISHIRING", 3)
//     should return "PAHNAPLSIIGYIR".
//
//

#include <iostream>
using namespace std;

class Solution {
 public:
  string convert(const string& s, int nRows) {
    if (n <= 0) {
      cerr << "nRows " << nRows << endl;
      abort();
    }
    if (nRows == 1) {
      return s;
    }

    string ret(s);
    int length = s.length();
    int stepmax = 2 * (nRows - 1);
    int res = 0;
    for (int i = 0; i < nRows; i++) {
      int step = 2*(nRows - i - 1);
      int begin = i;
      if (i == 0 || i == nRows -1) {
        while (begin < length) {
          ret[res++] = s[begin];
          begin += stepmax;
        }
      } else {
        while (begin < length) {
          ret[res++] = s[begin];
          begin += step;
          if (begin < length) {
            ret[res++] = s[begin];
            begin += 2 * i;
          }
        }
      }
    }
    return ret;
  }
};
