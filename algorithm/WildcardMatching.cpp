
#include <iostream>
using namespace std;

bool isMatch(const char* s, const char* p) {
    if (*p == '\0' && *s == '\0') {
        return true;
    }

    if (*p == '\0' && (*s != '\0')) {
        return false;
    }

    if (*s == '\0' && *p != '*') {
        return false;
    }


    if ((*p != '*') && (*p != '?')) {
        if (*p == *s) {
            return isMatch(s+1, p+1);
        } else {
            return false;
        }
    } else if (*p == '?') {
        return isMatch(s+1, p+1);
    } else {
        if (isMatch(s, p+1)) {
            return true;
        } else {
            if (*s != '\0') {
                return isMatch(s+1, p) || isMatch(s+1, p+1);
            }
        }
    }
    return false;
}

int main() {
  char s[] = "babaaababaabababbbbbbaabaabbabababbaababbaaabbbaaab";
  char p[] = "***bba**a*bbba**aab**b";
  if (isMatch(s, p)) {
    cout << "yes" << endl;
  } else {
    cout << "no" << endl;
  }
  return 0;
}
