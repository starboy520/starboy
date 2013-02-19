#include <string>
#include <unordered_set>
using namespace std;

/*
    public int ladderLength(String start, String end, HashSet<String> dict) {
         if (start == null || end == null || start.length() != end.length())
             return 0;
         int dist = 1;
         HashSet<String> used = new HashSet<String>();
         HashSet<String> cur = new HashSet<String>();
         cur.add(start);
         while(!cur.isEmpty()) {
             HashSet<String> newCur = new HashSet<String>();
             dist++;
             for (String s : cur) {
                 char[] str = s.toCharArray();
                 for (int i = 0; i < str.length; i++) {
                     for (int j = 0; j < 26; j++) {
                         if (str[i] != (char)('a' + j)) {
                             char temp = str[i];
                             str[i] = (char)('a' + j);
                             String candidate = new String(str);
                             if (candidate.equals(end))
                                 return dist;
                             if (!used.contains(candidate) && dict.contains(
 candidate)) {
                                 newCur.add(candidate);
                                 used.add(candidate);
                             }
                             str[i] = temp;
                         }
                     }
                 }
             }

             cur = newCur;
         }

         return 0;
     }

*/

class Solution {
	public:
		int ladderLength(string start, string end, unordered_set<string> dict) {
			if (start == "" || end == "" || start.length() != end.length()) {
				return 0;
			}

			int dist = 1;
			unordered_set<string> used;
			unordered_set<string> cur;
			cur.insert(start);

			while (!cur.empty()) {
				unordered_set<string> newCur;
				dist++;

				for (unordered_set<string>::iterator it = cur.begin(); it != cur.end(); it++) {
					for (int i = 0; i < (*it).size(); i++) {
						for (int j = 0; j < 26; j++) {
							if ((*it)[i] != ('a' + j)) {
								string s = *it;
								char temp = s[i];
								s[i] = ('a' + j);
								if (s == end) return dist;
								if (used.find(s) == used.end() && dict.find(s) != dict.end()) {
									newCur.insert(s);
									used.insert(s);
								}
								s[i] = temp;
							}
						}
					}
				}
				cur = newCur;
			}
			return 0;
		}
};
