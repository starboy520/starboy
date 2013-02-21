// given a string, split with n pieces , finds the smallest n
// to make all the substr is palindrome.

#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isPalindrome(const string& str, int begin, int end) {
    while (begin < end) {
        if (str[begin] != str[end]) return false;
        begin++;
        end--;
    }
    return true;
}

// O(N^3)
// can be done in O(n^2)
int minStepToMakePalindrome(const string& s) {
    vector<int> dp(s.size(), INT_MAX);
    for (int i = 0; i < s.size(); i++) {
        if (isPalindrome(s, 0, i)) {
            dp[i] = 0;
        } else {
            for (int j = 1; j <= i; j++) {
                if (isPalindrome(s, j, i) && dp[j-1] != INT_MAX) {
                    dp[i] = min(dp[i], dp[j-1] + 1);
                }
            }
        }
    }
    return dp[s.size()-1];
}
