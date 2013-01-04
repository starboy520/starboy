//  Given two binary strings, return their sum (also a binary string).
//
//  For example,
//  a = "11"
//  b = "1"
//  Return "100".
//


#include <string>

string addBinary(string a, string b) {
  std::reverse(a.begin(), a.end());
  std::reverse(b.begin(), b.end());

  string result;
  int size_a = a.size();
  int size_b = b.size();

  int min = std::min(size_a, size_b);
  int i = 0;
  int add = 0;
  while (i < min) {
    int c = (a[i] - '0') + (b[i] - '0') + add;
    result.append(1, c%2+'0');
    add = c/2;
    i++;
  }

  while (i < size_a) {
    int c = a[i] - '0' + add;
    result.append(1, c%2+'0');
    add = c/2;
    i++;
  }

  while (i < size_b) {
    int c = b[i] - '0' + add;
    result.append(1, c%2 + '0');
    add = c/2;
    i++;
  }

  while (add != 0) {
      result.append(1, add%2 + '0');
      add = add/2;
  }
  std::reverse(result.begin(), result.end());

  return result;
}
