class Solution {
public:
    string simplifyPath(string path) {
        int size= path.size();
        stack<string> st;
        
        int i = 0;
        
        while (i < size) {
            while (i < size && path[i] == '/') i++;
            int begin = i;
            
            while (i < size && path[i] != '/') i++;
            int end = i;
            string tmp = path.substr(begin, end-begin);
            if (i == size) {
                tmp = path.substr(begin, end-begin+1);
            }
            if (tmp == "." || tmp == "") {
                continue;
            } else if (tmp == "..") {
                if (!st.empty()) st.pop();
            } else {
                st.push(tmp);
            }
        }
        if (st.empty()) {
            return "/";
        }
        
        string result = "";
        
        while (!st.empty()) {
            string tmp = st.top();
            tmp = string("/") + tmp;
            result = tmp + result;
            st.pop();
        }
        return result;

    }
};
