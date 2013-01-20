// [Microsoft] 一个String当中,求出现多于一次的最长的substring。
// eg: "abcabcaacb" -> "abc"
// eg: "aababa" -> "aba"

// suffix array problem

#include <string>
#include <iostream>
#include <algorithm>

using namespace std;
int find(const string& s1, const string& s2) {
  int i = 0;
  int len1 = s1.length();
  int len2 = s2.length();

  int len = len1 < len2 ? len1:len2;

  while (i < len) {
    if (s1[i] != s2[i]) break;
    i++;
  }
  return i;
}

string MaxLength(string s) {
  int len = s.length();
  if (len < 1) return "";

  string* t = new string[len];
  for (int i = 0; i < len; i++) {
    t[i] = s.substr(i, len-i);
  }

  std::sort(t, t + len);

  int max = 0;
  string m;
  for (int i = 0; i < len-1; i++) {
    int l = find(t[i], t[i+1]);
    if (l>max) {
      max = l;
      m = t[i].substr(0, l);
    }
  }
  return m;
}

int main() {
  string s1 = "abcabcaacb";
  string s2 = "aababa";
  string t = MaxLength(s1);
  string m = MaxLength(s2);
  cout << t << endl;
  cout << m << endl;
  return 0;
}
