class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        unordered_set<string> visited;
        queue<string> qu;
        
        
        int count = 1;
        string FLAG;
        visited.insert(start);
        qu.push(start);
        qu.push(FLAG);
        
        while (!qu.empty()) {
            string word = qu.front();
            qu.pop();
            
            if (word == end) {
                return count;
            } else if (word == FLAG && !qu.empty()) {
                qu.push(FLAG);
                count++;
            } else if (!word.empty()) {
                for (int i = 0; i < start.size(); i++) {
                    string tmp = word;
                    for (char c = 'a' ;c <= 'z'; c++) {
                        tmp[i] = c;
                        if (dict.find(tmp) != dict.end() && visited.find(tmp) == visited.end()) {
                            qu.push(tmp);
                            visited.insert(tmp);
                        }
                    }
                }
            }
        }
        return 0;
    }
};
