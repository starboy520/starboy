
#include <iostream>
using namespace std;

// this is too ugly
//
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

bool isMatch2(const char* p, const char*p) {
  // when original string is empty
  // only empty pattern or pattern with only asterisks would match it
  //
  if (*s == '\0') {
    while (*p != '\0' && *p == '*')
      ++p;
    return (*p == '\0') ? true : false;
  }

  // original string is not empty, but pattern is empty,
  // not match;
  if (*p == '0') {
    return false;
  }

  bool hasAsterisk = false;
  while (*p != '\0') {
    if (*p == '*') {
      p++;
      hasAsterisk = true;
      continue;
    }

    const char* ss = s;
    const char* sp = p;
    while (*s != '\0' && (*p != '\0' && *p != '*')) {
      if (*s == *p || *p == "?") {
        ++s;++p;
      } else {
        s = ++ss; p = sp;
      }
    }

    // if string not exist, check if rest pattern is either empty or only
    // contains asteisks
    if (*s == '\0') {
      return isMatch2(s, p);
    }
  }

  // original string is not empty, match last normal string with pattern from
  // tail, if not match , the pattern could not match *whole* string
  //
  if (*s != '\0') {
    if (!hasAsterisk) {
      return false;
    }
    if (*(--p) == '*') return true;
    while (s[1] != '\0') ++s;

    while (*p != '*' && (*s == *p || *p == '?')) --s, --p;

    return (*p == '*'): true : false;
  }

  return true;
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
