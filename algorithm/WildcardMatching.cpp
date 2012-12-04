#include <iostream>
using namespace std;

bool isMatch(const char* s, const char* p) {

  if ((*p == '\0') && (*s == '\0')) {
    return true;
  } else if (
      ( (*p == '\0') && (*s != '\0')) ) {
    return false;
  } else {
    if ((*p != '*') && (*p != '?')) {
      if (*p == *s) {
        return isMatch(s+1, p+1);
      } else {
        return false;
      }
    } else if (*p == '?') {
      return isMatch(s+1, p+1);
    } else {
      return (isMatch(s, p+1) || isMatch(s+1, p) || isMatch(s+1, p+1));
    }
  }
  return false;
}

int main() {
  char s[] = "aaab";
  char p[] = "a*b";
  if (isMatch(s, p))
    cout << "yes" << endl;

  return 0;
}
