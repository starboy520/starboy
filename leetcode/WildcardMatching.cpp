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


/*

class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
         
        const char* star=NULL;
        const char* ss=s; 
        while (*s){
            if ((*p=='?')||(*p==*s)){s++;p++;continue;}
            if (*p=='*'){star=p++; ss=s;continue;}
            if (star){ p = star+1; s=++ss;continue;}
            return false;
        }
        while (*p=='*'){p++;}
        return !*p;
    }
};
*/

/*
class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (*p == '*'){//return true;
            while(*p == '*') ++p;
            if (*p == '\0') return true;
            while(*s != '\0' && !isMatch(s,p)){
                ++s;                
            }
            return *s != '\0';
        }
        else if (*p == '\0' || *s == '\0') return *p == *s;
        else if (*p == *s || *p == '?') return isMatch(++s,++p);
        else return false;
    }
};
*/
