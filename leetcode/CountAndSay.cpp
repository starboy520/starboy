#include <iostream>
#include <string>
using namespace std;

string countAndSay(int n) {
  // Start typing your C/C++ solution below
  // DO NOT write int main() function
    if (n == 1) {
        return "1";
    }

    string result = "1";
    for (int i = 2; i <= n; i++) {
        int size = result.size();
        int j = 0;
        string temp;

        while (j < size) {
            int bit = result[j] - '0';
            int num = 1;
            while (j+1 < size && (result[j+1] - '0') == bit) {
                j++;
                num++;
            }

            int sz = temp.size();

            while (num % 10 != 0) {
                temp.insert(sz, 1, (num%10)+'0');
                num = num/10;
            }
            temp.append(1, bit+'0');
            j++;
        }
        result = temp;
    }
    return result;
}

int main() {
  string s = countAndSay(30);

  cout << s << endl;
  return 0;
}
