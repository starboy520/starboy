//
// Distinct Subsequences
// Given a string S and a string T, count the number of distinct subsequences of
// T in S.
//
// A subsequence of a string is a new string which is formed from the original
// string by deleting some (can be none) of the characters without disturbing
// the relative positions of the remaining characters. (ie, "ACE" is a
// subsequence of"ABCDE" while "AEC" is not).
//
// Here is an example:
// S = "rabbbit", T = "rabbit"
//
// Return 3.
//
// Dynamic programming: f(x,y) is defines as the num of (S[0]~S[x])'s
// subsequences of (T[0]~T[y])
//
// Then we got if(S[x]==S[y]) f(x,y)=f(x-1,y)+f(x-1,y-1) else f(x,y)=f(x-1,y)
//
//
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        int t_size = t.size();
        int s_size = s.size();
        int result[t_size];
        for (int i = 0; i < t_size; i++) {
            result[i] = 0;
        }

        for (int i = 0; i < s_size; i++) {
            for (int j = t_size-1; j>= 0; j--) {
                if (t[j] == s[i]) {
                    if (j == 0) result[j]++;
                    else result[j] += result[j-1];
                }
                
            }
            
        }
        return result[t_size-1];
        
    }
};
// class Solution {
//
//  public:
//   int numDistinct(string s, string t) {
//     if (s.size() > t.size())
//       return 0;
//
//     int size_s = s.size();
//     int size_tt = t.size();
//
//     vector<int> last;
//     for (int i = 0; i < size_s; i++) {
//       if (last.empty())
//         last.push_back(s[i] == t[0]);
//       else {
//         last.push_back(last.back() + (s[i] == t[0]));
//       }
//     }
//
//     for (int i = 1; i < size_tt; i++) {
//       vector<int> next;
//       next.push_back(0);
//       for (int j = 1; j < size_s; j++) {
//         int tmp = next.back();
//         if (s[j] == t[i]) {
//           tmp+=last[j-1];
//         next.push_back(tmp);
//         }
//       }
//       last = next;
//     }
//     return last.back();
//   }
// };
