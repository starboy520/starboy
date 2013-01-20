#include <iostream>
#include <cstring>
using namespace std;

int getEditDistance(const char* s1, const char* s2) {
  if (s1 == NULL || s2 == NULL) return -1;

  int len1 = strlen(s1);
  int len2 = strlen(s2);

  int distance[len1+1][len2+1];

  for (int i=0; i < len1+1; i++) {
    distance[i][0] = i;
  }

  for (int j = 0; j < len2+1; j++) {
    distance[0][j] = j;
  }

  for (int i = 1; i <= len1; i++) {
    for (int j = 1; j <= len2; j++) {
      if (s1[i-1] == s2[j-1]) distance[i][j] = distance[i-1][j-1];
      else distance[i][j] = std::min(std::min(distance[i-1][j],distance[i][j-1]),
                                distance[i-1][j-1])+1;
    }
  }
  return distance[len1][len2];
}

int main() {
  const char* s1 = "SUNDAY";
  const char* s2 = "SATURDAY";
  cout << getEditDistance(s1, s2) << endl;
  return 0;
}
