class Solution {
public:
    bool isMatch(const char *s, const char *p) {
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
      if (*s == *p || *p == '?') {
        ++s;++p;
      } else {
          if (hasAsterisk == false) return false;
        s = ++ss; p = sp;
      }
    }

    // if string not exist, check if rest pattern is either empty or only
    // contains asteisks
    if (*s == '\0') {
      return isMatch(s, p);
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

    return (*p == '*')? true : false;
  }

  return true;
}

};
